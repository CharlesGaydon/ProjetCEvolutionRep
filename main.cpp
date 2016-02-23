#include "Individu.h"
#include "Environnement.h"
#include "Simulation.h"

#include <iostream>

int main(){
	//COMPILATION :
		//individu ok
		//Environnement ok
		//SImulation ok
	Simulation S = Simulation(15,15,2000, 0.1);
	S.Afficher ();
	std::cout << 0
	<< std::endl;
	
	//
  return 0;  
}
