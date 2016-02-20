
tp2 : Image.o main.o
	g++ -o tp2 Image.o main.o

main.o : main.cpp Image.h
	g++ -c main.cpp -g -pg -W -Wall -std=c++11

Image.o : Image.cpp Image.h
	g++ -c Image.cpp -g -pg -W -Wall -std=c++11

clean :
	rm -rf tp2 *.o *.do
