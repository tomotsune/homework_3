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
    int len;        //length of string.

    char *str;      //pointer to string.

    static int num_string;      //number of objects.

    static const int CINLIM = 80;     //cin input limit.
public:
//constructors and other methods.
    String(const char *s);   //constructor.

    String();       //default constructor.

    String(const String &);  //copy constructor.

    ~String();      //destructor.

    int length() const { return len; };

//overloaded operator methods.
    String &operator=(const String &);

    String &operator=(const char *);

    char &operator[](int i);

    const char &operator[](int i) const;

//overloaded operator friends.
    friend bool operator<(const String &lhs, const String &rhs);

    friend bool operator>(const String &lhs, const String &rhs);

    friend bool operator<=(const String &lhs, const String &rhs);

    friend bool operator>=(const String &lhs, const String &rhs);

    friend bool operator==(const String &lhs, const String &rhs);

    friend bool operator!=(const String &lhs, const String &rhs);

    friend std::ostream &operator<<(std::ostream &os, const String &string);

    friend std::istream &operator>>(std::istream &is, String &string);

    static int HowMany();
};


#endif //HOMEWORK_3_STRING_H
