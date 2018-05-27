#pragma once
#include <string>
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
	double L1;			//Longueur 1
    double L2;			//Longueur 2
    double L3;			//Longueur 3
	Vecteur A;			//Vecteur unitaire de l'axe du double ressort

	public:


	void affiche(std::ostream& out)const;													//Methode affichage des attributs du double ressort
	
		DoubleRessort(double m1,double k1,double m2,double k2,double k3,double lambda,
		Vecteur a={1,0,0},Vecteur P={1.0,0},Vecteur Q={1.0,0},SupportADessin* vue=nullptr,	//Q et P doivent etre en dimension 2
                      double L1=2.0, double L2=3.0, double L3=2.0, 							// Longueurs des ressorts
                      double xo=-3.5 ,double yo=0,double zo=0):								//Point de vue pour le dessin:	
		Oscillateur(P,Q,vue,xo,yo,zo),m1(m1),k1(k1),m2(m2),k2(k2),k3(k3),lambda(lambda),L1(L1),L2(L2),L3(L3){
			A=a.normalise();
			if((P.getcoord().size()!=2)or(Q.getcoord().size()!=2)){
				std::string Err_dim_doubleressort("Erreur dimension des vecteurs");
				throw Err_dim_doubleressort;
			}
		}
		virtual Vecteur equation_evolution(double t)const override;							//Retourne le vecteur obtenu par l'equation d'evolution
		
		void testevolution(double dt,double tlimite);										//Methode qui teste la methode equation_evolution
		
		virtual void dessine()const override{support->dessine(*this);}						//Methode pour le dessin
	
	
		double get_P1() const {return P.getvalue(0); } 										//Utile pour la partie graphique
        double get_P2() const {return P.getvalue(1); } 										//Utile pour la partie graphique

        double get_L1() const {return L1; }
        double get_L2() const {return L2; }
        double get_L3() const {return L3; }

        double get_k1() const {return k1; }
        double get_k2() const {return k2; }
        double get_k3() const {return k3; }
	};
	
		std::ostream& operator<<(std::ostream& out,DoubleRessort const& doubleressort);		//Surchage operateur d'affichage
		
