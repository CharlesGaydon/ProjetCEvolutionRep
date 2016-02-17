
#ifndef INDIVIDU_H_
#define INDIVIDU_H_

class Individu {
	
	public :
		
		//constructeurs
		
		Individu (void);
		Individu (unsigned int nx, unsigned int ny, bool ngen);
		Individu (const Individu& model);
		
		//destructeur
		
		~Individu (void);
		
		//Variables
		double* phen;
		bool divide;
		
		
		//Accesseurs
		inline unsigned int getx (void) const;
		inline unsigned int gety (void) const;		
		inline double getfitness (void) const;
		inline double* getphen (void) const;
		inline bool getgen (void) const;
		inline bool candivide (void) const;
		inline bool isalive (void) const;
		
		//Actualisation
		void actfitness (void);
		
	protected :
	
		//Variables
		bool gen; //0 : A, 1 : B
		bool vivant;
		double fitness;
		unsigned int x;
		unsigned int y;
	
};

//Definition des accesseurs

inline unsigned int Individu::getx (void) const {
	return x;
}

inline unsigned int Individu::gety (void) const {
	return y;
}

inline double Individu::getfitness (void) const {
	return fitness;
}

inline double* Individu::getphen (void) const {
	return phen;
}

inline bool Individu::getgen (void) const {
	return gen;
}

inline bool Individu::candivide (void) const {
	return divide;
}

inline bool Individu::isalive (void) const{
	return vivant;
}

#endif //INDIVIDU_H_
