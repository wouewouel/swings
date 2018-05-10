#include <iostream>
#include "text_viewer.h"
#include "Ressort.h"
#include "Pendule.h"
#include "Systeme.h"
#include "DoubleRessort.h"

using namespace std;

    void TextViewer::dessine(Pendule const& p){
        flot << p;
        }

    void TextViewer::dessine(Ressort const& r){
        flot << r;
        }

    void TextViewer::dessine(DoubleRessort const& dr){
        flot << dr;
      }

    void TextViewer::dessine(Systeme const& a_dessiner){
       a_dessiner.dessine();
      }

