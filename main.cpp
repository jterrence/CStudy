#include <iostream>
#include <move.h>
#include <MoveA.h>
#include <Lambda.h>
#include <Function.h>
#include <Bind.h>
#include <functional>

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

void testBind(){
    using namespace std::placeholders;

    //bind functions;
//    auto fn_five = std::bind(&Bind::my_divide,10.0,2.0);   // returns 10/2
//    std::cout << fn_five() << '\n';                    // return 5;

}
int main() {

    testBind();

    return  0;
}
