FLAGS = -std=c++11

all: BST.o Driver.o
	g++ $(FLAGS) -o test Driver.o BST.o
BST.o: BST.cpp
	g++ $(FLAGS) -c BST.cpp
Driver.o: Driver.cpp
	g++ $(FLAGS) -c Driver.cpp
clean:
	rm -rf *.o test