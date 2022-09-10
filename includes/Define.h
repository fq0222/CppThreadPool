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

#ifndef __FQFW_DEFINE_H_
#define __FQFW_DEFINE_H_

#include <string>

namespace fqfw
{

enum ThreadStatus : uint32_t
{
    INIT,
    RUNNING,
    WAIT,
    EXIT
};

enum TaskType : uint32_t
{
    NORMAL,
    BLOCK,
    LOOP
};

enum ErrorCode : int32_t {
    OK,
    PARAM_ERROR,
    QUEUE_OUT_OF_LINE,
    FAILED,
};


} // namespace fqfw


#endif // __FQFW_DEFINE_H_
