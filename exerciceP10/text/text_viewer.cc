#include <iostream>
#include "text_viewer.h"
#include "Ressort.h"
#include "Pendule.h"

using namespace std;

    void TextViewer::dessine(Pendule const& p){
        flot << p;
        }

    void TextViewer::dessine(Ressort const& r){
        flot << r;
        }

    void TextViewer::dessine(Systeme const& a_dessiner){}  //que mettre dedans ?
  //  void TextViewer::dessine(Systeme const& s){ //une version possible
  //      a_dessiner.dessine();
  //	}

   /* il y avait déja
    void TextViewer::dessine(Contenu const& a_dessiner)
    {
    flot << a_dessiner.infos() << std::endl;
    }*/

  //mais je pense que c'est inutile puisque le dessin d'un systeme n'est pas lie au support mais au support de ses oscillateurs
  //il faudrait demander a un assistant
