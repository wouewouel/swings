#pragma once
#include <vector>
#include "Oscillateur.h"
#include "Dessinable.h"
class Systeme:public Dessinable{
	private:
	std::vector <Oscillateur*>systeme;
	public:
	virtual void dessine()const override{
		for(auto const& element:systeme){
			element->dessine();
		}
	}
	void evolue(){
		for(auto const& element:systeme){
			element->equation_evolution();
};
