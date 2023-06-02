# @file Makefile
# @brief This file is responsible for controlling the GNU Make command for easier building.
#
# @author Willow Ciesialka
# @date 2023-06-01

# Executable name
EXEC = golf_engine

# Class names
CLASSES = main Vector2 Entity

# Compiler command
CC = g++

# Compiler flags
CFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Object paths
OBJECTS = $(addprefix build/,$(addsuffix .o, $(CLASSES)))

# Build everything - default
all: $(EXEC).out

# Build and run
run: $(EXEC).out
	./$<

# Clean - Delete build files and executables
clean:
	rm -f ./build/*
	rm -f ./$(EXEC).out

# Executable
$(EXEC).out: $(OBJECTS)
	$(CC) $^ -o $@ $(CFLAGS)

# Build files
build/%.o: src/%.cpp
	$(CC) -c $^ -o $@ 