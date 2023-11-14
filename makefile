all: main

main: main.cpp src/*
	g++ src/*.cpp main.cpp -lncurses -o main