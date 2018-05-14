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
	int i;
	cin >>i;
	return 0;
} 

