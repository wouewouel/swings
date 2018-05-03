#pragma once
#include "Oscillateur.h"
#include "Integrateur.h"
 
class Ressort:public Oscillateur{
	private:
	
	double m; //masse
	double k; //constante de raideur
	double lambda; //frottement fluide au point de rotation
	Vecteur A; //vecteur unitaire de dimension 3
	
	public:
	
	void affiche(std::ostream& out);
	Ressort(double m,double k,double lambda,Vecteur a={1,0,0},Vecteur P={"a",1},Vecteur Q={"a",1},SupportADessin* vue=nullptr):
	Oscillateur(P,Q,vue),m(m),k(k),lambda(lambda){
		A=a.normalise();//necessaire de normaliser a?
	}
	
	virtual Vecteur equation_evolution(double t)const override;
	
	void testevolution(double dt,double tlimite);
		
	
	virtual void dessine()const override{support->dessine(*this);};
};
	std::ostream& operator<<(std::ostream& out,Ressort r);
	
