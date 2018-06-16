all: t1 t3 

t1: test1.out

test1.out: test1.o
	g++ -std=c++11 -Wall test1.o -o test1.out

test1.o: test1.cpp
	g++ -std=c++11 -Wall -c test1.cpp


t3: test3.out

test3.out: test3.cpp
	g++ -std=c++11 -Wall test3.cpp -o test3.out
