#include <iostream>
#include <vector>
#include "Systeme.h"


using namespace std;

void Systeme::ajoute(Oscillateur* o){			//Ajoute un oscillateur au systeme
    if(o!=nullptr){
        o->set_support(support);
        systeme.push_back(unique_ptr<Oscillateur>(o));
        positions_initiales.push_back(o->getP());
        positions_initiales.push_back(o->getQ());
    }
}

    void Systeme::dessine()const{				//Dessine tout le systeme
            for(auto const& element:systeme){
                element->dessine();
            }
        }


    void Systeme::evolue(double t,double dt){	//Fait evoluer tout le systeme
        for(auto const& element:systeme){
            integrateur.integre(*element,t,dt);
        }
    }

    void Systeme::reset_systeme(){
        for(size_t i(0); i< nb_oscillateur(); ++i){
            systeme[i]->setP(positions_initiales[2*i]);
            systeme[i]->setQ(positions_initiales[2*i+1]);
        }
    }


