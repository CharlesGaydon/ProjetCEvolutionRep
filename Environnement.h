
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
	
		//table
		double** resA;	
		double** resB;
		double** resC;
		
		double** NresA;	
		double** NresB;
		double** NresC;
		
		//constructeurs
		Environnement (unsigned int nW, unsigned int nH, double nAinit);
		Environnement (unsigned int nW, unsigned int nH, double nAinit, double nD);
		
		//destructeur
		~Environnement ();
		
		//accesseur
		inline double getA (int i, int j) const;
		inline double getB (int i, int j) const;
		inline double getC (int i, int j) const;
		
		inline double getNA (int i, int j) const;
		inline double getNB (int i, int j) const;
		inline double getNC (int i, int j) const;
		
		//mutateurs
		inline void setA (int i, int j, double nA);
		inline void setB (int i, int j, double nB);
		inline void setC (int i, int j, double nC);
		
		//méthodes	de la simulation
		void Diffusion ();
		void clean ();
		
		//méthodes auxiliaires
		void AfficherA ();
		void AfficherB ();

	private:
	
		//constructeur non utilisable
		Environnement ();
	
	
};

//definition of inline getters

inline double Environnement::getA (int i, int j) const {
	return resA[i][j];
}
inline double Environnement::getB (int i, int j) const {
	return resB[i][j];
}
inline double Environnement::getC (int i, int j) const {
	return resC[i][j];
}


inline double Environnement::getNA (int i, int j) const {
	return NresA[i][j];
}
inline double Environnement::getNB (int i, int j) const {
	return NresB[i][j];
}
inline double Environnement::getNC (int i, int j) const {
	return NresC[i][j];
}

//definition of inline setters

inline void Environnement::setA (int i, int j, double nA) {
	resA[i][j] = nA;
}
inline void Environnement::setB (int i, int j, double nB) {
	resB[i][j] = nB;
}
inline void Environnement::setC (int i, int j, double nC) {
	resC[i][j] = nC;
}



#endif //ENVIRONNEMENT_H_
