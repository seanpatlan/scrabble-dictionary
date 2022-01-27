all: main.cpp
	g++ main.cpp -std=c++11 -w -o dictionary

clean:
	rm -rf dictionary
