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

        std::vector<double> pos_phase;


};

