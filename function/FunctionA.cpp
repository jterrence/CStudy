//
// Created by jiangshipeng on 2016/11/30.
//
#include <FunctionA.h>

void A::FunctionA::foo1() {
    std::cout << "foo1 is called" << std::endl;
}

void A::FunctionA::foo2(int i) {
    std::cout << "foo2 is called with " << i << std::endl;
}

void A::FunctionA::S::foo3() {
    std::cout << "foo3 is called" << std::endl;
}
