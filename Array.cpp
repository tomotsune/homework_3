//
// Created by tomot on 2020/10/9.
//

#include "Array.h"

Array::Array(const int *val, int len) : _len(len), _val(new int[_len]) {
    /*void *memcpy(void *dst, void *src, size_t size);*/
    memcpy(_val, val, sizeof(int) * _len);
}

Array::~Array() {
    delete[] _val;
}

void Array::sort() {
    std::sort(_val, _val + _len, [](int l, int r) {
        return l % 100 > r % 100;
    });
}

std::ostream &operator<<(std::ostream &os, const Array &array) {
    for (int i = 0; i < array._len; ++i) {
        os << array._val[i] << " ";
    }
    return os;
}
