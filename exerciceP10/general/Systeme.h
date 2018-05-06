#pragma once
#include <vector>
#include <memory>
#include "Oscillateur.h"
#include "Integrateur.h"
#include "support_a_dessin.h"

class Systeme : public Dessinable{
	
	private:
        std::vector<std::unique_ptr<Oscillateur>> systeme;

        Integrateur& integrateur;//Il faut faire du polymorphisme !!!
		
	public:
        Systeme(SupportADessin* vue,Integrateur& integrateur):
            Dessinable(vue),systeme(0),integrateur(integrateur){}
		
		void ajoute(Oscillateur* o);
		
        virtual void dessine()const ;
			
		void evolue(double t,double dt);

        std::vector<std::unique_ptr<Oscillateur>> get_systeme() const;

};
