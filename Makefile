CXX=clang++-5.0
CXXFLAGS=-std=c++17 

make: main.o Board.o MyChar.o
	$(CXX) $(CXXFLAGS) main.cpp *.o -o a.out
	valgrind --tool=memcheck ./a.out

Board.o: Board.cpp MyChar.cpp Board.h MyChar.H
	$(CXX) $(CXXFLAGS) -c Board.cpp -o Board.o
	$(CXX) $(CXXFLAGS) -c MyChar.cpp -o MyChar.o

clean:
	rm *.o a.out
