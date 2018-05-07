//
// Created by Gal on 07/05/2018.
//


#include "Board.h"

/**
 * Default Constructor init all board to '.'
 */
Board::Board() {
    for (int i = 0; i <this->size ; ++i) {
            board[i] = new MyChar();
    }
}
/**
 * Constructor init by int;
 * @param s
 */
Board::Board(int s) {
    this->size = s;
    board = new MyChar*[size];
    for (int i = 0; i <this->size ; ++i) {
        board[i] = new MyChar();
        for (int j = 1; j <this->size ; ++j) {
            board[i][j].setChar('.');
        }
    }

}
/**
 * Copy Constructor perform deep copy.
 * @param b
 */
Board::Board(const Board &b) {
    this->size = b.size;
    board = new MyChar*[size];
    for (int i = 0; i <this->size ; ++i) {
        board[i] = new MyChar();
        for (int j = 0; j <this->size ; ++j) {
            board[i][j] = b.board[i][j];
        }
    }
}
/**
 * All board will fill with c.
 * @param char c
 * @return &Board
 */
Board &Board::operator=(char c) {
    if( c != 'X' && c != 'O' && c!= '.'){
        IllegalCharException ex(c);
        throw ex;
    }
    else{
        for (int i = 0; i <this->size ; ++i) {
            for (int j = 0; j <this->size ; ++j) {
                this->board[i][j]=c;
            }
        }
        return *this;
    }
}
/**
 * All board will fill with other.c  .
 * @param char c
 * @return &Board
 */
Board &Board::operator=(const Board & b) {

        for (int i = 0; i < this->size; ++i) {
            for (int j = 0; j < this->size; ++j) {
                this->board[i][j] = b.board[i][j];
            }
        }
        return *this;

}
MyChar &Board::operator[] (std::pair<int,int> p) {

    if(p.first >= this->size || p.second >= this->size || p.second < 0 || p.first < 0){
        IllegalCoordinateException ex(p.first,p.second);
        throw ex;
    }
    else return this->board[p.first][p.second];
}

bool Board::operator==(const Board &l){
    if(size != l.size) return false;
    else{
        for (int i = 0; i <size; ++i) {
            for (int j = 0; j <size ; ++j) {
             if(this->board[i][j] != l.board[i][j]) return false;
            }
        }
    }
    return true;
}