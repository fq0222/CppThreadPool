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

#ifndef __FQFW_BLOCK_QUEUE_H_
#define __FQFW_BLOCK_QUEUE_H_

#include <memory>
#include <list>
#include <mutex>
#include <atomic>
#include <condition_variable>

#include "Define.h"

namespace fqfw
{
class Task;

class BlockQueue
{
private:
    std::list<std::shared_ptr<Task>>            mQueue;
    std::mutex                                  mQueueMutex;
    std::condition_variable                     mQueueCV;

    uint32_t                                    mMaxTask;
    std::atomic<bool>                           mExit;
public:
    BlockQueue();
    BlockQueue(uint32_t maxTask);
    virtual ~BlockQueue();

    void exit();

    ErrorCode add(const std::shared_ptr<Task>& task);
    std::shared_ptr<Task> pop();
};




} // namespace fqfw


#endif // __FQFW_BLOCK_QUEUE_H_
