//#pragma once
#include "SupportADessin.h"

class TextViewer:public SupportADessin{
	public:
	virtual void dessine() override;
	virtual void dessine(Pendule const& p)override;
	virtual void dessine(Ressort const& r)override; 
	virtual void dessine(Systeme const& s)override;
};
