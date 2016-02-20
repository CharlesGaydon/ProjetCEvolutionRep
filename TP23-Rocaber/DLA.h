
#ifndef DLA_H_
#define DLA_H_
#include <iostream>
#include "ImagePPM.h"

class DLA {
	
	public :
	
		//constructeurs
		DLA();
		DLA(const DLA&);
		DLA(int);
		
		//accesseurs
		int L() const;
		int** p() const;
		ImagePPM image() const;
		
		//Méthodes
		void aggreg ();
		bool keepGoing ();
		bool Pout ();
		bool Pfree (int, int);
		void move ();
		void showTab();
	protected :
	
		//attributs
		int x;
		int y;
		int _L;
		int** _p;
		ImagePPM _image;	

};


#endif //DLA_H_
