#include <iostream>

class Cellular {
	public :
	
		//constructeurs
			
		Cellular ();
		Cellular (int);
		Cellular (const Cellular&);
		
		//destructeur
		~Cellular ();
		
		//getters
		
		int get_N () const;
		int** get_T () const;
		
		//méthodes
		
		void calculate ();
		int code (int, int, int);
		
	protected :
		
		int N;
		int** T;
	
};
