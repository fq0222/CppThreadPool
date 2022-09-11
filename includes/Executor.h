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

#ifndef __FQFW_EXECUTOR_H_
#define __FQFW_EXECUTOR_H_

#include <memory>
#include <string>
#include <atomic>

namespace fqfw
{

class ExecutorService;

class Executor
{
private:
    static std::atomic<uint32_t>             mFixedThreadPool;
private:
    Executor();
    virtual ~Executor();
public:
    static std::shared_ptr<ExecutorService> newFixedThreadPool(uint32_t threadCount);
};


} // namespace fqfw

#endif // __FQFW_EXECUTOR_H_

