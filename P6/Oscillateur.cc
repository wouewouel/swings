#include <iostream>
#include <vector>
#include <string>
#include "Oscillateur.h"
using namespace std;


		Vecteur Oscillateur::equation_evolution(double t) const {  // utiliser Vecteur const en retour ?
			return Vecteur (0.0, -9.81);			  // modifie P et Q indirectement non ?
		}
		
		Vecteur Oscillateur::getP() const {return P;}
		
		Vecteur Oscillateur::getQ() const {return Q;}
		
		void Oscillateur::setP(Vecteur const& V){
			if(V.getcoord().size() <= P.getcoord().size() ){
				P = V;
			}else {
				throw string("le vecteur ne possède pas autant de dimension(s) !");
				}
			} 
		
		void Oscillateur::setQ(Vecteur const& V){
			if(V.getcoord().size() <= Q.getcoord().size() ){
				Q = V;
			}else {
				throw string("le vecteur ne possède pas autant de dimension(s) !");
				}
			}
	
		ostream& operator<<(ostream& sortie, Oscillateur const& O){
		    sortie  << " # Oscillateur " <<endl
			    	<< " # parametre (P) : " << O.getP() 
			        << " # vitesse   (Q) : " << O.getQ() <<"\n"
			        << "======================================" <<endl ;
			return sortie;
			}
			
		
