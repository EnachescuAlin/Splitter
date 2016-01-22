CPPFLAGS  = -std=c++11 -Wall
CFLAGS    = -std=c99 -Wall
INCLUDE   = -I../include

all: main cmain

main: main.cpp
	g++ $(CPPFLAGS) -o $@ $< $(INCLUDE) -L../bin -lsplitter
	#g++ $(CPPFLAGS) -o $@ $< ../bin/libsplitter.a $(INCLUDE)

cmain: cmain.c
	gcc $(CFLAGS) -o $@ $< $(INCLUDE) -L../bin -lcsplitter
	#gcc $(CFLAGS) -o $@ $< ../bin/libcsplitter.a $(INCLUDE) -lstdc++

clean:
	rm main cmain
