#include <iostream>
#include <vector>
#include "Systeme.h"
#include "Oscillateur.h"
#include "Integrateur.h"

using namespace std;

void Systeme::ajoute(Oscillateur* o){
	if(o!=nullptr){
		systeme.push_back(unique_ptr<Oscillateur>(o));
	}
}

	void Systeme::dessine()const{
			for(auto const& element:systeme){
				element->dessine();
			}
		}
		
	void Systeme::evolue(double t,double dt){
		for(auto const& element:systeme){
            integrateur.integre(*element,t,dt);
		}
	}
