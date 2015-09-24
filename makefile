# Makefile for MyRythmFever
# Written by Maximilian Siess, (c) 2015

CC=g++
CFLAGS=-lSDL_mixer
LDFLAGS=`sdl2-config --libs`
SOURCES=timeline.cpp objectmanager.cpp audioplayer.cpp editor.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=myRythmFever

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(CFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(LDFLAGS) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o *~ $(EXECUTABLE)
