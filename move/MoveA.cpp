//
// Created by jiangshipeng on 2016/11/29.
//

#include <iostream>
#include "MoveA.h"
using namespace std;

MoveA::MoveA(size_t length):lenght(length),mData(new int[length]){
    std::cout << "A(size_t). length = "
              << length << "." << std::endl;
}

//拷贝构造函数
MoveA::MoveA(const MoveA &other):lenght(other.lenght),
                                 mData(new int[other.lenght]) {
    std:cout<<"const move coming" << std::endl;

    std::copy(other.mData,other.mData + lenght,mData);

}

//移动构造函数
MoveA::MoveA(MoveA &&other):mData(NULL),lenght(0){
    std::cout << "A(A&&). length = "
              << other.lenght << ". Moving resource.\n";
    mData   = other.mData;
    lenght  = other.lenght;

    // Release the data pointer from the source object so that
    // the destructor does not free the memory multiple times.
    other.mData  = NULL;
    other.lenght = 0;
}

MoveA::~MoveA() {

}

size_t MoveA::getLength() const {
    return lenght;
}

int* MoveA::getData() {
    return mData;
}

MoveA& MoveA::operator=(const MoveA &other) {
    std::cout << "operator=(const A&). length = "
              << other.lenght<< ". Copying resource." << std::endl;
    if(this != &other){
        delete[] mData;
        lenght = other.lenght;
        mData = new int[lenght];
        std::copy(other.mData, other.mData + lenght, mData);
    }
    return *this;
}

MoveA& MoveA::operator=(MoveA &&other) noexcept{
    std::cout << "operator=(A&&). length = "
              << other.lenght << "." << std::endl;
    if (this != &other) {
        // Free the existing resource.
        delete[] mData;
        // Copy the data pointer and its length from the
        // source object.
        mData  = other.mData;
        lenght = other.lenght;

        // Release the data pointer from the source object so that
        // the destructor does not free the memory multiple times.
        other.mData  = NULL;
        other.lenght = 0;
    }
    return *this;
}

void MoveA::swap(MoveA &other) {
    MoveA temp = move(other);
    other      = move(*this);
    *this      = move(temp);
}

