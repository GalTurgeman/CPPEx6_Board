a: main.o Board.o MyChar.o
	clang++-5.0 -std=c++17 *.o -Wall main.o -o output

main.o: main.cpp Board.cpp MyChar.cpp
	clang++-5.0 -std=c++17 main.cpp Board.cpp MyChar.cpp
