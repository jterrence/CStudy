//
// Created by jiangshipeng on 2016/12/1.
//

#ifndef CSTUDY_FUNCTIONC_H
#define CSTUDY_FUNCTIONC_H

#include <functional>
#include <iostream>
/**
 * 包装函数
 */
namespace C{
    using cb1_t = std::function<void()>;
    using cb2_t = std::function<void(int)>;
    using fp    = void (*)void;

    class FunctionC{
    public:

        /**
         * 包装无参函数
         * @param f
         */
        template <typename R>
        void call(

                void (*f)();

        ){
            f();
        };

        /**
         * 包装有参函数
         * @param args
         */
        template<typename R, typename ...A>
        void call(std::function<R(A...)> f, A... args)
        {
            f(args...);
        }

        /**
         * 包装无参回调
         * @param f
         */
        template <typename R>
        void call(R f(void)){
            call(std::function<R(void)>(f));
        };

        /**
         * 包装有参函数
         * @param f
         * @param args
         */
        template<typename R, typename ...A>
        void call(R f(A...), A... args) {
            call(std::function<R(A...)>(f), args...);
        }

        void call(fp  f){
            this->call(std::function<void()>(f));
        }

        void foo1() {
            std::cout << "foo1 is called" << std::endl;
        }

        void foo2(int i) {
            std::cout << "foo2 is called with: " << i << std::endl;
        }
    };
}
#endif //CSTUDY_FUNCTIONC_H
