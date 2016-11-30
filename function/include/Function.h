//
// Created by jiangshipeng on 2016/11/29.
//

#ifndef COURSE_FUNCTION_H
#define COURSE_FUNCTION_H

#include <iostream>
using namespace std;

void func(void){
    std::cout << "1" << std::endl;
}

class FunctionA{
public:
    static int fun(int a);

};

class FunctionB{
public:
    int operator()(int a){
        std::cout << "2" << "(" << a << ")" << std::endl;
        return a;
    }

};

#endif //COURSE_FUNCTION_H
