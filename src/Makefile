PROGRAM = beTheBachelor
CC      = g++
CFLAGS  = -g -Wall -std=c++11 
LDFLAGS = -L/usr/X11R6/lib -L/usr/pkg/lib
LDLIBS  = -lglut -lGLU -lGL


$(PROGRAM): main.o draw.o light.o camera.o callbackfuncs.o 
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

camera.o: camera.cpp camera.hpp
	$(CC) $(CFLAGS) -c  $< $(LDLIBS)


main.o: main.cpp callbackfuncs.hpp
	$(CC) $(CFLAGS) -c  $< $(LDLIBS)

draw.o: draw.cpp draw.hpp callbackfuncs.hpp 
	$(CC) $(CFLAGS) -c  $< $(LDLIBS)

light.o: light.cpp light.hpp
	$(CC) $(CFLAGS) -c  $< $(LDLIBS)

callbackfuncs.o: callbackfuncs.cpp callbackfuncs.hpp draw.hpp light.hpp
	$(CC) $(CFLAGS) -c  $< $(LDLIBS)

.PHONY: clean


clean:
	rm -f *.o $(PROGRAM)
