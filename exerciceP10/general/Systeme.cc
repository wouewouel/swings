#include <iostream>
#include <vector>
#include "Systeme.h"


using namespace std;

void Systeme::ajoute(Oscillateur* o){			//Ajoute un oscillateur au systeme
    if(o!=nullptr){
        o->set_support(support);
        systeme.push_back(unique_ptr<Oscillateur>(o));
    }
}

    void Systeme::dessine()const{				//Dessine tout le systeme
            for(auto const& element:systeme){
                element->dessine();
            }
        }


    void Systeme::evolue(double t,double dt){	//Fait evoluer tout le systeme
        for(auto const& element:systeme){
            integrateur->integre(*element,t,dt);
        }
    }


/*
Je sais que c'est dangereux car les oscillateurs possèdent un pointeur sur un support a dessin
(il faudrait faire une copie profonde mais ça beugue pour faire une copie profonde d'une classe abstraite..)
mais ici nous ne modifierons rien, c'est juste pour l'affichage
 A TCHEKER AVEC UN ASSISTANT POUR UNE MEILLEUR SOLUTION*/


