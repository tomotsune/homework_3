#include <iostream>
#include "String.h"
#include "Array.h"

void testString();

void testArray();

int main() {
    testString();
    std::cout<<"---------------------"<<std::endl;
    testArray();
    return 0;
}

void testString() {
    String introduction{"Zhang Ji, a Chinese poet about whom little is known"};
    introduction.append(",once wrote a famous poem ")
    + "Mooring by Maple Bridge at Night.";
    std::cout << introduction << " len: " << introduction.length() << std::endl;

    String advice{"Before we come to a decision, we must take into consideration all the relevant facts."};
    std::cout << advice << " len: " << advice.length() << std::endl;

    std::cout << introduction.compare(advice) << std::endl;
}

void testArray() {
    int temp[7]{1234, 1204, 9001, 9900, 2010, 2009, 1299};
    Array array{temp, 7};
    std::cout << array << std::endl;
    array.sort();
    std::cout << array << std::endl;
}