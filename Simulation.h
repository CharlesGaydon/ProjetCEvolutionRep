
#ifndef SIMULATION_H_
#define SIMULATION_H_
#include <iostream>
#include <list>

class Simulation {
	
	protected:
		
		Environnement MAP;
		Individu*** pop;
		
		//variables
		
		unsigned int T;
		double Ainit;
		double D;
		
		//Paramètres du modèle a pouvoir modifier en cours de route

		double Pmut;
		double Pdeath;
		
		double Raa;
		double Rbb;
		double Rab;
		double Rbc;
		
		
		double Wmin;
		double Tfini;
		
	public:
	
	//constructeurs
	Simulation ();
	Simulation (double nT, double nAinit);
	Simulation (double nT, double nAinit, double nD);
	
	//variables paramètres
			
};

#endif //SIMULATION_H_
