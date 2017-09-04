//
// Created by ZhuoYuan Chen on 7/21/17.
//

#ifndef HELLO_WORLD_OS_TEST_H
#define HELLO_WORLD_OS_TEST_H

#include<thread>
#include<mutex>
#include<iostream>

static int g_i = 0;
std::mutex g_i_mutex;

void safe_inc() {
    std::lock_guard<std::mutex> lock(g_i_mutex);
    ++g_i;

    std::cout << std::this_thread::get_id() << ": " << g_i << std::endl;
}

void lock_test() {
    std::cout << __func__ << ": " << g_i << std::endl;

    std::thread t1(safe_inc);
    std::thread t2(safe_inc);

    t1.join();
    t2.join();

    std::cout << __func__ << ": " << g_i << std::endl;
}

#endif //HELLO_WORLD_OS_TEST_H
