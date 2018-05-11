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
	
    double L1;
    double L2;
    double L3;

    double lambda;
	Vecteur A;

	public:


	void affiche(std::ostream& out)const;
		
        DoubleRessort(double m1,double k1,double m2,double k2,double k3,double lambda, //constructeur
                      Vecteur a={1,0,0},Vecteur P={1,0},Vecteur Q={1,0},
                      SupportADessin* vue=nullptr,  //Q et P doivent etre en dimension 2
                      double L1=2.0, double L2=3.0, double L3=2.0)

            : Oscillateur(P,Q,vue),m1(m1),k1(k1),m2(m2),k2(k2),k3(k3),lambda(lambda),L1(L1),L2(L2),L3(L3)
                { A=a.normalise(); }
		
		
		virtual Vecteur equation_evolution(double t)const override;
		
		void testevolution(double dt,double tlimite);
		
		virtual void dessine()const override{support->dessine(*this);};
		
        double get_P1() const {return P.getvalue(0); } //utile pour la partie graphique
        double get_P2() const {return P.getvalue(1); } //utile pour la partie graphique

        double get_L1() const {return L1; }
        double get_L2() const {return L2; }
        double get_L3() const {return L3; }

        double get_k1() const {return k1; }
        double get_k2() const {return k2; }
        double get_k3() const {return k3; }

	};

std::ostream& operator<<(std::ostream& out,DoubleRessort doubleressort);
		
