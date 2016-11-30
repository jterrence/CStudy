//
// Created by jiangshipeng on 16-11-29.
//

#ifndef CSTUDY_BIND_H
#define CSTUDY_BIND_H
class Bind{
public:
    double my_divide(double x, double y);

    struct MyPair{
        double a,b;

        double multiply(){
            return a * b;
        }
    };
};
#endif //CSTUDY_BIND_H
