#pragma once
#include <vector>
#include <memory>
#include "Oscillateur.h"
#include "Integrateur.h"

class Systeme : public Dessinable{
	
	private:
		std::vector<std::unique_ptr<Oscillateur>>systeme;
		
		Integrateur& integrateur;	
		
	public:
		Systeme(SupportADessin* vue,Integrateur& integrateur):
			Dessinable(vue),systeme(0),integrateur(integrateur){}
		
		Systeme(Systeme const&) = delete;								//On ne peut pas copier de systeme a cause des unique ptr

		void ajoute(Oscillateur* o);									//Ajoute un oscillateur au systeme
		
		virtual void dessine()const override;							//Dessine tout le systeme
		
		virtual void dessine_phase()const override;						//Dessine les phases de tout le systeme
			
		void evolue(double t,double dt);								//Fait evoluer tout le systeme
};
