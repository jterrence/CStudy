//
// Created by jiangshipeng on 2016/12/1.
//
#include <Unique.h>
#include <memory>
#include <iostream>


void Unique::show() {
    std::default_delete<int> d;
    std::unique_ptr<int> u1;
    std::unique_ptr<int> u2(nullptr);
    std::unique_ptr<int> u3(new int);
    std::unique_ptr<int> u4(new int,d);
    std::unique_ptr<int> u5(new int,std::default_delete<int>());
//    std::unique_ptr<int> u8(std::auto_ptr<int>(new int));

    std::cout << "u1: " << (u1 ? "not null" : "null") << std::endl;

    if(u1 != nullptr){
        std::cout <<"*u1: "<< *u1 << std::endl;
    }

    std::cout << "u2: " << (u2 ? "not null" : "null") << std::endl;
    if (u2 != nullptr) {
        std::cout << "*u2: " << *u2 << std::endl;
    }

    std::cout << "u3: " << (u3 ? "not null" : "null") << '\n';
    if (u3 != nullptr)
    {
        std::cout << "*u3: " << *u3 << std::endl;
    }

    std::cout << "u4: " << (u4 ? "not null" : "null") << '\n';
    if (u4 != nullptr)
    {
        std::cout << "*u4: " << *u4 << std::endl;
    }

    std::cout << "u5: " << (u5 ? "not null" : "null") << '\n';
    if (u5 != nullptr)
    {
        std::cout << "*u5: " << *u5 << std::endl;
    }

//    std::cout << "u8: " << (u8 ? "not null" : "null") << '\n';
//    if (u8 != nullptr)
//    {
//        std::cout << "*u8: " << *u8 << std::endl;
//    }
}

void Unique::show1() {
    std::unique_ptr<int> foo;
    std::unique_ptr<int> far;
    foo = std::unique_ptr<int>(new int(101));
    far = std::move(foo);
    std::cout << "foo: ";
    if (foo) std::cout << *foo << '\n'; else std::cout << "empty\n";

    std::cout << "bar: ";
    if (far) std::cout << *far << '\n'; else std::cout << "empty\n";

}
