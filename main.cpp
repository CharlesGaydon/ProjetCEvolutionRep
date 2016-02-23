#include "Individu.h"
#include "Environnement.h"
#include "Simulation.h"

#include <iostream>

int main(){
	//COMPILATION :
		//individu ok
		//Environnement ok
		//SImulation ok
	Simulation S = Simulation(10,10,3, 0.1);
	S.Afficher();
	S.Simulate ();
	std::cout << 0
	<< std::endl;
	
	//
  return 0;  
}
