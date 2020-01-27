.PHONY: clean

clock: clock.o main.o util.o
	g++ clock.o main.o util.o -o clock

clock.o: clock.cpp
	g++ -c clock.cpp -o clock.o

util.o: util.cpp
	g++ -c util.cpp -o util.o

main.o: main.cpp
	g++ -c main.cpp -o main.o

clean:
	rm -rf *.o clock core.clock.*

