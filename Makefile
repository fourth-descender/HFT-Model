.PHONY: all configure build run plot clean

all: configure build run

configure:
	cmake -S . -B build

build:
	cmake --build build

run:
	build/bin/MarketMaker

clean:
	rm -rf build