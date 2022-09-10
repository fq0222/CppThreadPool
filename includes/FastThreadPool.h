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

#ifndef __FQFW_FAST_THREAD_POOL_H_
#define __FQFW_FAST_THREAD_POOL_H_

#include <memory>
#include <string>
#include <list>
#include "Define.h"

namespace fqfw
{

class Task;
class BlockQueue;
class FqFwThread;

class FastThreadPool
{
private:
    std::string                                 mName;
    uint32_t                                    mThreadCount;
    std::shared_ptr<BlockQueue>                 mBlockQueue;
    std::list<std::shared_ptr<FqFwThread>>      mThreadList;
public:
    FastThreadPool(std::string name, uint32_t threadCount);
    FastThreadPool(std::string name, uint32_t threadCount, const std::shared_ptr<BlockQueue>& blockQueue);
    ~FastThreadPool();

    ErrorCode post(const std::shared_ptr<Task>& task);
    bool exit();
private:
    void init();
};


} // namespace fqfw


#endif // __FQFW_FAST_THREAD_POOL_H_
