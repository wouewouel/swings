#include <iostream>
#include <vector>
#include <string>
#include "Oscillateur.h"
using namespace std;


		Vecteur Oscillateur::equation_evolution(double t) const {  
			//Vecteur evol = (P + Q )* t;
			//return evol;
			Vecteur g(0,-9.81); //pour le test de l'integrateur
			return g;
		}
		
		Vecteur Oscillateur::getP() const {return P;}	//Retourne P
		
		Vecteur Oscillateur::getQ() const {return Q;}	//Retourne Q
		
		void Oscillateur::setP(Vecteur const& V){		//Modifie P
			if(V.getcoord().size() <= P.getcoord().size() ){
				P = V;
			}else {
				throw string("le vecteur ne possede pas autant de dimension(s) !");
				}
			} 
		
		void Oscillateur::setQ(Vecteur const& V){		//Modifie Q
			if(V.getcoord().size() <= Q.getcoord().size() ){
				Q = V;
			}else {
				throw string("le vecteur ne possede pas autant de dimension(s) !");
				}
			}
	
		ostream& operator<<(ostream& sortie, Oscillateur const& O){	//Surchage operateur affichage
		    sortie  << " # Oscillateur " <<endl
			    	<< " # parametre (P) : " << O.getP() 
			        << " # vitesse   (Q) : " << O.getQ() <<"\n";
			return sortie;
			}
			
		void affiche_get(Oscillateur const& O,double t) {			//methode pour tester les methodes get
	  cout <<" Tests de get() : \n   de son parametre : " 
		   << O.getP()        << "   de sa vitesse    : "
		   << O.getQ() 		  << endl;
	  cout <<" Sa fonction d'evolution donne pour t = "
		   << t << " : " << O.equation_evolution(t) << endl;
   }
		
		void affiche_set(Oscillateur& O) {							//methode pour tester les methodes set
	  O.setP(Vecteur (-2, -1, 0)); 
	  cout <<" Tests de set() : \n   de son parametre : " 
		   << O.getP()        
		   << "   donne : " << endl
		   << O;   
	  O.setQ(Vecteur (-6, 12, 0)); 
	  cout  << "   de sa vitesse    : " 
		    <<O.getQ()
		    << "   donne : " << endl		
		    << O 		     << endl;
   }
