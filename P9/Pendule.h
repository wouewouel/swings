#pragma once
#include "Oscillateur.h"
#include "Integrateur.h"

class Pendule:public Oscillateur{
	private:
	double m; //masse
	double L; //Longueur
	double lambda; //frottement fluide au point de rotation
	
	public:
	
	Pendule(double m,double L,double lambda,double P=1,double Q=1,SupportADessin* vue=nullptr):
	Oscillateur(P,Q,vue),m(m),L(L),lambda(lambda){}//P et Q sont en dimension 1 donc on les initialise avec des double
	                                               //le constructeur d'oscillateur les convertira en vecteur
	void affiche(std::ostream& out);
	
	void testevolution(double dt,double tfinal);
	
	virtual Vecteur equation_evolution(double t) const override;
	
	virtual void dessine()const override{support->dessine(*this);};
};

std::ostream& operator<<(std::ostream& out,Pendule pendule);