//
// Created by haipinHu on 2020/10/9.
// fixed and augmented string class definition.
//

#ifndef HOMEWORK_3_STRING_H
#define HOMEWORK_3_STRING_H

#include <iostream>
#include <cstring>

class String {
private:
    size_t _len;        //length of string.

    char *_str;      //pointer to string.

    static int num_string;      //number of objects.

    static const int CINLIM = 80;     //cin input limit.
public:
//constructors and other methods.


    String();       //default constructor.

    explicit String(const char *s);   //constructor.

    String(const char *s, size_t pos, size_t n);

    String(const String &st);  //copy constructor.

    String(const String &st, size_t pos, size_t n);

    String(size_t n, char c);

    String &assign(const char *s);

    String &append(const char *s);

    int compare(const String &st) const;

    String &insert(size_t pos, const char *s);

    String substr(size_t pos, size_t n);

    ~String();      //destructor.

    [[nodiscard]] int length() const { return _len; };

//overloaded operator methods.
    String &operator+(const String &st);

    String &operator+(const char *s);

    void operator+=(const String &st);

    void operator+=(const char *s);

    String &operator=(const String &st);

    String &operator=(const char *s);

    char &operator[](int i);

    const char &operator[](int i) const;

//overloaded operator friends.
    friend bool operator<(const String &lhs, const String &rhs);

    friend bool operator>(const String &lhs, const String &rhs);

    friend bool operator<=(const String &lhs, const String &rhs);

    friend bool operator>=(const String &lhs, const String &rhs);

    friend bool operator==(const String &lhs, const String &rhs);

    friend bool operator!=(const String &lhs, const String &rhs);

    friend std::ostream &operator<<(std::ostream &os, const String &st);

    friend std::istream &operator>>(std::istream &is, String &st);

    static int HowMany();
};


#endif //HOMEWORK_3_STRING_H
