
tp3 : Image.o DLA.o CellularAutomaton.o main.o
	g++ -o tp3 Image.o DLA.o CellularAutomaton.o main.o

main.o : main.cpp DLA.h CellularAutomaton.h Image.h
	g++ -c main.cpp -g -pg -W -Wall -std=c++11

DLA.o : DLA.cpp DLA.h Image.h
	g++ -c DLA.cpp -g -pg -W -Wall -std=c++11

CellularAutomaton.o : CellularAutomaton.cpp CellularAutomaton.h Image.h
	g++ -c CellularAutomaton.cpp -g -pg -W -Wall -std=c++11

Image.o : Image.cpp Image.h
	g++ -c Image.cpp -g -pg -W -Wall -std=c++11

clean :
	rm -rf tp3 *.o *.do
