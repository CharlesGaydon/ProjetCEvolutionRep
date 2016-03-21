
#include "Individu.h"
#include <iostream>
using namespace std;

//constructeurs

//passé en private
Individu::Individu (void){
	//~phen = nullptr;	
	//~divide = true;
	//~
	//~gen = false;	
	//~vivant = false;
//~
	//~fitness = 0;
	//~x = 0;
	//~y = 0;

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
	divide = model.candivide ();
	
	gen = model.getgen ();
	vivant = model.isalive ();

	fitness = model.getfitness ();
	x = model.getx ();
	y = model.gety ();

}

//destructeurs

Individu::~Individu (){
	
	delete[] phen;
	
}

//mutateurs

void Individu::Dby2 (){
	phen[0] = phen[0]/2;
	phen[1] = phen[1]/2;
	phen[2] = phen[2]/2;
	divide = false;
}

//actualisation

void Individu::actfitness (){
	fitness = phen[gen];
}
