default: buildAndRun

build:
	mkdir -p bin
	g++ *.cpp -o bin/a.out

run:
	./bin/a.out

buildAndRun: build run
