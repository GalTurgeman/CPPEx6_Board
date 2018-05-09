//
// Created by Gal on 07/05/2018.
//
#include "MyChar.h"
#include "MyException.h"

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
/**
 * Getter
 * @param c
 */
char MyChar::getChar() {return this->c;};
/**
 * Setter
 * @param c
 */
void MyChar::setChar(char c) {this->c =c;}
/**
 * override = operator
 * @param c
 */
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
bool MyChar::operator == (const MyChar& mc ) const{
    return c == mc.c;
}
bool MyChar::operator==(char c) const{
    return this->c == c;
}
bool MyChar::operator != (const MyChar& mc ) const{
    return c != mc.c;
}
bool MyChar::operator!=(char c) const{
    return this->c != c;
}
