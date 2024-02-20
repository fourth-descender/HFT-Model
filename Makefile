.PHONY: all configure build run plot clean

all: configure build run plot

configure:
	cmake -S . -B build

build:
	cmake --build build

run:
	build/bin/MarketMaker

plot:
	python3 plot.py

clean:
	rm -rf build