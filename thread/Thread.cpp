//
// Created by jiangshipeng on 2016/11/30.
//
#include <Thread.h>
#include <iostream>
#include <thread>

void Thread::th_function() {
    std::cout << "hello thread." << std::endl;
}

void Thread::th_function1() {
    for (int i = 0; i != 10; ++i) {
        std::cout << "thread 1 print " << i << std::endl;
    }
}

void Thread::th_function2(int n) {
    std::cout << "thread 1 print " << n << std::endl;
}

void Thread::pause_thread(int n) {
    std::this_thread::sleep_for(std::chrono::seconds(n));
    std::cout << "pause of " << n << " seconds ended\n";
}
