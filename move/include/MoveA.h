//
// Created by jiangshipeng on 2016/11/29.
//

#ifndef COURSE_MOVEA_H
#define COURSE_MOVEA_H


#include <algorithm>

class MoveA {
public:
    explicit MoveA(size_t length);
    MoveA(const MoveA& other);
    //移动构造函数
    MoveA(MoveA&& other);

    ~MoveA();

    MoveA& operator = (const MoveA& other);

    MoveA&operator  = (MoveA&& other) noexcept ;

    size_t getLength() const;

    int* getData();

    void swap(MoveA& other);
private:
    size_t lenght;

    int* mData;

};


#endif //COURSE_MOVEA_H
