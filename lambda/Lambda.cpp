//
// Created by jiangshipeng on 2016/11/29.
//
#include <Lambda.h>
#include <iostream>
#include <vector>
#include <algorithm>

Lambda::Lambda():m_nData(20) {
    std::cout <<"lambda coming"<< std::endl;
}

Lambda::~Lambda() {
    std::cout <<"delete lambda"<< std::endl;
}

void Lambda::prinfList() {
    std::vector<int> vectorTemp;
    vectorTemp.push_back(1);
    vectorTemp.push_back(2);

    // 无函数对象参数，输出：1 2
    {
        std::for_each(vectorTemp.begin(),vectorTemp.end(),[](int v1){
            std::cout << "v1 = " << v1 << std::endl;
        });
    }

    //以值方式传递作用域内所有可见的局部变量（包括this），输出：11 12
    {
        int a = 10;
        std::for_each(vectorTemp.begin(),vectorTemp.end(),[=](int v2){
            std::cout << "v2 = " << v2 + a << std::endl;
        });
    }

    // 以引用方式传递作用域内所有可见的局部变量（包括this），输出：11 13 12
    {
        int a = 10;
        std::for_each(vectorTemp.begin(),vectorTemp.end(),[&](int v3) mutable{
            std::cout << "v3 = " << v3 + a << std::endl;
            a++;
        });
        std::cout << "a3 = " << a << std::endl;
    }

    // 以值方式传递局部变量a，输出：11 13 10
    {
        int a = 10;
        std::for_each(vectorTemp.begin(), vectorTemp.end(), [a](int v4)mutable{
            std::cout << "v4 = " << v4 + a << std::endl;
            a++;
        });
        std::cout << "a4 = " << a << std::endl;
    }

    // 以引用方式传递局部变量a，输出：11 13 12
    {
        int a = 10;
        std::for_each(vectorTemp.begin(), vectorTemp.end(), [&a](int v5){
            std::cout << "v5 = " << v5+a << std::endl; a++;
        });

        std::cout << "a5 = " << a << std::endl;
    }

    // 传递this，输出：21 22
    {
        std::for_each(vectorTemp.begin(),vectorTemp.end(),[this](int v6){
            std::cout << "v6 = " << v6 + m_nData << std::endl;
        });
    }

    // 除b按引用传递外，其他均按值传递，输出：11 12 17
    {
        int a = 10;
        int b = 12;

        std::for_each(vectorTemp.begin(),vectorTemp.end(),[=,&b](int v7){
            std::cout << " v7 = " << v7 + a << std::endl;
            b ++;
        });

        std::cout << " b7 = " << b << std::endl;
    }

    // 操作符重载函数参数按引用传递，输出：2 3
    {

        std::for_each(vectorTemp.begin(), vectorTemp.end(), [](int &v){
            v++;
        });
        std::for_each(vectorTemp.begin(), vectorTemp.end(), [](int v){
            std::cout << v << std::endl;
        });
    }
}

