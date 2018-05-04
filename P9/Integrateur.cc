#include <iostream>
#include "Integrateur.h"
using namespace std;


		void IntegrateurEulerCromer::integre(Oscillateur& O, double t, double dt){
			O.setQ(O.getQ() + dt * O.equation_evolution(t) );
			O.setP(O.getP() + dt * O.getQ()                 );
		}		

		void IntegrateurEulerCromer::affiche_evol(Oscillateur O ) const {
			
			cout << "====================================== \n"
				 << endl
				 << O 
				 << endl ;
			double dt(0.01);
			IntegrateurEulerCromer E;
			for ( double t(0.0) ; t < 0.70; t+=dt){
					E.integre(O,t,dt);
					cout <<" # parametre " 
						 << O.getP() ;
				}
			}
		
