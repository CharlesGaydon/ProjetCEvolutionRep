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
	
	//~ Pmut = 0;
	//~ Pdeath = 0;
		
	//~ Raa = 0;
	//~ Rbb = 0;
	//~ Rab = 0;
	//~ Rbc = 0;
	
	//~ Wmin = 0;
	//~ Tfini = 0;
	
}

//:param nT: nombre de tours avant changement de milieu.
Simulation::Simulation (unsigned int nW, unsigned int nH, 
						double nT, double nAinit){
							
	T = nT;
	Ainit = nAinit;
	D = 0.1;
	W = nW;
	H = nH;
	
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
	MAP = new Environnement(W, H, Ainit);
	
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

			if (NewGenotype) {nbB++;} else {nbA++;}
			pop[i][j] = new Individu(i,j, NewGenotype);
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
	MAP = new Environnement(W, H, Ainit, D);
	
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
	int nbCycle = 0;
	
	//TODO : lecture du fichier texte pour paramètres
	while (this->JeContinue (nbCycle)){
		for (unsigned int i = 0 ; i<T ; i++){
			//Les métabolites externes diffusent dans l'environnement
			MAP->Diffusion ();
			//Certains individus meurent, leurs métabolites sont rejetés
			//et ils passent de vivant à mort
			this->Hecatombe ();
			//COmpétition pour la reproduction. parcours aléatoire des 
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
			this->Metabolisme ();
			//Affichage de la boîte de pétri
			this->Afficher ();
		}
		nbCycle++;	
	}
}

void Simulation::Hecatombe (){
	//TODO
}

void Simulation::GuerreSexuelle (){
	//TODO
}

void Simulation::Metabolisme (){
	//TODO
}

void Simulation::Mutation (){
	//TODO
}



//Méthodes auxiliaires

void Simulation::Afficher (){
	
	int* sit = this->Situation ();
	std::cout << "La simulation est dans l'état : " << sit[2] << " avec : "<< std::endl ;
	std::cout << sit[0]<< " individus de phétonype A et "<< sit[1] << " individus de phétonype B." <<std::endl;
	
	for (unsigned int j = 0 ; j<H ; j++){
		for (unsigned int i = 0 ; i<W ; i++){
			std::cout << (pop[i][j])->getgen () << " ";
		}
		std::cout << "" << std::endl;
	}
	std::cout << "L'état des ressources en A est le suivant : "<< std::endl ;
	MAP->AfficherA ();
}
//Retourne : nb de genA, de genB, et un code pour la situation sur le plateau:
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

bool Simulation::JeContinue (int nbCycle){
	bool cont = false;
	//TODO
	return cont;
}



