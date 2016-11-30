//
// Created by jiangshipeng on 2016/11/29.
//

#ifndef COURSE_CONSTRUCT_H
#define COURSE_CONSTRUCT_H

#include <iostream>

using namespace std;

class Construct{
public:
    Construct();

    //复制构造函数
    Construct(const Construct& construct);

    Construct(int n, const string &str);

    ~Construct();


private:
    int age;

    string * name;

};
#endif //COURSE_CONSTRUCT_H
