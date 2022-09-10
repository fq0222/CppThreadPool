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
#include <memory>
#include "FastThreadPool.h"

using namespace fqfw;

int main(int argc, char *argv[])
{
    printf("hello fqfw\n");
    std::shared_ptr<FastThreadPool> pool = std::shared_ptr<FastThreadPool>(new FastThreadPool());

    return 0;
}
