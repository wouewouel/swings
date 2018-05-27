#pragma once
#include "Oscillateur.h"
#include "Integrateur.h"

class Pendule:public Oscillateur{
	private:
	double m;		//Masse
	double L;		//Longueur
	double lambda;	//frottement fluide au point de rotation
	
	public:
	
	Pendule(double m,double L,double lambda,double P=1,double Q=1,SupportADessin* vue=nullptr,
	double xo=0 ,double yo=2.0,double zo=0):								//Point de vue pour le dessin):
	Oscillateur(P,Q,vue,xo,yo,zo),m(m),L(L),lambda(lambda){}				//P et Q sont en dimension 1 donc on les initialise avec des double
																			//le constructeur d'oscillateur les convertira en vecteur
	 double get_P() const {return P.getvalue(0); }							//Les getters sont utiles pour la version graphique uniquement

    double get_Q()const {return Q.getvalue(0);}

    double get_m() const {return m;}
	
    double get_L() const {return L;}
	
    double get_lambda() const {return lambda;}
	
	virtual Vecteur equation_evolution(double t) const override;			//Fonction qui renvoie le vecteur de l'equation d'evolution
	
	void testevolution(double dt,double tfinal);							//Fonction qui teste l'equation d'evolution
	
	void affiche(std::ostream& out)const;									//Methode affichage des attributs du pendule
	
	virtual void dessine()const override{support->dessine(*this);};			//Methode pour le dessin

};

std::ostream& operator<<(std::ostream& out,Pendule const& pendule);			//Surchage operateur affichage
