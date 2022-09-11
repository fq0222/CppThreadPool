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

#include <iostream>
#include <cstdio>
#include <chrono>
#include <thread>
#include "FastThreadPool.h"
#include "Task.h"

using namespace fqfw;

class TestTask : public Task
{
public:
    TestTask() {}
    virtual ~TestTask() {}

    virtual void run(std::thread::id tid) {
        printf("Tid: %ld TestTask run\n", tid);
    }
};


int main(int argc, char *argv[])
{
    printf("Hello FQFW Thread Pool\n");
    std::shared_ptr<FastThreadPool> pool = std::shared_ptr<FastThreadPool>(new FastThreadPool("fqfw", 20));


    for (int i = 0; i < 50; ++i) {
        std::shared_ptr<Task> task = std::shared_ptr<Task>(new TestTask());
        pool->post(task);
    }


    std::this_thread::sleep_for(std::chrono::seconds(10));

    pool->shutdown();

    return 0;
}
