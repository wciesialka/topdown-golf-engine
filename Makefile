CC = g++
CFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all: golf_engine.out

run: golf_engine.out
	./golf_engine.out

golf_engine.out: build/main.o build/Vector2.o
	$(CC) $^ -o $@ $(CFLAGS)

build/%.o: src/%.cpp
	$(CC) -c $^ -o $@ 

clean:
	rm -f ./build/*
	rm -f ./golf_engine.out
