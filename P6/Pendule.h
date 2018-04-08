#pragma once
#include "Oscillateur.h"

class Pendule:public Oscillateur{
	private:
	double m; //masse
	double L; //Longueur
	double lambda; //frottement fluide au point de rotation
	
	public:
	
	Pendule(double m,double L,double lambda,double P=1,double Q=1):Oscillateur(P,Q),m(m),L(L),lambda(lambda){}//P et Q sont en dimension 1
	
	double get_m();
	
	double get_L();
	
	double get_lambda();
	
	Vecteur equation_evolution(double t);
};

std::ostream& operator<<(std::ostream& out,Pendule pendule);