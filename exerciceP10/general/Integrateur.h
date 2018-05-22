#pragma once
#include "Vecteur.h"
#include "Oscillateur.h"



class Integrateur {															//Classe abstraite
    public:
        virtual void integre(Oscillateur& O, double t, double dt)=0;		//Methode d'integration virtuelle pure

        virtual ~Integrateur(){};
    };


class IntegrateurEulerCromer : public Integrateur {
    public:
        virtual void integre(Oscillateur& O, double t, double dt)override;	//Methode d'integration

        void affiche_evol(Oscillateur O) const;								//Methode qui teste la
    };																		//methode integre


class IntegrateurNewmark : public Integrateur{
    private:
    double parametre;
    public:

    IntegrateurNewmark(double parametre=0.000001):parametre(parametre){};	//Constructeur pour definir le
                                                                            //parametre de l'integrateur

    virtual void integre(Oscillateur& O,double t,double dt) override;		//Methode d'integration

    void affiche_evol(Oscillateur O) const;									//Methode qui teste la
    };																		//methode integre


class IntegrateurRungeKutta:public Integrateur{
    public:

    virtual void integre(Oscillateur& O,double t,double dt) override;		//Methode d'integration

    void affiche_evol(Oscillateur O)const;									//Methode qui teste la
};																			//methode integre
