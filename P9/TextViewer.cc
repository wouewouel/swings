#include <iostream>
#include "TextViewer.h"


using namespace std;

void TextViewer::dessine() {}; //	que mettre dedans ?
		
	void TextViewer::dessine(Pendule const& p){
		cout << p;
		}

	void TextViewer::dessine(Ressort const& r){
		cout << r;
		} 

    void TextViewer::dessine(Systeme const& s){}  //que mettre dedans ?
  //  void TextViewer::dessine(Systeme const& s){ //une version possible
  //		s.dessine();
  //	}
  //mais je pense que c'est inutile puisque le dessin d'un systeme n'est pas lie au support mais au support de ses oscillateurs
  //il faudrait demander a un assistant
	void TextViewer::dessine(DoubleRessort const& dr){
		cout<< dr;
	}
