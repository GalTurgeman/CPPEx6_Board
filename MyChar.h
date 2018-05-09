//
// Created by Gal on 07/05/2018.
//


#pragma once
#include <iostream>

using namespace std;

class MyChar {
    char c;
public:
    MyChar();
    MyChar(const MyChar&);
    MyChar(char);

    char getChar();
    void setChar(char);

    MyChar&operator =(char);
    MyChar&operator=(const MyChar&);
    bool operator == (const MyChar l );
    bool operator == (char);
    operator char();
    friend ostream& operator<<(std::ostream & output, const MyChar mc);
};
inline ostream& operator<<(std::ostream & output, const MyChar mc) {
    output << mc.c << endl;

    return output;
}



