CPPFLAGS = -Wall -g -std=c++11

all: car

car: carlist.o car.o tools.o driver.o
	g++ carlist.o car.o tools.o driver.o -o car

carlist.o: carlist.cpp
	g++ -g -c carlist.cpp

car.o: car.cpp
	g++ -g -c car.cpp

driver.o: driver.cpp
	g++ -g -c driver.cpp

tools.o: tools.cpp
	g++ -g -c tools.cpp

clean:
	rm *.o ./car 
