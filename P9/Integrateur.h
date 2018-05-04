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

