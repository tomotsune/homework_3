//
// Created by tomot on 2020/10/9.
//


#include "String.h"

//initializing static class menber.

int String::num_string = 0;

//static method
int String::HowMany() {
    return num_string;
}

//class methods.
String::String(const char *s) {     //constructor String from C string.
    len = std::strlen(s);     //set size.
    str = new char[len + 1];        //allot storage.
    std::strcpy(str, s);        //initialize pointer.
    ++num_string;       //set object count.
}

String::String() : len(4), str(new char[1]) {      //default constructor.
    str[0] = '\0';        //default string.
    ++num_string;
}

String::String(const String &st) : len(st.len), str(new char[len + 1]) {
    ++num_string;
    std::strcpy(str, st.str);       //copy string to new location.

}

String::~String() {     //necessary destructor.
    --num_string;       //required.
    delete[] str;      //required.
}

//overloaded operator methods.
String &String::operator=(const String &st) {   //assign a String to a String.
    if (this == &st)return *this;
    delete[] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

String &String::operator=(const char *s) {  //assign a C string to a String.
    delete[] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

char &String::operator[](int i) {   //read-write char access for non-const String.
    return str[i];
}

const char &String::operator[](int i) const {   //read-only char access for const String.
    return str[i];
}

bool operator<(const String &lhs, const String &rhs) {
    return (std::strcmp(lhs.str, rhs.str) < 0);
}

bool operator>(const String &lhs, const String &rhs) {
    return rhs < lhs;
}

bool operator<=(const String &lhs, const String &rhs) {
    return !(rhs < lhs);
}

bool operator>=(const String &lhs, const String &rhs) {
    return !(lhs < rhs);
}

bool operator==(const String &lhs, const String &rhs) {
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

bool operator!=(const String &lhs, const String &rhs) {
    return !(rhs == lhs);
}

std::ostream &operator<<(std::ostream &os, const String &string) {
    os << "str: " << string.str;
    return os;
}

/*
 * 重载>>运算符提供了一种将键盘上输入行读到String对象中的简单方法.
 * 它假定输入的字符不超过CINCLIM, 并丢弃多余的字符.
 * 在if条件下, 如果由于某种原因(如果到达文件尾或get(char*, int)读取的是一个空行)
 * 导致输入失败, istream对象的值将设置位false.
 * cin用法具体参见-->https://blog.csdn.net/bravedence/article/details/77282039
 */
std::istream &operator>>(std::istream &is, String &st) {
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}












