# Makefile for MyRythmFever
# Written by Maximilian Siess, (c) 2015

CC=g++
CFLAGS=-lSDL2 -lSDL_mixer
#LDFLAGS=
SOURCES=timeline.cpp objectmanager.cpp audioplayer.cpp editor.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=myRythmFever

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o *~ $(EXECUTABLE)
