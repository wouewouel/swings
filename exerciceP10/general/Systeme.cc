#include <iostream>
#include <vector>
#include <memory>
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
    vector<unique_ptr<Oscillateur>> Systeme::get_systeme() const {
        vector<unique_ptr<Oscillateur>> result;
        for(auto const& chacun : systeme) {
            result.push_back(unique_ptr<Oscillateur>(new Oscillateur(*chacun)));
        }
        return result;

/*
Je sais que c'est dangereux car les oscillateurs possèdent un pointeur sur un support a dessin
(il faudrait faire une copie profonde mais ça beugue pour faire une copie profonde d'une classe abstraite..)
mais ici nous ne modifierons rien, c'est juste pour l'affichage
 A TCHEKER AVEC UN ASSISTANT POUR UNE MEILLEUR SOLUTION*/

    }
