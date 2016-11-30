//
// Created by jiangshipeng on 2016/11/29.
//
/**
 * 移动语义
 */
#include <Move.h>
#include <iostream>

using namespace std;

Move::Move() {

}

Move::~Move() {

}

void Move::f(int &i) {
    std::cout << "lvalue ref:"<< i << std::endl;
}

void Move::f(int && ii) {
    std::cout << "rvalue ref:"<< ii << std::endl;
}




