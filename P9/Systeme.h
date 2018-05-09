#pragma once
#include <vector>
#include <memory>
#include "Oscillateur.h"
#include "Dessinable.h"
#include "Integrateur.h"
class Systeme : public Dessinable{
	
	private:
		std::vector<std::unique_ptr<Oscillateur>>systeme;
		
		IntegrateurEulerCromer integrateur;//Integrateur ou integrateur euler cromer?
		
	public:
		Systeme(SupportADessin* vue,IntegrateurEulerCromer integrateur):Dessinable(vue),systeme(0),integrateur(integrateur){}

		void ajoute(Oscillateur* o);
		
		virtual void dessine()const override;
			
		void evolue(double t,double dt);
};
