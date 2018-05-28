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
	
    Ressort(double m,double k,double lambda,Vecteur a={1,0,0},Vecteur P={1},Vecteur Q={1},
            SupportADessin* vue=nullptr,double xo=-2 ,double yo=-2.0,double zo=0)           //point de vue pour le dessin
        : Oscillateur(P,Q,vue,xo,yo,zo),m(m),k(k),lambda(lambda){
        A=a.normalise();
        }


    double get_m() const {return m;}                        //utile pour la partie graphique
	
    double get_k()const {return k;}                         //
	
    double get_lambda()const {return lambda;}               //
	
    double get_A()const {return A.norme();}                 //

    double get_P() const {return P.getvalue(0); }           //   !!
	

    virtual Vecteur equation_evolution(double t)const override;     //Fonction qui renvoie le vecteur de l'equation d'evolution
	
    void testevolution(double dt,double tlimite);                   //fonction qui teste l'équation d'évolution
		
    void affiche(std::ostream& out);                                //Methode affichage des attributs du double ressort

    virtual void dessine()const override{support->dessine(*this);}; //Methode pour le dessin

};

std::ostream& operator<<(std::ostream& out,Ressort r);              //surcharge de l'opérateur d'affichage
	
