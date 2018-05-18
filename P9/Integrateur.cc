#include <iostream>
#include "Integrateur.h"
using namespace std;


		void IntegrateurEulerCromer::integre(Oscillateur& O, double t, double dt){
			O.setQ(O.getQ() + dt * O.equation_evolution(t) );			//Methode d'integration
			O.setP(O.getP() + dt * O.getQ()                 );
			
		}		

		void IntegrateurEulerCromer::affiche_evol(Oscillateur O ) const {
																		//Methode qui teste la
			cout << "====================================== \n"			//methode integre
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
			
			
		void IntegrateurNewmark::integre(Oscillateur& O,double t,double dt){
			Vecteur P(O.getP());										//Methode d'integration
			Vecteur Q(O.getQ());
			s=O.equation_evolution(t);
			Vecteur condition;
			do{
				q=O.getP();
				r=O.equation_evolution(t);
				O.setQ(Q+0.5*dt*(r+s));
				O.setP(P+dt*Q+((dt*dt)/3)*(0.5*r+s));
				condition=O.getP()-q;
			}while (condition.norme()>=parametre);
		}
		
		void IntegrateurNewmark::affiche_evol(Oscillateur O ) const {	//Methode qui teste la
			cout << "====================================== \n"			//methode integre
				 << endl
				 << O;
			double dt(0.01);
			IntegrateurNewmark E;
			for ( double t(0.0) ; t < 0.70; t+=dt){
					E.integre(O,t,dt);
					cout <<" # parametre " 
						 << O.getP() ;
				}
			}
