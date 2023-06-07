# @file Makefile
# @brief This file is responsible for controlling the GNU Make command for easier building.
#
# @author Willow Ciesialka
# @date 2023-06-01

# Executable name
EXEC = golf_engine

# Class names
CLASSES = main Tests Vector2 Renderables/Renderable Rendering/RenderableVisitor GameManagement/Tile Renderables/Entity GameManagement/Scene Rendering/Window Renderables/Sprite

# Compiler command
CC = g++

# Compiler flags
CFLAGS = -std=c++11

# Linker flags
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Build Object paths
OBJECTS = $(addprefix build/,$(addsuffix .o, $(CLASSES)))

# Build everything - default
all: $(EXEC).out

# Build and run
run: $(EXEC).out
	./$<

# Clean - Delete build files and executables
clean:
	rm -rf ./build/*
	rm -f ./$(EXEC).out

# Executable
$(EXEC).out: $(OBJECTS)
	$(CC) $^ -o $@ $(LFLAGS)

# Build files
build/%.o: src/%.cpp
	# Make the build directory if it doesn't exist
	if ! [ -d $(@D) ]; then mkdir $(@D); fi
	$(CC) -c $^ -o $@ $(CFLAGS) 