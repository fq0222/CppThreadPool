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

#include "FqFwThread.h"
#include "BlockQueue.h"
#include "Task.h"

namespace fqfw
{

FqFwThread::FqFwThread(const std::shared_ptr<BlockQueue>& ptr)
: mBlockQueue(ptr)
, mRun(true)
, mThread(&FqFwThread::run, this)
{
}

FqFwThread::~FqFwThread()
{
}


void FqFwThread::stop()
{
    this->mRun = false;
}


void FqFwThread::run()
{
    while (mRun)
    {
        std::shared_ptr<BlockQueue> queue = mBlockQueue.lock();
        if (queue) {
            auto task = queue->pop();
            if (task) {
                task->run();
            }
        }
    }
}


} // namespace fqfw
