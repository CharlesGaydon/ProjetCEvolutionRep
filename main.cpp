#include "Individu.h"
#include "Environnement.h"
#include "Simulation.h"

#include <string>
#include <iostream>

int main(){
	//Exemple de Simulation.
	using namespace std; 
	Simulation S = new Simulation(32,32,500,0.1);
	S->Simulate ();
	S.Afficher (); 
	
	//Construction du diagramme de phase
	
	int NPrecision = 2;
	(vector <string>)* res = new (vector <int*>)[NPrecision];
	double* tab = nullptr;	
	
	Simulation* S; 
	unsigned int nW = 32;
	unsigned int nH = 32;
	int pasT = 30;
	double pasA = 4;
	
	for (int i = 0 ; i<NPrecision ; i++){
		ostringstream s;
		s << i << flush;
		
		string title = "PhaseN" + s.str();
		cout << "titre du fichier enregistré : " title << endl;
		
		FILE* f;
		f = fopen (title,"wt");
		if (f == NULL){
			cout << "Impossible d'ouvrir le fichier en écriture !" << endl;
		}else{
			for (int T = 1 ; T<=500 ; T = T + pasT){
				for (double A = 0 ; A <= 50 ; A = A + pasA){
					
					S = new Simulation(nW,nH,T,A);
					S->Simulate ();
					
					fprintf (f, "%d %f %d \n",T,A,S->Situation ());	
					
					tab = new double[3];	
					tab[0] = T;
					tab[1] = A;
					tab[2] = S->Situation ();
					res[i].push_back(tab);
					delete S;
				}
			}
			fclose (f);
		}
	}
	
	//Comparer situation par situation et refaire ceux qui le nécessitent 
	//le double de NPrecision 
	
	int state = 0;
	int j = 1;
	for (int i = 0; i < res[0].size() ; i++){
		state = res[0][i];
		j = 1;
		while (j<NPrecision){
			if (state != res[j][i]){
				//Augmenter le nombre de valeurs disponibles pour 
				
				
				j = NPrecision;
			}
			j++;
		}
	}
	
	
  return 0;  
}
