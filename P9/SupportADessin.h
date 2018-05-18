#pragma once

class Pendule;
class Ressort;
class Systeme;
class DoubleRessort;

class SupportADessin{
	public:
	
	virtual ~SupportADessin(){}
	
	virtual void dessine() =0;
	
	virtual void dessine(Pendule const&) = 0;
	
	virtual void dessine(Ressort const&) = 0;
	
	virtual void dessine(Systeme const&) = 0;
	
	virtual void dessine(DoubleRessort const&) = 0;
	
	virtual void dessine_phase(Pendule const&) = 0;
	
	virtual void dessine_phase(Ressort const&) = 0;
	
	virtual void dessine_phase(Systeme const&) = 0;
	
	virtual void dessine_phase(DoubleRessort const&) =0;
};
