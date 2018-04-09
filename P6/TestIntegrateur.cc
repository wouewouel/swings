#include <iostream>
#include <fstream>
#include "Integrateur.h"
#include "Oscillateur.h"
using namespace std;


int main()
{
	IntegrateurEulerCromer W;
	
	string cas1 ("normal.txt");
	Oscillateur O1(0,1,0, 1,2,0);
	W.affiche_evol(O1);
	
	string cas2 ("verslehaut.txt");
	Oscillateur O2(0,0,0, 0,2,0);
	W.affiche_evol(O2);
	
	string cas3 ("vitesse0.txt");
	Oscillateur O3(1,1,0, 0,0,0); 
	W.affiche_evol(O3);
	
	int i;
	cin >>i;
	return 0;
}
