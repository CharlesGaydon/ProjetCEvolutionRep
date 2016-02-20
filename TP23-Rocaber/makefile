all: main

main: main.o Array.o RandomArray.o Complexes.o ImagePPM.o DLA.o Cellular.o Poly.o
	g++ main.o Array.o RandomArray.o Complexes.o ImagePPM.o DLA.o Cellular.o Poly.o -o main -g

main.o: main.cpp Array.h RandomArray.h ImagePPM.h DLA.h Cellular.h Poly.h
	g++ -c main.cpp -o main.o -std=c++11 -g

Array.o: Array.cpp  Array.h
	g++ -c Array.cpp -o Array.o -std=c++11 -g

RandomArray.o : RandomArray.cpp RandomArray.h
	g++ -c RandomArray.cpp -o RandomArray.o -std=c++11 -g

Complexes.o : Complexes.cpp Complexes.h
	g++ -c Complexes.cpp -o Complexes.o -std=c++11 -g

ImagePPM.o : ImagePPM.cpp ImagePPM.h
	g++ -c ImagePPM.cpp -o ImagePPM.o -std=c++11 -g
	
DLA.o : DLA.cpp DLA.h
	g++ -c DLA.cpp -o DLA.o -std=c++11 -g

Cellular.o : Cellular.cpp Cellular.h
	g++ -c Cellular.cpp -o Cellular.o -std=c++11 -g
	
Poly.o : Poly.cpp Poly.h
	g++ -c Poly.cpp -o Poly.o -std=c++11 -g

clean:
	rm *.o

