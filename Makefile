CXX = clang++5.0
CXXFLAGS = -std=c++17

make: Board.o MyChar.o
	
Board.o: Board.cpp Board.h
	$(CXX) $(CXXFLAGS) -c Board.cpp -o Board.o
	

MyChar.o: MyChar.cpp MyChar.h
	$(CXX) $(CXXFLAGS) -c MyChar.cpp -o MyChar.o
clean:
	rm *.o a.out
