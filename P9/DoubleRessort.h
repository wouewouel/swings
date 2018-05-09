#pragma once
#include "Oscillateur.h"
#include "Integrateur.h"


class DoubleRessort:public Oscillateur{
	private:
	double m1;
	double k1;
	double m2;
	double k2;
	double k3;
	double lambda;
	Vecteur A;

	public:
	void affiche(std::ostream& out)const;
	
	DoubleRessort(double m1,double k1,double m2,double k2,double k3,double lambda,
	Vecteur a={1,0,0},Vecteur P={"a",1},Vecteur Q={"a",1},SupportADessin* vue=nullptr)://Q et P doivent etre en dimension 2
	Oscillateur(P,Q,vue),m1(m1),k1(k1),m2(m2),k2(k2),k3(k3),lambda(lambda){
		A=a.normalise();
	}
	
	
	virtual Vecteur equation_evolution(double t)const override;
	
	void testevolution(double dt,double tlimite);
	
	virtual void dessine()const override{support->dessine(*this);};
	
	
};
	std::ostream& operator<<(std::ostream& out,DoubleRessort const& doubleressort);
