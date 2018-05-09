//
// Created by Gal on 08/05/2018.
//

#ifndef CPPEX5_MYEXCEPTION_H
#define CPPEX5_MYEXCEPTION_H

#endif //CPPEX5_MYEXCEPTION_H

#include <string>
#include <iostream>
#include <exception>

using namespace std;

class IllegalCoordinateException : public exception {
public:
    int x, y;

    IllegalCoordinateException(int x, int y) { this->x = x, this->y = y; }

    string theCoordinate() const {
        return to_string(x)+ "," +to_string(y);
    }
};
class IllegalCharException : public exception {
public:
    char c;

    IllegalCharException(char c) { this->c = c; }

    char theChar() const {
        return (this->c);
    }
};
