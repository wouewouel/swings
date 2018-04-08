#pragma once
#include "Vecteur.h"
#include "Oscillateur.h"



class Integrateur {
	public: 
		void integre(Oscillateur& O, double t, double dt) {};
	};

class IntegrateurEulerCromer : public Integrateur {
	public:
		void integre(Oscillateur& O, double t, double dt);
		
		void affiche_evol(Oscillateur O) const;
	};

