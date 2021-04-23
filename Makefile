CC=g++
CFLAGS=
ODIR=obj

OUTFILE=*encrypted*

TARGET=build/encrypt

default: main.cpp
	$(CC) -o $(TARGET) main.cpp $(CFLAGS)

cleanup:
	rm build/$(OUTFILE)
