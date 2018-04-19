#include <iostream>
#include <vector>
#include "Oscillateur.h"
using namespace std;

int main ()
{

	Oscillateur O(1,2,0, 3,4,0);
	cout << O;
	double t(5);
	
	affiche_get(O,t);
	
	affiche_set(O);
	Vecteur P(1,2);
	Vecteur Q(3,4);
	Oscillateur O1(P,Q);
	affiche_get(O1,5);
	//affiche_set(O1); Revoir la def de affiche_set
	int i;
	cin >>i;
	return 0;
} 

