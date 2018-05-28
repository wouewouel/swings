#pragma once
#include <vector>
#include <memory>
#include "Oscillateur.h"
#include "Integrateur.h"

class Systeme : public Dessinable{

    private:
        std::vector<std::unique_ptr<Oscillateur>>systeme;

        Integrateur& integrateur;   /*  On a choisit des références aux lieu de poineurs car on peut s'en servir ici
                                        et qu'on favorise les références au pointeurs (bien que conceptuellemnt un syteme
                                        fait bien appel à un integrateur et n'en possède pas à proprement parler -> on peut
                                        d'ailleurs changer d'integrateur si on le veut !
                                    */

        std::vector<Vecteur> positions_initiales; //on ne doit pas pouvoir modifier ce tableau, sinon il n'y a
                                                       //aucun intéret de stoker les valeurs initiales
                                                       //on ne l'initialise pas dans le constructeur

    public:
        Systeme(SupportADessin* vue,Integrateur& integrateur):
            Dessinable(vue),systeme(0),integrateur(integrateur){}

        //On ne peut pas copier de systeme a cause des unique ptr
        Systeme(Systeme const&) = delete;

        //Ajoute un oscillateur au systeme
        void ajoute(Oscillateur* o);

        //Dessine tout le systeme
        virtual void dessine()const override;

        //Fait evoluer tout le systeme
        void evolue(double t,double dt);

        //Remet les oscillateurs du système à leur positions initiales
        void reset_systeme();

        //utile pour l'utilisation de la fonction suivante pour éviter les segmentation fault
        size_t nb_oscillateur() const {return systeme.size();}

        const Oscillateur& get_ref_oscillateur(size_t i) const {return *systeme[i];   }
       /* On a choisit cette implémentation car on préserve au mieux l'encapsulation (c'est juste une référence constante(!) même
          si ele permet de voir l'interieur du sytème). On aurait aussi pu voir les choses différemment et mettre un if
          dans chaque methode dessine() de VueOpenGL (qui ont un accès direct aux oscillateurs) pour décider si on dessine
          la phase au lieu de l'oscillateur mais il y aurait eu du copié collé et conceptuellement on aurait mit au même
          endroit la fonction que dessine la phase et le système ~
         */
};
