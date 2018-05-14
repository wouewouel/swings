#pragma once
#include "Oscillateur.h"
#include "Integrateur.h"

class DoubleRessort:public Oscillateur{	//voir si on rajoute les longueurs en attribut
	private:
	double m1;			//Masse 1
	double k1;			//Constante de raideur ressort 1
	double m2;			//Masse 2
	double k2;			//Constante de raideur ressort 2
	double k3;			//Constante de raideur ressort 3
	double lambda;		//Frottement fluide au point de rotation
	Vecteur A;			//Vecteur unitaire de l'axe du double ressort

	public:


	void affiche(std::ostream& out)const;													//Methode affichage des attributs du double ressort
	
		DoubleRessort(double m1,double k1,double m2,double k2,double k3,double lambda,
		Vecteur a={1,0,0},Vecteur P={1.0,0},Vecteur Q={1.0,0},SupportADessin* vue=nullptr):	//Q et P doivent etre en dimension 2
		Oscillateur(P,Q,vue),m1(m1),k1(k1),m2(m2),k2(k2),k3(k3),lambda(lambda){
			A=a.normalise();
		}
		virtual Vecteur equation_evolution(double t)const override;							//Retourne le vecteur obtenu par l'equation d'evolution
		
		void testevolution(double dt,double tlimite);										//Methode qui teste la methode equation_evolution
		
		virtual void dessine()const override{support->dessine(*this);}						//Methode pour le dessin
	};
	
		std::ostream& operator<<(std::ostream& out,DoubleRessort const& doubleressort);		//Surchage operateur d'affichage
		
