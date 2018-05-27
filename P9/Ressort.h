#pragma once
#include "Oscillateur.h"
#include "Integrateur.h"

class Ressort:public Oscillateur{
	private:
	
	double m;		//Masse
	double k;		//Constante de raideur
	double lambda;	//Frottement fluide au point de rotation
	Vecteur A; 		//vecteur unitaire de dimension 3
	
	public:
	
	Ressort(double m,double k,double lambda,Vecteur a={1,0,0},Vecteur P={1},Vecteur Q={1},SupportADessin* vue=nullptr):
	Oscillateur(P,Q,vue),m(m),k(k),lambda(lambda){						//On definit les vecteurs par defaut 
		A=a.normalise();												//au cas ou on oublie de les mettre en arguments
	}
	Ressort(double m,double k,double lambda,double P,double Q,Vecteur a={1,0,0},SupportADessin* vue=nullptr):// constructeurs avec des doubles
	Oscillateur(P,Q,vue),m(m),k(k),lambda(lambda){						//On garde le constructeur avec des vecteurs?
		A=a.normalise();
	}
	
	double get_m() const {return m;}
	
    double get_k()const {return k;}
	
    double get_lambda()const {return lambda;}
	
    double get_A()const {return A.norme();}

    double get_P() const {return P.getvalue(0); } 						//Utile pour la partie graphique
	
	virtual Vecteur equation_evolution(double t)const override; 		//Fonction qui renvoie le vecteur de l'equation d'evolution
	
	void testevolution(double dt,double tlimite); 						//Fonction qui teste l'equation d'evolution
		
	void affiche(std::ostream& out)const;								//Methode affichage des attributs du double ressort
	
	virtual void dessine()const override{support->dessine(*this);};		//Methode pour le dessin
};
	std::ostream& operator<<(std::ostream& out,Ressort const& r);		//Surchage operateur affichage
	
