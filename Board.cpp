//
// Created by Gal on 07/05/2018.
//


#include "Board.h"
#include "MyException.h"
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
    this->board = new MyChar*[size];
    for (int i = 0; i <this->size ; ++i) {
        this->board[i] = new MyChar();
        for (int j = 1; j <this->size ; ++j) {
            this->board[i][j].setChar('.');
        }
    }

}
/**
 * Copy Constructor perform deep copy.
 * @param Board
 */
Board::Board(const Board& b) {
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
    if( c != 'X' && c != 'O' && c!= '.') {
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
 * check if is the same board
 * check if need to create new board , than delete old one.
 * @param Board b
 * @return &Board
 */
Board &Board::operator=(const Board& other) {
        if(this == &other) return *this;//Same Board!
        if(size != other.size) {
            clean(*this);
            size = other.size;
            board = new MyChar*[size];
            for (int i = 0; i <size ; i++) {
                board[i] = new MyChar[size];
            }
            for (int i = 0; i < this->size; ++i) {
                for (int j = 0; j < this->size; j++) {
                    this->board[i][j] = MyChar{other.board[i][j].getChar()};
                }
            }
        }
        return *this;

}
/**
 * Delete Board.
 * @param Board b
 */
void Board::clean(const Board& b){
    for (int i = 0; i <b.size ; i++) {
        delete[] b.board[i];
    }
    delete[]b.board;
}
/**
 * override '[]'
 * @param list l
 * @return &MyChar
 */
MyChar& Board::operator[](list<int> l) {
    if(l.front() >= this->size || l.back() >= this->size || l.back() < 0 || l.front() < 0){
        IllegalCoordinateException ex(l.front(),l.back());
        throw ex;
    }
    return board[l.front()][l.back()];
}
/**
 * Check if all board equal to other board.
 * @param Board
 * @return boolean
 */
bool Board::operator==(const Board &l) const{
    if(size != l.size) return false;
    else{
        for (int i = 0; i <size; ++i) {
            for (int j = 0; j <size ; ++j) {
             if(board[i][j] != l.board[i][j]) return false;
            }
        }
    }
    return true;
}
/**
 * destructor
 * @param
 *
 */
Board::~Board() {
//    cout<<"destructor"<<endl;
    for (int i = 0; i < size; i++) {
        delete[] board[i];
    }
    delete[](board);
}

