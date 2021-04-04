CC=g++
CFLAGS=

TARGET=encrypt

default: main.cpp
	$(CC) -o $(TARGET) main.cpp $(CFLAGS)
	
