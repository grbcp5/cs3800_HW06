default: buildAndRun

build:
	mkdir -p bin
	g++ *.cpp -o bin/a.out

run:
	mkdir -p out
	./bin/a.out

buildAndRun: build run
