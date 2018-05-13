#pragma once
#include <iostream>
#include "Oscillateur.h"
#include "Integrateur.h"
#include "support_a_dessin.h"

class Pendule:public Oscillateur{
	private:
	double m; //masse
	double L; //Longueur
	double lambda; //frottement fluide au point de rotation
	
	public:
	
    Pendule(double m,double L,double lambda,double P=1,double Q=1,SupportADessin* vue=nullptr,
            double xo=0 ,double yo=2.0,double zo=0) //point de vue pour le dessin
        :	Oscillateur(P,Q,vue,xo,yo,zo),m(m),L(L),lambda(lambda){}
                                        //P et Q sont en dimension 1 donc on les initialise avec des double
                                        //le constructeur d'oscillateur les convertira en vecteur
    double get_P() const {return P.getvalue(0); }

    double get_Q()const {return Q.getvalue(0);}

    double get_m() const {return m;}
	
    double get_L() const {return L;}
	
    double get_lambda() const {return lambda;}
	
    void testevolution(double dt,double tfinal);
	
    virtual Vecteur equation_evolution(double t) const override;

    void affiche(std::ostream& out);
	
    virtual void dessine()const override{support->dessine(*this);}

   };

std::ostream& operator<<(std::ostream& out,Pendule pendule);
