all:	start

start: main.o error.o lexAnalyser.o
	g++ main.o error.o lexAnalyser.o -o start -std=c++11
main.o:	main.cpp
	g++ -c main.cpp
error.o: error.cpp
	g++ -c error.cpp
lexAnalyzer.o: lexAnalyser.cpp
	g++ -c lexAnalyser.cpp

clean:
	rm -rf *.o
