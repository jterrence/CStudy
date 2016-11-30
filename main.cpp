#include <iostream>
#include <move.h>
#include <MoveA.h>
#include <Lambda.h>
#include <Function.h>
#include <Bind.h>
#include <functional>
#include <FunctionA.h>
#include <FunctionB.h>

using namespace std;

/**
 * C++11新特性之 Move semantics(移动语义)
 */
void testMove(){
    Move* move = new Move;
    int i = 77;
    move->f(i);
    move->f(99);
    move->f(std::move(i));
}

/**
 * 测试移动构造函数
 */
void testMoveA(){

    MoveA a(11),b(12);

    cout << a.getLength() << ' ' << b.getLength() << endl;
    cout << a.getData() << ' ' << b.getData() << endl;
    swap(a,b);
    cout << a.getLength() << ' ' << b.getLength() << endl;
    cout << a.getData() << ' ' << b.getData() << endl;
}

/**
 * 空指针
 */
void testNullPtr(){
    bool   b = false;
    std::cout << b << std::endl;
}

/**
 * lambda表达式
 */
void testLambda(){
    Lambda lambda;
    lambda.prinfList();
}

/**
 * 测试function
 */
void testFunction(){
    std::function<void(void)> fun1 = func;
    fun1();

    std::function<int(int)> fun2 = FunctionA::fun;
    fun2(20);


    FunctionB functionB;

    fun2 = functionB;

    std::cout << fun2(123) << std::endl;
}

/**
 * 测试使用回调
 */
void testFunctionA(){
    A::FunctionA functionA;
    A::cb1_t  cb1_t = std::bind(&A::FunctionA::foo1,functionA);
    cb1_t();

    A::FunctionA functionB;

    A::cb2_t cb2_t  = std::bind(&A::FunctionA::foo2,
                                functionB,std::placeholders::_1);
    cb2_t(222);

    A::FunctionA::S s;

    A::cb1_t  cb3_t = std::bind(&A::FunctionA::S::foo3,s);
    cb3_t();

    A::cb1_t  cb4_t = std::bind([]{
        std::cout << "lambda is coming " << std::endl;
    });

    cb4_t();
}

/**
 * 测试存储回调
 */
void testFunctionB(){
    B::FunctionB functionA;
    B::cb1_t  cb1_t = std::bind(&B::FunctionB::foo1,functionA);
    B::callbacks.push_back(cb1_t);

    B::FunctionB functionB;
    B::cb1_t  cb2_t = std::bind(&B::FunctionB::foo2,functionB,2323);
    B::callbacks.push_back(cb2_t);

    for(auto& fun : B::callbacks){
        fun();
    }

}

/**
 * 测试bind
 */
void testBind(){
    Bind bind;
    //bind 类成员函数;
    auto fn_five = std::bind(&Bind::my_divide,bind,
                             std::placeholders::_1,2);   // returns 10/2
    std::cout << fn_five(10) << std::endl;       // return 5;
}


int main() {
    testFunctionB();
    return  0;
}
