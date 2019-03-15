#tell make to start with the lab2 target
all: lab2

#create the app.o object
lab2: app.o

# assign and create the app.o linked to app.cpp
app.o: app.cpp
	g++ -c app.cpp

# remove app.o to clean up directory
clean:
	rm app.o 

