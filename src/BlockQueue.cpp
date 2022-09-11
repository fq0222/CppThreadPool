/*
 *    ___          ___
 *  /'___\       /'___\
 * /\ \__/   __ /\ \__/  __  __  __
 * \ \ ,__\/'__`\ \ ,__\/\ \/\ \/\ \
 *  \ \ \_/\ \L\ \ \ \_/\ \ \_/ \_/ \
 *   \ \_\\ \___, \ \_\  \ \___x___/'
 *    \/_/ \/___/\ \/_/   \/__//__/
 *              \ \_\
 *               \/_/
 */

#include "BlockQueue.h"
#include "Define.h"
#include "Task.h"

#include <cstdio>

namespace fqfw
{

BlockQueue::BlockQueue()
: mMaxTask(0XFFFFFFFF)
, mExit(false)
{

}


BlockQueue::BlockQueue(uint32_t maxTask)
: mMaxTask(maxTask)
, mExit(false)
{

}


BlockQueue::~BlockQueue()
{
    mQueue.clear();
}


void BlockQueue::exit()
{
    std::lock_guard<std::mutex> lock(mQueueMutex);
    this->mExit = true;
    mQueueCV.notify_all();
}


ErrorCode BlockQueue::add(const std::shared_ptr<Task>& task)
{
    std::lock_guard<std::mutex> lock(mQueueMutex);
    if (mQueue.size() > mMaxTask) {
        return ErrorCode::QUEUE_OUT_OF_LINE;
    }

    mQueue.push_back(task);
    mQueueCV.notify_all();
    // mQueueCV.notify_one();

    return ErrorCode::OK;
}


std::shared_ptr<Task> BlockQueue::pop()
{
    std::unique_lock<std::mutex> lock(mQueueMutex);
    while (mQueue.empty() && !mExit)
    {
        printf("BlockQueue::pop wait\n");
        mQueueCV.wait(lock);
    }

    if (mQueue.empty()) {
        std::shared_ptr<Task> t = std::shared_ptr<Task>(nullptr);
        return t;
    }

    std::shared_ptr<Task> t = mQueue.front();
    mQueue.pop_front();

    return t;
}



} // namespace fqfw
