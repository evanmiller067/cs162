all: prime

prime: prime.o tools.o
	g++ prime.o tools.o -o prime

prime.o: prime.cpp
	g++ -c prime.cpp

tools.o: tools.cpp
	g++ -c tools.cpp

clean:
	rm *o prime	
