# Makefile for MyRythmFever
# Written by Maximilian Siess, (c) 2015

CC=g++
CFLAGS=-Wall -lSDL2
LDFLAGS=
SOURCES=main.cpp editor.cpp timeline.cpp objectmanager.cpp audioplayer.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=myRythmFever

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
