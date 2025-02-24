CFLAGS = -g -Wall #-std=c++11
CC = g++

objects = main.o scanner.o parser.o

server: $(objects)
	$(CC) -o main $(objects) 

main.o: main.cpp

scanner.o: scanner.cpp

parser.o: parser.cpp

.PHONY : clean
clean:
	rm -f main $(objects)