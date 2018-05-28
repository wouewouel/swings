#pragma once
#include <vector>
class Pendule;
class Ressort;
class Systeme;
class Oscillateur;
class DoubleRessort;


class SupportADessin{
        public:

        virtual ~SupportADessin(){}

        virtual void dessine(Pendule const&) = 0;

        virtual void dessine(Ressort const&) = 0;

        virtual void dessine(Systeme const&) = 0;

        virtual void dessine(DoubleRessort const&) = 0;

        virtual void dessinePhase(Oscillateur const&)= 0;

        protected:

        std::vector<double> pos_phase;          //avoir la position des composantes de P et Q à  chaque pas de temps

        //on a choisit cette implémentation car à chaque fois on affiche qu'une seule phase donc pas besoinn de stocker
        //toutes les position dans les oscillateurr : on dupliquerai du code inutilement si on n'implémentait ça dans Systeme

};

