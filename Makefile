all: t1 t3 l1

t1: test1.out

test1.out: test1.o
	g++ -std=c++11 -Wall test1.o -o test1.out

test1.o: test1.cpp
	g++ -std=c++11 -Wall -c test1.cpp


t3: test3.out

test3.out: test3.cpp
	g++ -std=c++11 -Wall test3.cpp -o test3.out


# make ERROR....
#l1: lambda1

# make ERROR....
#lambda1: lambda1.out

l1: lambda1.out

lambda1.out: lambda1.cpp
	g++ -std=c++11 -Wall lambda1.cpp -o lambda1.out
#	g++ -std=c++11       lambda1.cpp -o lambda1.out    
