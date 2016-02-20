#include "Cellular.h"
#include <iostream>
#include <fstream>
using namespace std;

//constructeurs

Cellular::Cellular (){
	N = 0;
	T = nullptr;
}

Cellular::Cellular (int NN){
	N = NN;
	T = new int*[N];
	for (int k = 0; k<N ; k++){
		T[k] = new int[N];
		for (int j = 0 ; j<N ; j++){
			T[k][j] = 0;
		}
	}
	T[0][(int) N/2] = 1;
}

Cellular::Cellular (const Cellular& model){
	N = model.get_N ();
	int** Tmodel = model.get_T ();
	T = new int*[N];
	
	for (int k = 0; k<N ; k++){
		for (int j = 0 ; j<N ; j++){
			T[k][j] = Tmodel[k][j];
		}
	}
}

//destructeur

Cellular::~Cellular (){
	for (int j = 0 ; j<N ; j++){
		delete[] T[j];
		cout << j << endl;
	}
	cout << "la" <<endl;
	delete[] T;
	cout << "lala" <<endl;
}

//getters

int Cellular::get_N () const{
	return N;
}

int** Cellular::get_T () const {
	return T;
}
//méthodes

void Cellular::calculate () {
	for (int i = 1 ; i< N ; i++){
		for (int j = 0 ; j<N ; j++){
			if (j == 0){
				T[i][j] = this->code(T[i-1][N-1],T[i-1][j],T[i-1][j+1]);
			}else if (j == N-1){
				T[i][j] = this->code(T[i-1][j-1],T[i-1][j],T[i-1][0]);
			}else{
				T[i][j] = this->code(T[i-1][j-1], T[i-1][j], T[i-1][j+1]);
			}
		}
	}
	//saving
	cout << "Enter saving" << endl;
	
	string nameout = "Cellular.ppm";
	ofstream g(nameout, ios::out | ios::trunc | ios::binary);
	g << "P6\n" << N << " " << N << "\n" << 255 << "\n";
	char col = 0;
	for (int i = 0; i<N; i++){
		for (int j = 0; j<N; j++){
			col = T[i][j]*255;
			g.write((char*)&col, sizeof(char));
			g.write((char*)&col, sizeof(char));
			g.write((char*)&col, sizeof(char));
		}
	}
	g.close();
}

int Cellular::code (int kmoins, int k, int kplus){
	if (kmoins == 1){
		if (k == 0 && kplus == 0){
			return 1;
		}else{
			return 0;
		}
	}
	if (k == 0 && kplus == 0){
			return 0;
		}else{
			return 1;
		}
}
