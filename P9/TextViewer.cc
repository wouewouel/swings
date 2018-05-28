#include <iostream>
#include "TextViewer.h"
#include <iomanip>

using namespace std;
	
	//Methode dessin
		
	void TextViewer::dessine(Pendule const& p){
		flot<<p;
		}

	void TextViewer::dessine(Ressort const& r){
		flot<<r;
		} 

    void TextViewer::dessine(Systeme const& s){
	   		s.dessine();
	  	}
	  	
	void TextViewer::dessine(DoubleRessort const& dr){
			flot<< dr;
		}
	
	
    void TextViewer::dessinePhase(Oscillateur const& O){
        pos_phase.push_back(O.getP().getvalue(0));
        pos_phase.push_back(O.getQ().getvalue(0));
        flot<< "=======Portrait de phase===== \n";
        for(size_t i(0); i<pos_phase.size() ; i+=2){
            flot << setw(10)<<"coord de (P,Q) a t=";
            flot << i/(2);
            flot << " : ("<<setw(5)<<  pos_phase[i] << " , " <<pos_phase[i+1]<<") "<<endl;
        }
    }
