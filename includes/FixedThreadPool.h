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

#ifndef __FQFW_FIXED_THREAD_POOL_H_
#define __FQFW_FIXED_THREAD_POOL_H_

#include <memory>
#include <string>
#include <list>
#include "Define.h"
#include "ExecutorService.h"

namespace fqfw
{

class Task;
class BlockQueue;
class FqFwThread;

class FixedThreadPool : public ExecutorService
{
private:
    std::string                                 mName;
    uint32_t                                    mThreadCount;
    std::shared_ptr<BlockQueue>                 mBlockQueue;
    std::list<std::shared_ptr<FqFwThread>>      mThreadList;
public:
    FixedThreadPool(std::string name, uint32_t threadCount);
    FixedThreadPool(std::string name, uint32_t threadCount, const std::shared_ptr<BlockQueue>& blockQueue);
    virtual ~FixedThreadPool();

    virtual ErrorCode post(const std::shared_ptr<Task>& task) override;
    virtual bool shutdown() override;
private:
    void init();
};


} // namespace fqfw


#endif // __FQFW_FIXED_THREAD_POOL_H_
