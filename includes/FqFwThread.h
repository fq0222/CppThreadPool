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

#ifndef __FQFW_FQFW_THREAD_H_
#define __FQFW_FQFW_THREAD_H_

#include <thread>
#include <memory>
#include <atomic>

namespace fqfw
{

class BlockQueue;

class FqFwThread
{
private:
    std::weak_ptr<BlockQueue>       mBlockQueue;
    std::atomic<bool>               mRun;
    std::thread                     mThread;
public:
    explicit FqFwThread(const std::shared_ptr<BlockQueue>& ptr);
    ~FqFwThread();

    void stop();
private:
    void run();
};



} // namespace fqfw


#endif // __FQFW_FQFW_THREAD_H_
