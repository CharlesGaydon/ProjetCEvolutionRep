#include "Environnement.h"
#include "Individu.h"
#include "Simulation.h"



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

Simulation::Simulation (double nT, double nAinit){
	T = nT;
	Ainit = nAinit;
	D = 0.1;
	//TODO : Lecture des paramètres dans cet ordre :
	//fonction importParam
	W = 32;
	H = 32;
	Pmut = 0.1;
	Pdeath = 0.001;
		
	Raa = 0.1;
	Rbb = 0.1;
	Rab = 0.1;
	Rbc = 0.1;
		
		
	Wmin = 0.001;
	Tfini = 10000;

}

Simulation::Simulation (double nT, double nAinit, double nD){
	T = nT;
	Ainit = nAinit;
	D = nD;
	//TODO : Lecture des paramètres
}

