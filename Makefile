# @file Makefile
# @brief This file is responsible for controlling the GNU Make command for easier building.
#
# @author Willow Ciesialka
# @date 2023-06-01

# Executable name
EXEC = golf_engine

# Directories
SDIR = ./src
BDIR = ./build

# Compiler command
CC = g++

# Compiler flags
CFLAGS = -std=c++11

# Linker flags
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Source Files
SOURCE_PATHS = $(shell find $(SDIR) -iname "*.cpp")

# Sources/Build Object paths
SOURCES = $(SOURCE_PATHS:$(SDIR)/%=%)
OBJECTS = $(addprefix $(BDIR)/,$(addsuffix .o, $(basename $(SOURCES))))

.PHONY: all run clean

# Build everything - default
all: $(EXEC).out

# Build and run
run: $(EXEC).out
	./$<

# Clean - Delete build files and executables
clean:
	rm -rf $(BDIR)/*
	rm -f  $(EXEC).out

# Executable
$(EXEC).out: $(OBJECTS)
	$(CC) $^ -o $@ $(LFLAGS)

# Build files
$(BDIR)/%.o: $(SDIR)/%.cpp
	@# Make the build directory if it doesn't exist
	@if ! [ -d $(@D) ]; then mkdir $(@D); fi
	$(CC) -c $^ -o $@ $(CFLAGS) 