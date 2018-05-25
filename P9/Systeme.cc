#include <iostream>
#include <vector>
#include "Systeme.h"


using namespace std;

void Systeme::ajoute(Oscillateur* o){			//Ajoute un oscillateur au systeme
	if(o!=nullptr){
		systeme.push_back(unique_ptr<Oscillateur>(o));
	}
}

	void Systeme::dessine()const{				//Dessine tout le systeme
			for(auto const& element:systeme){
				element->dessine();
			}
		}
	void Systeme::dessine_phase()const{			//Dessine les phases de tout le systeme
		for(auto const& element:systeme){
			element->dessine_phase();
		}
	}
		
	void Systeme::evolue(double t,double dt){	//Fait evoluer tout le systeme
		for(auto const& element:systeme){
			integrateur.integre(*element,t,dt);
		}
	}
