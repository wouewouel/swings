#pragma once
#include <vector>
#include <memory>
#include "Oscillateur.h"
#include "Integrateur.h"

class Systeme : public Dessinable{

    private:
        std::vector<std::unique_ptr<Oscillateur>>systeme;

        Integrateur& integrateur;

    public:
        Systeme(SupportADessin* vue,Integrateur& integrateur):
            Dessinable(vue),systeme(0),integrateur(integrateur){}

        Systeme(Systeme const&) = delete;								//On ne peut pas copier de systeme a cause des unique ptr

        void ajoute(Oscillateur* o);									//Ajoute un oscillateur au systeme

        virtual void dessine()const override;							//Dessine tout le systeme

        void evolue(double t,double dt);								//Fait evoluer tout le systeme

        size_t nb_oscillateur() const {return systeme.size();}

        const Oscillateur& get_ref_oscillateur(size_t i) const {return *systeme[i];   }
        //on garde l'encapsulation !! car c'est juste un erefernece constante
};
