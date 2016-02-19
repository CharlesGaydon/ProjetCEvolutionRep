#include "Individu.h"
#include "Environnement.h"
#include "Simulation.h"

#include <iostream>

int main(){
	//individu ok
	//Environnement
	std::cout << (5<4)<< std::endl;

	int a = 0;
	while(a<10){
		std::cout << (((double) std::rand()/RAND_MAX)>=0.5) << std::endl;	
		a++;	
	}
	Simulation S = Simulation(2000, 0.1);
	std::cout << 0<< std::endl;
	
	//
  return 0;  
}
