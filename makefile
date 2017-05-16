main:	main.o Hugeint.o
	g++ -o main main.o Hugeint.o
main.o: main.cpp Hugeint.h
	g++ -c main.cpp
Hugeint.o: Hugeint.h Hugeint.cpp
	g++ -c Hugeint.cpp
