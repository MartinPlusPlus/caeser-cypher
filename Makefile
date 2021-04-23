CC=g++
CFLAGS=
ODIR=obj


TARGET=build/encrypt

default: main.cpp
	$(CC) -o $(TARGET) main.cpp $(CFLAGS)
	
