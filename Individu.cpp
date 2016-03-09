
#include "Individu.h"
#include <iostream>
using namespace std;

//constructeurs

Individu::Individu (void){
	phen = nullptr;	
	divide = true;
	
	gen = false;	
	vivant = false;

	fitness = 0;
	x = 0;
	y = 0;

}

Individu::Individu (unsigned int nx, unsigned int ny, bool ngen){
	
	phen = new double[3];
	for (int i = 0 ; i < 3 ; i++){
		phen[i] = 0;
	}
	
	divide = true;
	
	gen = ngen;	
	vivant = true;

	fitness = 0;
	x = nx;
	y = ny;
}


Individu::Individu (const Individu& model){
	
	phen = new double[3];
	double* pmod = model.getphen();
	if (pmod == nullptr) {
		cout << "Copie d'individu sans genotype ! Erreur ! " << endl;
	}
	for (int i = 0 ; i < 3 ; i++){
		phen[i] = pmod[i];
	}
	divide = model.candivide();
	
	gen = model.getgen();
	vivant = model.isalive();

	this->actfitness ();
	x = model.getx();
	y = model.gety();

}

//destructeurs

Individu::~Individu (){
	
	delete[] phen;
	
}

//pour construcetur par copie.
void Individu::actfitness (){
	if (gen){
		fitness = phen[2];
	}else{
		fitness = phen[1];
	}
}
