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
String::String() : _len(4), _str(new char[1]) {      //default constructor.
    _str[0] = '\0';        //default string.
    ++num_string;
}

String::String(const char *s)
        : _len(std::strlen(s)), _str(new char[_len + 1]) {     //constructor String from C string.
    std::strcpy(_str, s);        //initialize pointer.
    ++num_string;       //set object count.
}

String::String(const char *s, size_t pos, size_t n)
        : _len(n), _str(new char[_len + 1]) {
    std::strncpy(_str, s + pos, n);        //initialize pointer.
    _str[_len] = '\0';
    ++num_string;       //set object count.
}

String::String(const String &st)
        : _len(st._len), _str(new char[_len + 1]) {
    ++num_string;
    std::strcpy(_str, st._str);       //copy string to new location.

}

String::String(const String &st, size_t pos, size_t n)
        : _len(n), _str(new char[_len + 1]) {
    ++num_string;
    std::strncpy(_str, st._str + pos, n);
    _str[_len] = '\0';
}

String::String(size_t n, char c)
        : _len(n), _str(new char[_len + 1]) {
    strnset(_str, c, n);
    _str[_len] = '\0';
}

String &String::assign(const char *s) {
    return this->operator=(s);
}

String &String::append(const char *s) {
    return this->operator+(s);
}

int String::compare(const String &st) const {
    return *this < st ? -1 : *this > st ? 1 : 0;
}

String &String::insert(size_t pos, const char *s) {
    size_t len = strlen(_str);
    auto str{new char[_len + len + 1]};
    strcpy(str, _str);
    for (size_t i = _len; i >= pos; --i) {
        _str[i + len] = _str[i];
    }
    strncpy(str + pos, s, len);
    delete[] _str;
    _len += len;
    _str = str;
    return *this;
}

String String::substr(size_t pos, size_t n) {
    char *str{};
    strncpy(str, _str + pos, n);
    return String(str);
}

String::~String() {     //necessary destructor.
    --num_string;       //required.
    delete[] _str;      //required.
}

//overloaded operator methods.
String &String::operator+(const String &st) {
    this->operator+=(st);
    return *this;
}

String &String::operator+(const char *s) {
    this->operator+=(s);
    return *this;
}

void String::operator+=(const String &st) {
    strcat(_str, st._str);
}

void String::operator+=(const char *s) {
    _len+=strlen(s);
    strcat(_str, s);
}

String &String::operator=(const String &st) {   //assign a String to a String.
    if (this == &st)return *this;
    delete[] _str;
    _len = st._len;
    _str = new char[_len + 1];
    std::strcpy(_str, st._str);
    return *this;
}

String &String::operator=(const char *s) {  //assign a C string to a String.
    delete[] _str;
    _len = std::strlen(s);
    _str = new char[_len + 1];
    std::strcpy(_str, s);
    return *this;
}

char &String::operator[](int i) {   //read-write char access for non-const String.
    return _str[i];
}

const char &String::operator[](int i) const {   //read-only char access for const String.
    return _str[i];
}

bool operator<(const String &lhs, const String &rhs) {
    return (std::strcmp(lhs._str, rhs._str) < 0);
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
    return (std::strcmp(lhs._str, rhs._str) == 0);
}

bool operator!=(const String &lhs, const String &rhs) {
    return !(rhs == lhs);
}

std::ostream &operator<<(std::ostream &os, const String &string) {
    os << string._str;
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
























