//#pragma once
#include "SupportADessin.h"

class TextViewer:public SupportADessin{
	public:
	virtual void dessine() override;
	virtual void dessine(Pendule const& p);
	virtual void dessine(Ressort const& r); 
	virtual void dessine(Systeme const& s);
};
