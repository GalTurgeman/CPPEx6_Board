//
// Created by Gal on 07/05/2018.
//
#include "Board.h"
#include "MyChar.h"
/**
 * "Empty" constructor .
 * @param c
 */
MyChar::MyChar() {
    this->c = '.';
}
/**
 * Constructor with MyChar as input.
 * @param c
 */
MyChar::MyChar(const MyChar &other) {
    this->c = other.c;
}
/**
 * Constructor with char as input.
 * @param c
 */
MyChar::MyChar(char c ) {
    this->c = c;
}

char MyChar::getChar() {return this->c;};
void MyChar::setChar(char c) {this->c =c;}

MyChar &MyChar::operator=(char c) {
    if( c != 'X' && c != 'O' && c!= '.'){
        IllegalCharException ex(c);
        throw ex;
    }
    else {
        this->c = c;
        return *this;
    }
}
MyChar &MyChar::operator=(const MyChar& mc) {
    this->c = mc.c;
    return *this;
}
MyChar::operator char() {
    return this->c;
}
bool MyChar::operator == (const MyChar l ){
    if(this->c == l.c) {
        return true;
    }
    return false;

}