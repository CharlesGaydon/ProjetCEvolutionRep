#include "Environnement.h"
#include "Individu.h"
#include "Simulation.h"
#include <iostream>


Simulation::Simulation (){
	//A ne pas employer
	MAP = Environnement();
	pop = nullptr;
	
	T = 0;
	Ainit = 0;
	D = 0;
	
	Pmut = 0;
	Pdeath = 0;
		
	Raa = 0;
	Rbb = 0;
	Rab = 0;
	Rbc = 0;
	
	Wmin = 0;
	Tfini = 0;
	
}


//:param nT: nombre de tours avant changement de milieu.
Simulation::Simulation (double nT, double nAinit){
	T = nT;
	Ainit = nAinit;
	D = 0.1;

	//TODO : Lecture des paramètres dans cet ordre :
	//fonction importParam

	Pmut = 0.1;
	Pdeath = 0.001;
		
	Raa = 0.1;
	Rbb = 0.1;
	Rab = 0.1;
	Rbc = 0.1;	
		
	Wmin = 0.001;
	Tfini = 10000;
	
	//Environnement :
	unsigned int W = 32;
	unsigned int H = 32;
	MAP = Environnement(W, H, Ainit);
	
	//Tableau de population, rempli de 50% de chaque génotype.
	pop = new Individu**[W];
	
	bool NewGenotype = true;
	int nbA = 0;
	int nbB = 0;
	int max = (W*H)/2;
	
	for (unsigned int i = 0 ; i<W ; i++){
		pop[i] = new Individu*[H];
		
		for (unsigned int j = 0 ; j<H ; j++){
			NewGenotype = (((double) std::rand()/RAND_MAX)>=0.5);
						
			while(((nbA>max) && (NewGenotype==false)) || ((nbB>max) && NewGenotype)){
				NewGenotype = (((double) std::rand()/RAND_MAX)>=0.5);
			}
			std::cout << nbA << " " << nbB << std::endl;
			if (NewGenotype) {nbA++;} else {nbB++;}
			pop[i][j] = new Individu(i,j, NewGenotype);
		}
	}

	
}

Simulation::Simulation (double nT, double nAinit, double nD){
	T = nT;
	Ainit = nAinit;
	D = nD;
	//TODO : Lecture des paramètres
	
	Pmut = 0.1;
	Pdeath = 0.001;
		
	Raa = 0.1;
	Rbb = 0.1;
	Rab = 0.1;
	Rbc = 0.1;	
		
	Wmin = 0.001;
	Tfini = 10000;
	//Environnement :
	unsigned int W = 32;
	unsigned int H = 32;
	MAP = Environnement(W, H, Ainit, D);
	
	//Tableau de population, rempli de 50% de chaque génotype.
	pop = new Individu**[W];
	
	bool NewGenotype = false;
	int nbA = 0;
	int nbB = 0;
	int max = (W*H)/2;
	
	for (unsigned int i = 0 ; i<W ; i++){
		pop[i] = new Individu*[H];
		
		for (unsigned int j = 0 ; j<H ; j++){
			while((nbA<=max && NewGenotype == true) || (nbB<=max && NewGenotype == false)){
				NewGenotype = ((std::rand()/RAND_MAX)>=0.5);
			}
			pop[i][j] = new Individu(i,j, NewGenotype);
		}
	}
}


Simulation::~Simulation{
	//TODO
	
}

