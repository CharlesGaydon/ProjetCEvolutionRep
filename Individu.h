
#ifndef INDIVIDU_H_
#define INDIVIDU_H_

class Individu {
	
	public :
		
		//constructeurs
		

		Individu (unsigned int nx, unsigned int ny, bool ngen);
		Individu (const Individu& model);
		
		//destructeur
		
		~Individu (void);
		
		//Variables
		double* phen;
		bool divide;
		
		
		//Accesseurs
		inline unsigned int getx () const;
		inline unsigned int gety () const;		
		inline double getfitness () const;
		inline double* getphen () const;
		inline bool getgen () const;
		inline bool candivide () const;
		inline bool isalive () const;
		
		//mutateurs
		
		inline void setA (double nA);
		inline void setB(double nB);
		inline void setC (double nC);
		
		inline void setgen (bool ngen);
		inline void setfitness (double nfit);
		
		inline void kill ();
		inline void mutate ();
		inline void godivide ();
		inline void stopdivide ();

		void Dby2 ();
		
		//Actualisation
		void actfitness ();
		
	protected :
	
		//Variables
		bool gen; //0 : A, 1 : B
		bool vivant;
		double fitness;
		unsigned int x;
		unsigned int y;
	private :
		Individu (void);
	
};

//Definition des accesseurs inline

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

//Definition des mutateurs inline

inline void Individu::setA (double nA){
	phen[0] = nA;
}

inline void Individu::setB (double nB){
	phen[1] = nB;
}

inline void Individu::setC (double nC){
	phen[2] = nC;
}

inline void Individu::setgen (bool ngen){
	gen = ngen;
}

inline void Individu::setfitness (double nfit){
	fitness = nfit;
}

//Special ones

inline void Individu::kill (){
	vivant = false;
}

inline void Individu::mutate (){
	gen = !gen;
	this->actfitness ();
}

inline void Individu::godivide (){
	divide = true;
}

inline void Individu::stopdivide (){
	divide = false;
}
#endif //INDIVIDU_H_
