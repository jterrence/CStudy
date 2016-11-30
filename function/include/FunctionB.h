//
// Created by jiangshipeng on 2016/11/30.
//

#ifndef CSTUDY_FUNCTIONB_H
#define CSTUDY_FUNCTIONB_H

#include <functional>
#include <vector>

/**
 * 使用Function作为存储回调
 */
namespace B{
    using cb1_t         = std::function<void()>;
    using callbacks_t   = std::vector<cb1_t>;

    callbacks_t  callbacks;

    class FunctionB{
    public:
        void foo1();
        void foo2(int i);
    };
}
#endif //CSTUDY_FUNCTIONB_H
