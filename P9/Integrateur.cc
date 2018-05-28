#include <iostream>
#include "Integrateur.h"
using namespace std;


void IntegrateurEulerCromer::integre(Oscillateur& O, double t, double dt){
			O.setQ(O.getQ() + dt * O.equation_evolution(t) );			//Methode d'integration
			O.setP(O.getP() + dt * O.getQ()                 );	
}
				
void IntegrateurEulerCromer::affiche_evol(Oscillateur O ) const {														//Methode qui teste la
	cout << "====================================== \n"			//methode integre
	<< endl
	<< O 
	<< endl ;
	double dt(0.01);
	IntegrateurEulerCromer E;
	for ( double t(0.0) ; t < 0.70; t+=dt){
		E.integre(O,t,dt);
		cout <<" # parametre " 
		<< O.getP();
	}
}
			
			
void IntegrateurNewmark::integre(Oscillateur& O,double t,double dt){
	Vecteur q;
	Vecteur r;
	Vecteur s;
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
	cout<< "====================================== \n"			//methode integre
		<< endl
		<< O;
	double dt(0.01);
	IntegrateurNewmark N;
	for( double t(0.0) ; t < 0.70; t+=dt){
			N.integre(O,t,dt);
			cout <<" # parametre " 
				 << O.getP() ;
	}
}
		
void IntegrateurRungeKutta::integre(Oscillateur& O,double t,double dt){
	Vecteur k1(O.getQ());
	Vecteur k1p(O.equation_evolution(t));
	Vecteur k2(O.getQ()+0.5*dt*k1p);
	Oscillateur O2(O.getP()+0.5*dt*k1,O.getQ()+0.5*dt*k1p);
	Vecteur k2p(O2.equation_evolution(t+0.5*dt));
	Vecteur k3(O.getQ()+0.5*dt*k2p);
	O2.setP(O.getP()+0.5*dt*k2);
	O2.setQ(O.getQ()+0.5*dt*k2p);
	Vecteur k3p(O2.equation_evolution(t+0.5*dt));
	Vecteur k4(O.getQ()+dt*k3p);
	O2.setP(O.getP()+dt*k3);
	O2.setQ(O.getQ()+dt*k3p);
	Vecteur k4p(O2.equation_evolution(t+dt));
	O.setP(O.getP()+(dt/6)*(k1+2*k2+2*k3+k4));
	O.setQ(O.getQ()+(dt/6)*(k1p+2*k2p+2*k3p+k4p));
}
		
void IntegrateurRungeKutta::affiche_evol(Oscillateur O ) const {	//Methode qui teste la
	cout << "====================================== \n"				//methode integre
		 << endl
		 << O;
	double dt(0.01);
	IntegrateurRungeKutta R;
	for ( double t(0.0) ; t < 0.70; t+=dt){
			R.integre(O,t,dt);
			cout <<" # parametre " 
				 << O.getP() ;
		}
	}
