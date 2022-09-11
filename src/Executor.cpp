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

#include "Executor.h"
#include "FixedThreadPool.h"
#include "ExecutorService.h"



namespace fqfw
{
#define TOSTR(str)          #str

std::atomic<uint32_t> Executor::mFixedThreadPool(0);

std::shared_ptr<ExecutorService> Executor::newFixedThreadPool(uint32_t threadCount)
{
    return std::shared_ptr<ExecutorService>(new FixedThreadPool(
                                            TOSTR(FixedThreadPool) + std::to_string(mFixedThreadPool++),
                                            threadCount));
}

} // namespace fqfw

