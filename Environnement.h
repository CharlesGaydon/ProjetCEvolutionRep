
#ifndef ENVIRONNEMENT_H_
#define ENVIRONNEMENT_H_
class Environnement {
	
	protected:
		
		//variables
		unsigned int W;
		unsigned int H;
		double D;
		double Ainit;

	public:
		//constructeurs
		Environnement ();
		Environnement (unsigned int nW, unsigned int nH, double nAinit);
		Environnement (unsigned int nW, unsigned int nH, double nAinit, double nD);
		
		//destructeur
		~Environnement ();
		
		//table
		double*** res;	
		
		//méthodes	
		void diffusion ();
		

	
	
};

#endif //ENVIRONNEMENT_H_
