#include "Environnement.h"
#include "Individu.h"
#include "Simulation.h"
#include <iostream>

//Constructeurs

Simulation::Simulation (){
	//Déclaré privé pour empêcher son usage.
	
	//~ MAP = new Environnement();
	//~ pop = nullptr;
	//~ T = 0;
	//~ Ainit = 0;
	//~ D = 0;
	//~ poursuivre = 0;
	//~ Pmut = 0;
	//~ Pdeath = 0;
		
	//~ Raa = 0;
	//~ Rbb = 0;
	//~ Rab = 0;
	//~ Rbc = 0;
	
	//~ Wmin = 0;
	//~ Tfini = 0;
	
}

//:param nT: nombre de tours avant changement de milieu : 
//durée de la simulation
Simulation::Simulation (unsigned int nW, unsigned int nH, 
						double nT, double nAinit){
							
	T = nT; 
	Ainit = nAinit;
	D = 0.1;
	W = nW;
	H = nH;
	
	this->MAJparametres ();
	
	//Environnement :
	MAP = new Environnement(W, H, Ainit);
	
	//Tableau de population, rempli de B, puis de 50% de A.
	pop = new Individu**[W];
	
	int nbA = 0;
	int max = (W*H)/2;
	
	for (unsigned int i = 0 ; i<W ; i++){
		pop[i] = new Individu*[H];
		for (unsigned int j = 0 ; j<H ; j++){
			pop[i][j] = new Individu(i,j, true);
		}
	}
	unsigned int i = 0;
	unsigned int j = 0;
	while (nbA <= max){
			i = ((double) std::rand()/(double) RAND_MAX)*((double) (W));
			j = ((double) std::rand()/(double) RAND_MAX)*((double) (H));
			std::cout << i << " " << j << std::endl;//ok
			if ((pop[i][j])->getgen ()){
				pop[i][j]->setgen(false);
				nbA++;
			}
	}
	
}


Simulation::Simulation (unsigned int nW, unsigned int nH, 
						double nT, double nAinit, double nD){
	T = nT;
	Ainit = nAinit;
	D = nD;
	W = nW;
	H = nH;
	
	this->MAJparametres ();
	
	//Environnement :
	MAP = new Environnement(W, H, Ainit, D);
	
	//Tableau de population, rempli de B, puis de 50% de A.
	pop = new Individu**[W];
	
	int nbA = 0;
	int max = (W*H)/2;
	
	for (unsigned int i = 0 ; i<W ; i++){
		pop[i] = new Individu*[H];
		for (unsigned int j = 0 ; j<H ; j++){
			pop[i][j] = new Individu(i,j, true);
		}
	}
	unsigned int i = 0;
	unsigned int j = 0;
	while (nbA <= max){
			i = ((double) std::rand()/(double) RAND_MAX)*((double) (W));
			j = ((double) std::rand()/(double) RAND_MAX)*((double) (H));
			std::cout << i << " " << j << std::endl;//ok
			if ((pop[i][j])->getgen ()){
				pop[i][j]->setgen(false);
				nbA++;
			}
	}
	
}

//Destructeurs

Simulation::~Simulation () {
	for (unsigned int i = 0 ; i<W ; i++){
		for (unsigned int j = 0 ; j<H ; j++){
			delete pop[i][j];
		}
		delete[] pop[i];
	}
	delete[] pop;
	delete MAP;
}


//Méthodes de simulation


int Simulation::Simulate (){
	int temps = 0;
	this->Metabolisme ();
	//TODO : lecture du fichier texte pour paramètres
	while (poursuivre){

			//Les métabolites externes diffusent dans l'environnement
		MAP->Diffusion ();
			//Certains individus meurent, leurs métabolites sont rejetés
			//et ils passent de vivant à mort
		this->Hecatombe ();
			//Compétition pour la reproduction. parcours aléatoire des 
			//Cases où les individus sont mort (cad vides). et compétition 
			//entre les individus extérieurs. L'individu choisi voit ses C
			//en métabolite divisées par deux (donc sa fitness aussi) et
			//A l'espace vide est attribué par opérateur par copie (après 
			//DESTRUCTION du précédent) cet individu.
			//Après division, un individu ne peut se reproduire dans le même tour.
		this->GuerreSexuelle ();
			//Mutation aléatoire des organisme independemment les uns des autres.
		this->Mutation ();			
			//Métabolisme des individus. La FITNESS est actualisée pour tous.
		this->Metabolisme (); //actualiser la fitness egalement
			//Affichage de la boîte de pétri

		
		temps++;	
		this->JeContinue (temps);
		if (temps%T == 0){
			this->Afficher ();
			//LECTURE DES PARAMèTRES.
			MAP->clean ();
		}
			
	}
}

void Simulation::Hecatombe (){
	
	bool newState = true;
	Individu* p = nullptr;
	
	for (unsigned int i = 0 ; i<W ; i++){
		for (unsigned int j = 0 ; j<H ; j++){
			p = pop[i][j];
			if (p->isalive()){
				newState = (((double) std::rand()/RAND_MAX)>=Pdeath);
				std::cout << "individu changed to : "<< newState << std::endl;
				p->setDeadOrAlive(newState);
			}
		}
	}
	
}

void Simulation::GuerreSexuelle (){
	//TODO
}

void Simulation::Metabolisme (){
	Individu* p = nullptr;
	double dt = 0.1;
	
	double Aout = 0;
	double A = 0;
	double Bout = 0;
	double B = 0;
	double C = 0;
	
	for (unsigned int i = 0 ; i<W ; i++){
		for (unsigned int j = 0 ; j<H ; j++){
			
			p = pop[i][j];
			
			if (p->isalive ()){
				
				if (p->getgen ()){
					
					//Métabolisme B
					for (int t = 0; t<10 ; t++){
						Bout = MAP->getB(i,j);
						B = (p->getphen())[1];
						C = (p->getphen())[2];
						//Bout
						MAP->setB(i,j,Bout - dt*Bout*Rbb);
						//B
						p->setB(B + dt*(Bout*Rbb - B*Rbc));
						//C
						p->setC(C + dt*B*Rbc);	
					}
					
				}else{
					
					//Métabolisme A
					for (int t = 0; t<10 ; t++){					
						Aout = MAP->getA(i,j);
						A = (p->getphen())[0];
						B = (p->getphen())[1];
						
						//Aout
						MAP->setA(i, j, Aout - dt*Aout*Raa);
						//A
						p->setA(A + dt*(Aout*Raa - A*Rab));
						//B
						p->setB(B + dt*A*Rab);
					}
					
				} //end else
				
			} //end isalive
			
		} //end for
	} //end for
}

void Simulation::Mutation (){
	
	bool mutate = true;
	Individu* p = nullptr;
	
	for (unsigned int i = 0 ; i<W ; i++){
		for (unsigned int j = 0 ; j<H ; j++){
			
			p = pop[i][j];
			if (p->isalive()){
				mutate = (((double) std::rand()/RAND_MAX)<=Pmut);
				std::cout << "mutate : " << mutate << std::endl;
				if (mutate){
					if (p->getgen()){
						p->setgen(false);
					}else{
						p->setgen(true);
					}
				}
			}
			
		}
	}
	
}

void Simulation::MAJfitness (){
	Individu* p = nullptr;
	
	for (unsigned int i = 0 ; i<W ; i++){
		for (unsigned int j = 0 ; j<H ; j++){
			
			p = pop[i][j];
			if (p->isalive ()){
				if (p->getgen ()){
						p->setfitness ((p->getphen())[2]);
					}else{
						p->setfitness ((p->getphen())[1]);
					}
				if (p->getfitness () < Wmin){
					p->setfitness(0);
				}
			}
			
		}
	}
}

//Méthodes auxiliaires

void Simulation::Afficher (){
	
	Individu* p = nullptr;
	int* sit = this->Situation ();
	
	std::cout << "La simulation est dans l'état : " << sit[2] << " avec : "<< std::endl ;
	std::cout << sit[0]<< " individus de phétonype A et "<< sit[1] << " individus de phétonype B." <<std::endl;
	
	for (unsigned int j = 0 ; j<H ; j++){
		for (unsigned int i = 0 ; i<W ; i++){
			p = pop[i][j];
			if (p->isalive()){
				std::cout << p->getgen () << " ";
			}else{
				std::cout << "X" << " ";
			}
		}
		std::cout << "" << std::endl;
	}
	std::cout << "L'état des ressources en A est le suivant : "<< std::endl ;
	MAP->AfficherA (); //TODO : ENLEVER APRES TESTS
	
}


//return : nb de genA, de genB, et un code pour la situation sur le plateau:
// -1 : extinction ;
// 0 : cohabitation ;
// 1 : S (gen B) éteinte.


int* Simulation::Situation (){
	//NB : 	//pop L == gen A == code bool 0
	
	int* Sit = new int[3]; 
	Sit[0] = 0;
	Sit[1] = 0;
	Sit[2] = 0;
	Individu* p = nullptr;
	for (unsigned int i = 0 ; i<W ; i++){
		for (unsigned int j = 0 ; j<H ; j++){
			
			p = pop[i][j];
			if (p->getgen() && p->isalive()){
				Sit[1]++;
			}else if (p->isalive()){
				Sit[0]++;
			}
			
		}
	}
	
	if (Sit[1] == 0){
		if (Sit[0] == 0){
			Sit[2] = -1; //extinction
		}else{
			Sit[2] = 1; //S éteinte (plus de gen B)	
		}
		return Sit;
	}
	Sit[2] = 0; //cohabitation. CAS genA étein non prévu.
	
	return Sit;
}

//Mise en place de conditions d'arrêt du système.
//TODO : changer nmax
void Simulation::JeContinue (int temps){
	if (temps > Tfini){
		std::cout << Tfini << " temps de simulation effectués. Arrêt de la simulation. " << std::endl;
		poursuivre = false;
		this->Afficher();
	}
	//TO DELETE
	//~ if ((this->Situation ())[2] != 0){
		//~ std::cout << "Les populations ne cohabitent plus ! Arrêt de la simulation." << std::endl;
		//~ poursuivre = false;
		//~ this->Afficher();
	//~ }
}

void Simulation::MAJparametres (){
	//TODO : import des paramètres depuis fichier texte
	Pmut = 0.1;
	Pdeath = 0.001;
		
	Raa = 0.1;
	Rbb = 0.1;
	Rab = 0.1;
	Rbc = 0.1;	
		
	Wmin = 0.001;
	Tfini = 10000;
	poursuivre = true;
}

