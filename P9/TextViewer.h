#pragma once
#include "SupportADessin.h"
#include "Ressort.h"
#include "Pendule.h"
#include "Systeme.h"
#include "Ressort.h"
#include "DoubleRessort.h"



class TextViewer:public SupportADessin{
	public:
	virtual void dessine() override;
	virtual void dessine(Pendule const& p)override;
	virtual void dessine(Ressort const& r)override; 
	virtual void dessine(Systeme const& s)override;
	virtual void dessine(DoubleRessort const& dr)override;
};
