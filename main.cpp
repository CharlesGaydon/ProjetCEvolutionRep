#include "Individu.h"
#include "Environnement.h"
#include "Simulation.h"


#include <vector>

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
int main(){

	unsigned int nW = 32;
	unsigned int nH = 32;	


//Exemple de Simulation.

	using namespace std; 
	//~Simulation S = new Simulation(32,32,500,0.1);
	//~S->Simulate ();
	//~S.Afficher (); 
	
//Construction du diagramme de phase BIS
	
	//parametres
	int NPrecision = 2; //2
	int pasT = 5; //5
	double pasA = 4	;	//4

	vector<vector<double*>> res (NPrecision+1, vector<double*> (0));
	cout << res[0].size() << endl;
	double* tab = nullptr;	
	
	Simulation* S; 

	for (int T = 1 ; T<=500 ; T = T + pasT){
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
		for (int T = 1 ; T<=500 ; T = T + pasT){
			for (double A = 0 ; A <= 50 ; A = A + pasA){
				S = new Simulation(nW,nH,T,A);
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
	
	
	//penser aux delete
	
	//Comparer situation par situation et refaire ceux qui le nécessitent 
	//le double de NPrecision 
	

	double state;
	int j;
	
	int sit = 0;
	int* etats = new int[3]; //-1 0 1
	//pour créer une différence :
	cout << "On avait : " << res[2][0][0] <<" "<< res[2][1][0]<<endl; 
	res[1][0][0] = 0;

	cout << "On a : " << res[2][0][0] <<" "<< res[2][1][0]<<endl; 

	
	for (int i = 0; i < res[1].size() ; i++){

		state = res[1][i][0];
		j = 2;
		etats[0] = 0;
		etats[1] = 0;
		etats[2] = 0;		
		cout << "On a : " << res[2][0][0] <<" "<< res[2][1][0]<<endl; 
		while (j<NPrecision+1){
			cout << state << " vs "<<  res[j][i][0] <<" en "<<i<<" "<<j<<endl;
			
			if (state != res[j][i][0]){
				cout << "différence rencontrée ! " << endl;
				
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
	delete tab;
	//Ecrire les bonnes valeurs
	stringstream s;
	s << "pT" << pasT << "pA" << pasA << "Pres" << NPrecision<<".txt";	
	string title = "Diagramme_" + s.str();
	
	ofstream f(title.c_str());

	cout << "Titre du fichier a enregistrer : " << title.c_str() << endl;

	for (int i = 0; i < res[0].size() ; i++){
		f << res[0][i][0]<<" "<<res[0][i][1]<<" "<<res[1][i][0] << endl;
	}
	f.close ();
	
	
	
	delete etats;
	return 0;
}
