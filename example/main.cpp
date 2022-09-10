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

#include <cstdio>
#include <chrono>
#include <thread>
#include "FastThreadPool.h"
#include "Task.h"

using namespace fqfw;

class TestTask : public Task
{
private:
    /* data */
public:
    TestTask() {}
    virtual ~TestTask() {}

    virtual void run() {
        printf("TestTask run\n");
    }
};


int main(int argc, char *argv[])
{
    printf("hello fqfw\n");
    std::shared_ptr<FastThreadPool> pool = std::shared_ptr<FastThreadPool>(new FastThreadPool("fqfw", 10));


    for (int i = 0; i < 200; ++i) {
        std::shared_ptr<Task> task = std::shared_ptr<Task>(new TestTask());
        pool->post(task);
    }


    std::this_thread::sleep_for(std::chrono::seconds(10));

    pool->exit();

    return 0;
}
