CC = g++
CFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all: golf_engine.out

run: golf_engine.out
	./golf_engine.out

golf_engine.out: build/main.o
	$(CC) $^ -o $@ $(CFLAGS)

build/main.o: src/main.cpp
	$(CC) -c $^ -o $@ 

clean:
	rm -f ./build/*
	rm -f ./golf_engine.out
