#include "Individu.h"
#include "Environnement.h"
#include "Simulation.h"


#include <vector>

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std; 
int main(){

	unsigned int nW = 32;
	unsigned int nH = 32;	


//Exemple de Simulation.

	//~Simulation* S = new Simulation(32,32,75,25);
	//~S->Simulate ();
	//~S->Afficher (); 
	
//Construction du diagramme de phase BIS
	//~
	//parametres
	int NPrecision = 2; //2
	int pasT = 25; //5
	double pasA = 9	;	//4
	int maxT = 600;
	double D = 0.1;

	vector<vector<double*>> res (NPrecision+1, vector<double*> (0));
	double* tab = nullptr;
	
	Simulation* S; 

	for (int T = 1 ; T<=maxT ; T = T + pasT){
		for (double A = 0 ; A <= 50 ; A = A + pasA){
			tab = new double[2];	
			tab[0] = T;
			tab[1] = A;
			res[0].push_back(tab);				
		}
	}	
	
	for (int i = 1 ; i<NPrecision+1 ; i++){
		
		stringstream s;
		s << "Phase" << i <<"pT" << pasT << "pA" << pasA << "Pres" << NPrecision<< ".txt";	
		string title = s.str();
		
		ofstream f(title.c_str());
		cout << "Titre du fichier a enregistrer : " <<title.c_str() << endl;	
		for (int T = 1 ; T<=maxT ; T = T + pasT){
			for (double A = 0 ; A <= 50 ; A = A + pasA){
				S = new Simulation(nW,nH,T,A,D);
				S->Simulate ();
				
				f << T<<" "<<A<<" "<< S->Situation () << endl;	

				tab = new double[1];
				tab[0] = S->Situation ();
				res[i].push_back(tab);
				
				delete S;
				}
		}
		f.close();
	}
	
	//Comparer situation par situation et refaire ceux qui le nécessitent 
	//le double de NPrecision 

	double state;
	int j;
	
	int sit = 0;
	int* etats = new int[3]; //-1 0 1
	
	for (int i = 0; i < res[1].size() ; i++){

		state = res[1][i][0];
		j = 2;
		etats[0] = 0;
		etats[1] = 0;
		etats[2] = 0;		
		while (j<NPrecision+1){
			
			
			if (state != res[j][i][0]){
				cout << "Différence rencontrée :" << endl;
				cout << state << " vs "<<  res[j][i][0] <<" en T = "<<res[1][i][0]<<" et A = "<< res[j][i][1]<<endl;
				for(int k =0 ; k< NPrecision ; k++){
					etats[(int) res[k+1][i][0]+1]++;
					S = new Simulation(nW,nH,res[0][i][0],res[0][i][1]);
					S->Simulate ();	
					sit = S->Situation ();
					
					etats[sit+1]++; 				
					delete S;
				}
				cout << etats[0] << " "<< etats[1]<< " "<<etats[2] <<endl;
				//Calcul du plus fréquent :
				if((etats[0] >= etats[1]) && (etats[0] >= etats[2])){
					res[1][i][0] = -1;
				}
				if((etats[1] >= etats[0]) && (etats[1] >= etats[2])){
					res[1][i][0] = 0;
				}		
				if((etats[2] >= etats[0]) && (etats[2] >= etats[1])){
					res[1][i][0] = 1;
				}					
				
				j = NPrecision+1;				
				
			}
			
			j++;
		}
		
	}
	cout << "ici" << endl;
	delete[] tab;
		cout << "la" << endl;
	//Ecrire les bonnes valeurs
	stringstream s;
	s << "pT" << pasT << "pA" << pasA << "Pres" << NPrecision<<"D"<<D<<".txt";	
	string title = "Diagramme_" + s.str();
	
	std::ofstream f(title.c_str(), std::ios::out | std::ios::trunc );

	cout << "Titre du fichier a enregistrer : " << title.c_str() << endl;
		cout << "On a bien "<< (res[0]).size() << (res[1]).size()<< endl;
	for (int i = 0; i < (res[0]).size() ; i++){
		cout << "On voit : " << res[0][i][0] << res[0][i][1] <<res[1][i][0]<< endl;
		f << res[0][i][0]<<" "<<res[0][i][1]<<" "<<res[1][i][0] << endl;	
		cout << "la" << endl;
	}


	//ERREUR
	//~for (vector<vector<double*>>::iterator it = res.begin() ; it != res.end(); ++it){
		//~for (vector<double*>::iterator it2 = (*it).begin() ; it2 != (*it).end(); ++it2){
			//~delete[] *it2;
		//~}
	//~} 
	//~res.clear();
	//delete[] etats;
	return 0;
}
