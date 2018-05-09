CXX=clang++-5.0
CXXFLAGS=-std=c++17 

all: Board.o MyChar.o

Board.o: Board.cpp Board.h MyException.h
	$(CXX) $(CXXFLAGS) -c Board.cpp -o Board.o

Node.o: MyChar.cpp MyChar.h MyException.h
	$(CXX) $(CXXFLAGS) -c MyChar.cpp -o MyChar.o

main.o: main.cpp Board.h MyException.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	rm *.o a.out

buildAndRun: all main.o
	$(CXX) $(CXXFLAGS) Board.o MyChar.o main.o
	./a.out
