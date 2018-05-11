#include <iostream>
#include <fstream>
#include "Integrateur.h"
#include "Oscillateur.h"
using namespace std;


int main()
{
	IntegrateurEulerCromer W;
	
	string cas1 ("normal.txt");
	Vecteur P(0,1);
	Vecteur Q(1,2);
	Oscillateur O1(P,Q);
	//W.affiche_evol(O1);
	
	string cas2 ("verslehaut.txt");
	Oscillateur O2(0,0,0, 0,2,0);
	//W.affiche_evol(O2);
	
	string cas3 ("vitesse0.txt");
	Oscillateur O3(1,1,0, 0,0,0); 
	//W.affiche_evol(O3);
	
	IntegrateurNewmark N;
	Oscillateur O4(P,Q);
	N.affiche_evol(O4);
	
	
	int i;
	cin >>i;
	return 0;
}
