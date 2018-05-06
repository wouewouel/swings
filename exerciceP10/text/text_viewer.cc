#include <iostream>
#include "text_viewer.h"
#include "Ressort.h"
#include "Pendule.h"
#include "Systeme.h"

using namespace std;

    void TextViewer::dessine(Pendule const& p){
        flot << p;
        }

    void TextViewer::dessine(Ressort const& r){
        flot << r;
        }

    void TextViewer::dessine(Systeme const& a_dessiner){
        a_dessiner.dessine();
    }


  //mais je pense que c'est inutile puisque le dessin d'un systeme n'est pas lie au support mais au support de ses oscillateurs
  //il faudrait demander a un assistant
