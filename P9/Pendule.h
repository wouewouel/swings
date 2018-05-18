#pragma once
#include "Oscillateur.h"
#include "Integrateur.h"

class Pendule:public Oscillateur{
	private:
	double m;		//Masse
	double L;		//Longueur
	double lambda;	//frottement fluide au point de rotation
	
	public:
	
	Pendule(double m,double L,double lambda,double P=1,double Q=1,SupportADessin* vue=nullptr):
	Oscillateur(P,Q,vue),m(m),L(L),lambda(lambda){}							//P et Q sont en dimension 1 donc on les initialise avec des double
																			//le constructeur d'oscillateur les convertira en vecteur
	void affiche(std::ostream& out)const;									//Methode affichage des attributs du double ressort
	
	virtual Vecteur equation_evolution(double t) const override;			//Fonction qui renvoie le vecteur de l'equation d'evolution
	
	void testevolution(double dt,double tfinal);							//Fonction qui teste l'equation d'evolution
	
	virtual void dessine()const override{support->dessine(*this);};			//Methode pour le dessin

	void dessine_phase()const override{support->dessine_phase(*this);};		//Methode dessin phase
};

std::ostream& operator<<(std::ostream& out,Pendule const& pendule);			//Surchage operateur affichage
