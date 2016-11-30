//
// Created by jiangshipeng on 2016/11/30.
//

#ifndef CSTUDY_FUNCTIONA_H
#define CSTUDY_FUNCTIONA_H
#include <iostream>
#include <functional>

/*
 * 使用回调
 */
namespace A{
    using cb1_t = std::function<void()>;
    using cb2_t = std::function<void(int)>;
    class FunctionA{
    public:
        void foo1();
        void foo2(int i);

        struct S{
            void foo3();
        };
    };
}

#endif //CSTUDY_FUNCTIONA_H
