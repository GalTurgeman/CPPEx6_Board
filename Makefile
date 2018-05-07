CXX=clang++-5.0
CXXFLAGS=-std=c++17 

make: main.o Board.o MyChar.o
	$(CXX) $(CXXFLAGS) main.cpp *.o -o a.out
	valgrind --tool=memcheck ./a.out

main.o: main.cpp Board.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

Board.o: Board.cpp Board.h
	$(CXX) $(CXXFLAGS) -c Board.cpp -o Board.o

MyChar:	MyChar.cpp MyChar.H
	$(CXX) $(CXXFLAGS) -c MyChar.cpp -o MyChar.o

clean:
	rm *.o a.out


all: make main.o
	$(CXX) $(CXXFLAGS) MyChar.o Board.o main.o
	./a.out