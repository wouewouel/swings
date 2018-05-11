#pragma once
#include "Vecteur.h"
#include "Oscillateur.h"



class Integrateur {
	public: 
		virtual void integre(Oscillateur& O, double t, double dt)=0;
	};

class IntegrateurEulerCromer : public Integrateur {
	public:
		virtual void integre(Oscillateur& O, double t, double dt)override;
		
		void affiche_evol(Oscillateur O) const;
	};
class IntegrateurNewmark : public Integrateur{
	private:
	Vecteur q;
	Vecteur r;
	Vecteur s;
	double parametre=0.000001;
	public:
	virtual void integre(Oscillateur& O,double t,double dt) override;
	
	void affiche_evol(Oscillateur O) const;
	};

