#pragma once
#include "Oscillateur.h"
#include "Integrateur.h"
#include "support_a_dessin.h"

class Ressort:public Oscillateur {
	private:
	
	double m; //masse
	double k; //constante de raideur
	double lambda; //frottement fluide au point de rotation
	Vecteur A; //vecteur unitaire de dimension 3
	
	public:
	
    double get_m() const {return m;}
	
    double get_k()const {return k;}
	
    double get_lambda()const {return lambda;}
	
    double get_A()const {return A.norme();}

    double get_P() const {return P.getvalue(0); } //utile pour la partie graphique
	
    Ressort(double m,double k,double lambda,Vecteur a={1,0,0},Vecteur P={1},Vecteur Q={1},SupportADessin* vue=nullptr)
        : Oscillateur(P,Q,vue),m(m),k(k),lambda(lambda){
        A=a.normalise();//necessaire de normaliser a?
        }
	
	virtual Vecteur equation_evolution(double t)const override;
	
	void testevolution(double dt,double tlimite);
		
    void affiche(std::ostream& out);

	virtual void dessine()const override{support->dessine(*this);};

};

std::ostream& operator<<(std::ostream& out,Ressort r);
	
