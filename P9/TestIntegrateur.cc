#include <iostream>
#include <fstream>
#include "Integrateur.h"
#include "Oscillateur.h"
using namespace std;


int main()
{
	//Test generaux dimension 2
	IntegrateurEulerCromer W;											//Test integrateur Euler Cromer
	cout<<"Test integrateur Euler Cromer:"<<endl<<"Normal:"<<endl;
	Oscillateur O1(0,1,1,2);
	W.affiche_evol(O1);
	
	cout<<endl<<"Verslehaut:"<<endl;
	Oscillateur O2(0,0, 0,2);
	W.affiche_evol(O2);
	
	cout<<endl<<"vitesse nulle:"<<endl;
	Oscillateur O3(1,1,0,0); 
	W.affiche_evol(O3);
	
	IntegrateurNewmark N;												//Test integrateur Newmarck
	cout<<"Test integrateur Newmarck:"<<endl<<"Normal:"<<endl;
	Oscillateur O4(0,1,1,2);
	N.affiche_evol(O4);
	
	cout<<endl<<"Verslehaut:"<<endl;
	Oscillateur O5(0,0,0,2);
	N.affiche_evol(O5);
	
	cout<<endl<<"Vitesse nulle:"<<endl;
	Oscillateur O6(1,1, 0,0);
	N.affiche_evol(O6);
	
	IntegrateurRungeKutta R;												//Test integrateur RungeKutta
	cout<<"Test integrateur RungeKutta:"<<endl<<"Normal:"<<endl;
	Oscillateur O4bis(0,1,1,2);
	R.affiche_evol(O4bis);
	
	cout<<endl<<"Verslehaut:"<<endl;
	Oscillateur O5bis(0,0,0,2);
	R.affiche_evol(O5bis);
	
	cout<<endl<<"Vitesse nulle:"<<endl;
	Oscillateur O6bis(1,1, 0,0);
	N.affiche_evol(O6bis);
	//Test Oscillateur dimension 1
	
	cout<<endl<<"Test oscillateur dimension 1:"<<endl;
	Oscillateur O7(3,4);
	cout<<"Oscillateur 7, test Euler:"<<endl;							//Test Euler Cromer
	W.affiche_evol(O7);
	Oscillateur O8(3,4);
	cout<<endl<<"Oscillateur 8, test Newmarck:"<<endl;					//Test Newmarck
	N.affiche_evol(O8);
	Oscillateur O8bis(3,4);
	cout<<endl<<"Oscillateur 8bis, test RungeKutta:"<<endl;				//Test RungeKutta
	R.affiche_evol(O8bis);
	
	//Test oscillateur dimension 3
	
	cout<<endl<<"Test oscillateur dimension 3:"<<endl;
	Oscillateur O9(3,3,4,4,5,6);
	cout<<"Oscillateur 9, test Euler:"<<endl;							//Test Euler
	W.affiche_evol(O9);
	Oscillateur O10(3,3,4,4,5,6);
	cout<<endl<<"Oscillateur 10, test Newmarck:"<<endl;					//Test Newmarck
	N.affiche_evol(O10);
	Oscillateur O10bis(3,3,4,4,5,6);
	cout<<endl<<"Oscillateur 10bis, test RungeKutta:"<<endl;					//Test RungeKutta
	N.affiche_evol(O10bis);
	return 0;
}
