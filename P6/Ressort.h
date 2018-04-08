#pragma once
#include "Oscillateur.h"
 
class Ressort:public Oscillateur{
	private:
	
	double m; //masse
	double k; //constante de raideur
	double lambda; //frottement fluide au point de rotation
	Vecteur A={1,0,0}; //vecteur unitaire de dimension 3
	
	public:
	
	double get_m();
	
	double get_k();
	
	double get_lambda();
	
	Vecteur get_A();
	
	Ressort(double m,double k,double lambda,Vecteur a={1,0,0},Vecteur P={'a',1},Vecteur Q={'a',1}):Oscillateur(P,Q),m(m),k(k),lambda(lambda){
		//remplacer par une fonction qui normalise a
		A=a;
	}
	
	Vecteur equation_evolution(double t)const;
};
	std::ostream& operator<<(std::ostream& out,Ressort r);
	
