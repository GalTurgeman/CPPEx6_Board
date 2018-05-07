//
// Created by Gal on 07/05/2018.
//



#include <iostream>
#include "MyChar.h"

using namespace std;

class Board{
public:
    int size;
    MyChar ** board;
    Board();
    Board(int);
    Board(const Board &b);

    //______________________//
    friend ostream& operator<<(std::ostream & output, const Board &b);

    MyChar&operator[](std::pair<int,int>);
    Board& operator=(char);
    Board& operator=(const Board&);

};

inline ostream& operator << (std::ostream &output, const Board &b){
    for (int i = 0; i < b.size; ++i) {
        for (int j = 0; j <b.size ; ++j) {
            output << b.board[i][j].getChar();
        }
        output<<endl;
    }
    return output;
}

class IllegalCoordinateException : public exception{
public:
    int x,y;
    IllegalCoordinateException(int x , int y){this->x=x ,this->y=y;}
    string theCoordinate()const{
        return to_string(x)+","+to_string(y);
    }
};

class IllegalCharException : public exception{
public:
    char c;
    IllegalCharException(char c){this->c =c;}

    char theChar() const{
        return (this->c);
    }
};




