start: test
	./test

test: main.cpp
	g++ -o test main.cpp egg.cpp -lncurses -std=c++11

clean:
	rm test