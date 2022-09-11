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

#ifndef __FQFW_TASK_H_
#define __FQFW_TASK_H_

#include <thread>
#include "Define.h"

namespace fqfw
{

class Task
{
private:
    TaskType type;
public:
    Task() {}
    Task(TaskType _type): type(_type) {}
    virtual ~Task() {}

    void setType(TaskType type) {
        this->type = type;
    }

    TaskType getType() {
        return this->type;
    }

    virtual void run(std::thread::id tid) = 0;
};

} // namespace fqfw


#endif // __FQFW_TASK_H_
