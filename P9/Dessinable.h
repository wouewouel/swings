#pragma once
#include "SupportADessin.h"
class Dessinable{
	protected:
		SupportADessin* support;
	public:
		Dessinable(SupportADessin* support):support(support){}
		
		virtual ~Dessinable(){}						//On delete le pointeur dans le destructeur?
		
		virtual void dessine()const =0;				//Methode virtuelle pure pour dessiner
		
		virtual void dessine_phase()const =0;		//Methode virtuelle pure pour dessin de phase
	};
