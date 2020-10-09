//
// Created by tomot on 2020/10/9.
//

#ifndef HOMEWORK_3_ARRAY_H
#define HOMEWORK_3_ARRAY_H


#include <ostream>
#include <cstring>
#include <algorithm>

class Array {
private:
    int _len;

    int *_val;
public:
    Array(const int *val, int len);

    void sort();

    virtual ~Array();

    friend std::ostream &operator<<(std::ostream &os, const Array &array);
};


#endif //HOMEWORK_3_ARRAY_H
