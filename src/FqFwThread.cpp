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

#include <iostream>
#include <cstdio>
#include "FqFwThread.h"
#include "BlockQueue.h"
#include "Task.h"

namespace fqfw
{

FqFwThread::FqFwThread(const std::shared_ptr<BlockQueue>& ptr)
: mBlockQueue(ptr)
, mRun(true)
, mThread(&FqFwThread::run, this)
, mTid(0)
, mStatus(ThreadStatus::INIT)
{
}

FqFwThread::~FqFwThread()
{
}


bool FqFwThread::joinable()
{
    return mThread.joinable();
}


void FqFwThread::join()
{
    mThread.join();
}


uint32_t FqFwThread::state()
{
    return mStatus;
}


void FqFwThread::stop()
{
    this->mRun = false;
    std::shared_ptr<BlockQueue> queue = mBlockQueue.lock();
    if (queue) {
        queue->exit();
    }
}


void FqFwThread::run()
{
    while (mRun)
    {
        std::shared_ptr<BlockQueue> queue = mBlockQueue.lock();
        if (queue) {
            mStatus = ThreadStatus::WAIT;
            auto task = queue->pop();
            if (task) {
                mTid = mThread.get_id();
                // printf("Tid: %ld FqFwThread::run()\n", mTid);
                mStatus = ThreadStatus::RUNNING;
                task->run(mTid);
            }
        }
    }
    mStatus = ThreadStatus::EXIT;
}


} // namespace fqfw
