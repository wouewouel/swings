#include <iostream>
#include "TextViewer.h"


using namespace std;
	
	//Methode dessin
	void TextViewer::dessine() {} 
		
	void TextViewer::dessine(Pendule const& p){
		cout<<p;
		}

	void TextViewer::dessine(Ressort const& r){
		cout<<r;
		} 

    void TextViewer::dessine(Systeme const& s){
	   		s.dessine();
	  	}
	  	
	void TextViewer::dessine(DoubleRessort const& dr){
			cout<< dr;
		}
	
	//Methode dessin de phase	
	void TextViewer::dessine_phase(Pendule const& p){
		cout<<"Parametre: "<<p.getP()<<"     "<<"Vitesse: "<<p.getQ()<<endl;
	}
	
	void TextViewer::dessine_phase(Ressort const& r){
		cout<<"Parametre: "<<r.getP()<<"     "<<"Vitesse: "<<r.getQ()<<endl;
	}
	
	void TextViewer::dessine_phase(Systeme const& s){
		s.dessine_phase();
	}
	
	void TextViewer::dessine_phase(DoubleRessort const& dr){
		cout<<"Parametre: "<<dr.getP().getvalue(0)<<"     "<<"Vitesse: "<<dr.getQ().getvalue(0)<<endl;
	}
