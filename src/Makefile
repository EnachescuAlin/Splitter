CFLAGS  = -std=c++11 -Wall -c
INCLUDE = -I../include

all: dir separator.o splitter.o libsplitter.a libsplitter.la

dir:
	mkdir -p ../bin

separator.o: separator.cpp ../include/separator.h
	g++ $(CFLAGS) -o ../bin/separator.o separator.cpp $(INCLUDE)

splitter.o: splitter.cpp ../include/splitter.h
	g++ $(CFLAGS) -o ../bin/splitter.o splitter.cpp $(INCLUDE)

libsplitter.a:
	ar rcs ../bin/libsplitter.a ../bin/separator.o ../bin/splitter.o

libsplitter.la:
	ar rcs ../bin/libsplitter.la ../bin/separator.o ../bin/splitter.o

clean:
	rm -r ../bin
