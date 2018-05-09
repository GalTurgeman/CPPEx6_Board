//
// Created by Gal on 07/05/2018.
//



#include <iostream>
#include "MyChar.h"
#include <string>
#include <list>

using namespace std;

class Board {
public:
    int size;
    MyChar **board;

    Board();

    Board(int);

    Board(const Board &b);
    ~Board();
    //______________________//
    friend ostream &operator<<(ostream &output, const Board &b);

    void clean(const Board& b);
    MyChar &operator [] (list<int>);
    Board &operator=(char);
    Board &operator=(const Board &);
    bool operator==(const Board &)const;



};
inline ostream &operator<<(ostream &output, const Board &b) {
    for (int i = 0; i < b.size; ++i) {
        for (int j = 0; j < b.size; ++j) {
            output << b.board[i][j].getChar();
        }
        output << endl;
    }
    return output;
}








