#include <iostream>
#include "TextViewer.h"


using namespace std;

void TextViewer::dessine() {} //	que mettre dedans ?
		
	void TextViewer::dessine(Pendule const& p){
		cout<<p;
		}

	void TextViewer::dessine(Ressort const& r){
		cout<<r;
		} 

    void TextViewer::dessine(Systeme const& s){
	   		s.dessine();
	  	}
	  //Il faut bien que le système fasse appel au différentes fonctions dessine de ses oscillateurs
	  void TextViewer::dessine(DoubleRessort const& dr){
			cout<< dr;
		}
