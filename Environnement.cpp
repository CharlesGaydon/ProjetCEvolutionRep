#include <iostream>
#include "Environnement.h"


//Conctructeurs
Environnement::Environnement () {
	
	//Déclaré privé pour empêcher son usage.
	
	//~ W = 0;
	//~ H = 0;
	//~ D = 0;
	
	//~ resA = nullptr;
	//~ resB = nullptr;
	//~ resC = nullptr;

	//~ NresA = nullptr;
	//~ NresB = nullptr;
	//~ NresC = nullptr;
	
}

Environnement::Environnement (unsigned int nW, unsigned int nH, double nAinit) {
	
	W = nW;
	H = nH;
	D = 0.1;
	Ainit = nAinit;
	
	//Ressources
	
	resA = new double*[W];
	resB = new double*[W];
	resC = new double*[W];

	NresA = new double*[W];
	NresB = new double*[W];
	NresC = new double*[W];
	
	for (unsigned int i = 0 ; i< W ; i++){	
		
		resA[i] = new double[H];
		resB[i] = new double[H];
		resC[i] = new double[H];
		
		NresA[i] = new double[H];
		NresB[i] = new double[H];
		NresC[i] = new double[H];
		
		for (unsigned int j = 0 ; j<H ; j++){			
			resA[i][j] = Ainit;	
			resB[i][j] = 0;	
			resC[i][j] = 0;
			
			NresA[i][j] = Ainit;	
			NresB[i][j] = 0;	
			NresC[i][j] = 0;			
		}	
		
	}

}

Environnement::Environnement (unsigned int nW, unsigned int nH, double nAinit, double nD) {
	
	W = nW;
	H = nH;
	D = nD;
	Ainit = nAinit;
	
	//Ressources
	
	resA = new double*[W];
	resB = new double*[W];
	resC = new double*[W];

	NresA = new double*[W];
	NresB = new double*[W];
	NresC = new double*[W];
	
	for (unsigned int i = 0 ; i< W ; i++){	
		
		resA[i] = new double[H];
		resB[i] = new double[H];
		resC[i] = new double[H];
		
		NresA[i] = new double[H];
		NresB[i] = new double[H];
		NresC[i] = new double[H];
		
		for (unsigned int j = 0 ; j<H ; j++){			
			resA[i][j] = Ainit;	
			resB[i][j] = 0;	
			resC[i][j] = 0;
			
			NresA[i][j] = Ainit;	
			NresB[i][j] = 0;	
			NresC[i][j] = 0;			
		}	
		
	}
	
}

//Destructeur

Environnement::~Environnement (){

	for (unsigned int i = 0 ; i< W ; i++){	
		delete[] resA[i];
		delete[] resB[i];
		delete[] resC[i];
		
		delete[] NresA[i];
		delete[] NresB[i];
		delete[] NresC[i];
	}		
	delete[] resA;
	delete[] resB;
	delete[] resC;
	
	delete[] NresA;
	delete[] NresB;
	delete[] NresC;
	
}


//Méthodes de la simulation


void Environnement::Diffusion (){
	int x = 0;
	int y = 0;
	for (unsigned int i = 0 ; i<W ; i++){
		for (unsigned int j = 0 ; j<H ; j++){
			
			NresA[i][j] = resA[i][j];
			NresB[i][j] = resB[i][j];
			NresC[i][j] = resC[i][j];
			
			for (int dx = -1; dx<2 ; dx++){
				for (int dy = -1 ; dy<2 ; dy++){
					x = i + dx;
					y = j + dy;
					if (x<0){x = W-1;}
					if (x == W){x = 0;}
					if (y<0){y = H-1;}
					if (y == H){y = 0;}
					NresA[i][j]+= D*resA[x][y];
					NresB[i][j]+= D*resB[x][y];
					NresC[i][j]+= D*resC[x][y];
				}
			}
		resA[i][j] = NresA[i][j] - 9*D*resA[i][j];
		resB[i][j] = NresB[i][j] - 9*D*resB[i][j];
		resC[i][j] = NresC[i][j] - 9*D*resC[i][j];

		}
	}
}

void Environnement::clean (){
	
	for(unsigned int i = 0 ; i<W ; i++){
		for (unsigned int j = 0 ; j<H ; j++){
			resA[i][j] = Ainit;
			resB[i][j] = 0;
			resC[i][j] = 0;
		}
	}
}


//Méthodes auxilaires


void Environnement::AfficherA (){

	for (unsigned int j = 0 ; j<H ; j++){
		for (unsigned int i = 0 ; i<W ; i++){
			std::cout << resA[i][j] << " ";
		}
		std::cout << "" << std::endl;
	}

}

void Environnement::AfficherB (){

	for (unsigned int j = 0 ; j<H ; j++){
		for (unsigned int i = 0 ; i<W ; i++){
			std::cout << resB[i][j] << " ";
		}
		std::cout << "" << std::endl;
	}

}


