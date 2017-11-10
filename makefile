default: buildAndRun

build:
	mkdir -p bin
	fg++ *.cpp -o bin/a.out

run:
	./bin/a.out

buildAndRun: build run
