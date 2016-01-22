CFLAGS  = -fpic -std=c++11 -Wall -c
INCLUDE = -I../include

all: dir separator.o splitter.o cseparator.o csplitter.o libsplitter.a \
     libsplitter.la libcsplitter.a libcsplitter.la libsplitter.so libcsplitter.so

dir:
	mkdir -p ../bin

separator.o: separator.cpp ../include/separator.h
	g++ $(CFLAGS) -o ../bin/separator.o separator.cpp $(INCLUDE)

splitter.o: splitter.cpp ../include/splitter.h
	g++ $(CFLAGS) -o ../bin/splitter.o splitter.cpp $(INCLUDE)

cseparator.o: cseparator.cpp ../include/cseparator.h
	g++ $(CFLAGS) -o ../bin/cseparator.o cseparator.cpp $(INCLUDE)

csplitter.o: csplitter.cpp ../include/csplitter.h
	g++ $(CFLAGS) -o ../bin/csplitter.o csplitter.cpp $(INCLUDE)

libsplitter.a:
	ar rcs ../bin/libsplitter.a ../bin/separator.o ../bin/splitter.o

libsplitter.la:
	ar rcs ../bin/libsplitter.la ../bin/separator.o ../bin/splitter.o

libcsplitter.a:
	ar rcs ../bin/libcsplitter.a ../bin/separator.o ../bin/splitter.o \
	    ../bin/cseparator.o ../bin/csplitter.o

libcsplitter.la:
	ar rcs ../bin/libcsplitter.la ../bin/separator.o ../bin/splitter.o \
	    ../bin/cseparator.o ../bin/csplitter.o

libsplitter.so:
	g++ -shared ../bin/separator.o ../bin/splitter.o -o ../bin/libsplitter.so

libcsplitter.so:
	g++ -shared ../bin/separator.o ../bin/splitter.o ../bin/cseparator.o \
	    ../bin/csplitter.o -o ../bin/libcsplitter.so
clean:
	rm -r ../bin
