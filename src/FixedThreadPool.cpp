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

#include <cstdio>
#include "FixedThreadPool.h"
#include "BlockQueue.h"
#include "FqFwThread.h"

namespace fqfw
{

FixedThreadPool::FixedThreadPool(std::string name, uint32_t threadCount)
: mName(name)
, mThreadCount(threadCount)
, mBlockQueue(new BlockQueue())
{
    init();
}


FixedThreadPool::FixedThreadPool(std::string name, uint32_t threadCount, const std::shared_ptr<BlockQueue>& blockQueue)
: mName(name)
, mThreadCount(threadCount)
, mBlockQueue(blockQueue)
{
    init();
}


FixedThreadPool::~FixedThreadPool()
{
    mThreadList.clear();
}


ErrorCode FixedThreadPool::post(const std::shared_ptr<Task>& task)
{
    return mBlockQueue->add(task);
}


bool FixedThreadPool::shutdown()
{
    for (auto it = mThreadList.begin(); it != mThreadList.end(); ++it) {
        (*it)->stop();
        while (true) {
            if ((*it)->state() == ThreadStatus::EXIT) {
                break;
            }
        }
        if ((*it)->joinable()) {
            (*it)->join();
        }
    }
    printf("FixedThreadPool::shutdown()\n");
}


void FixedThreadPool::init()
{
    for (int i = 0; i < mThreadCount; ++i) {
        std::shared_ptr<FqFwThread> thread = std::shared_ptr<FqFwThread>(new FqFwThread(mBlockQueue));
        while (true) {
            if (thread->state() == ThreadStatus::WAIT) {
                break;
            }
        }

        mThreadList.push_back(thread);
    }
    printf("FixedThreadPool::init()\n");
}


} // namespace fqfw
