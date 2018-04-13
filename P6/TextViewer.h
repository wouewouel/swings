#pragma once
#include "SupportADessin"

class TextViewer:public SupportADessin{
	public:
	virtual void dessine();
	virtual void dessine(Pendule const&);
	virtual void dessine(Ressort const&);
	virtual void dessine(Systeme const&);
}
