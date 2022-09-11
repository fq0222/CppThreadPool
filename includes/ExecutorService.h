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

#ifndef __FQFW_EXECUTOR_SERVICE_H_
#define __FQFW_EXECUTOR_SERVICE_H_

#include <memory>
#include "Define.h"

namespace fqfw
{

class Task;

class ExecutorService
{
public:
    ExecutorService() {}
    virtual ~ExecutorService() {}

    virtual ErrorCode post(const std::shared_ptr<Task>& task) = 0;
    virtual bool shutdown() = 0;
};

} // namespace fqfw


#endif // __FQFW_EXECUTOR_SERVICE_H_
