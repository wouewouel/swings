//#pragma once
#include "SupportADessin.h"
#include "Ressort.h"
#include "Pendule.h"
#include "Systeme.h"
#include "Ressort.h"
#include "DoubleRessort.h"


class TextViewer:public SupportADessin{
	public:
	
	//Methode de dessin
	virtual void dessine() override;
	virtual void dessine(Pendule const& p)override;
	virtual void dessine(Ressort const& r)override; 
	virtual void dessine(Systeme const& s)override;
	virtual void dessine(DoubleRessort const& dr)override; 
	
	//Methode de dessin de phase
	virtual void dessine_phase(Pendule const& p)override;
	virtual void dessine_phase(Ressort const& r)override;
	virtual void dessine_phase(Systeme const& s) override;
	virtual void dessine_phase(DoubleRessort const& dr)override;
};
