#include <iostream>
#include "TextViewer.h"
#include "Ressort.h"
#include "Pendule.h"

using namespace std;

//	void TextViewer::dessine() {}; 	que mettre dedans ?
		
	void TextViewer::dessine(Pendule const& p){
		cout << p;
		}

	void TextViewer::dessine(Ressort const& r){
		cout << r;
		} 

//	void TextViewer::dessine(Systeme const& s){} 	que mettre dedans ?


