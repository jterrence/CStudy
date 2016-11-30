//
// Created by jiangshipeng on 2016/11/30.
//

#ifndef CSTUDY_TEMPLATE_H
#define CSTUDY_TEMPLATE_H

#include <iostream>

template <class T>
class Template{
public:
    T g(T a,T b){
        return a + b;
    }
    Template(){
        std::cout << "template is coming" << std::endl;
    }
};
#endif //CSTUDY_TEMPLATE_H
