CC = g++
CFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
CLASSES = main Vector2
OBJECTS = $(addprefix build/,$(addsuffix .o, $(CLASSES)))

all: golf_engine.out

run: golf_engine.out
	./golf_engine.out

golf_engine.out: $(OBJECTS)
	$(CC) $^ -o $@ $(CFLAGS)

build/%.o: src/%.cpp
	$(CC) -c $^ -o $@ 

clean:
	rm -f ./build/*
	rm -f ./golf_engine.out
