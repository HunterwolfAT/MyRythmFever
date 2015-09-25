# Makefile for MyRythmFever
# Written by Maximilian Siess, (c) 2015

#CC=g++
#CFLAGS=-lSDL2 -lSDL2_mixer
#LDFLAGS=`sdl2-config --libs`
#SOURCEFILES=timeline.cpp objectmanager.cpp audioplayer.cpp editor.cpp myRythmFever.cpp
#EXECUTABLE=myRythmFever

#SRC_DIR=source
#BUILD_DIR=build

#SOURCES= $(foreach source,$(SOURCEFILES),$(SRC_DIR)/$(source))
#OBJECTFILES=$(SOURCEFILES:.cpp=.o)
#OBJECTS= $(foreach object,$(OBJECTFILES),$(BUILD_DIR)/$(object))

#all: $(SOURCES) $(EXECUTABLE)

#$(EXECUTABLE): $(OBJECTS)
#	$(CC) $(LDFLAGS) $(CFLAGS) $(OBJECTS) -o $@

#$(OBJECTS):
#	$(CC) $(LDFLAGS) $(CFLAGS) $< -o $@

#$(SOURCES):
#	$(CC) $(LDFLAGS) $(CFLAGS) -c $@ -o $@

#clean:
#	$(RM) $(BUILD_DIR)/*.o *~ $(EXECUTABLE)

CC = g++

#OBJ = CG4.o List.o LoadShader.o objloader.o ShaderHandler.o Model.o
TARGET = myRythmFever

CFLAGS = 
LDLIBS = `sdl2-config --libs` -lSDL2 -lSDL2_mixer -lSDL2_ttf
INCLUDES = -Isource

SRC_DIR = source
BUILD_DIR = build

all: $(TARGET)

$(TARGET).o: $(TARGET).cpp
	$(CC) $(LDLIBS) $(CFLAGS) -c $^ -o $@

#$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
#	$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(LDLIBS) $(CFLAGS) $(INCLUDES) -c $^ -o $@

clean:
	rm -f $(BUILD_DIR)/*.o *.o $(TARGET) 

.PHONY: clean

# Dependencies
$(TARGET): $(BUILD_DIR)/editor.o $(BUILD_DIR)/timeline.o $(BUILD_DIR)/audioplayer.o $(BUILD_DIR)/objectmanager.o $(BUILD_DIR)/interface.o $(BUILD_DIR)/textrenderer.o | $(BUILD_DIR)

