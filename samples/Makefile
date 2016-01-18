CFLAGS  = -std=c++11 -Wall
INCLUDE = -I../include

all: main

main: main.cpp
	g++ $(CFLAGS) -o $@ $< ../bin/libsplitter.a $(INCLUDE)

clean:
	rm main
