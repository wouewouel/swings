#include <iostream>
#include <string>
#include <vector>
#include "DoubleRessort.h"
using namespace std;

int main()
{
	Vecteur a(0.8,0,0.6);
	Vecteur P(0.12,0.18);
	Vecteur Q(0.13,0.15);
	DoubleRessort doubleressort(1,1,1,1,1,1,a,P,Q);
	cout<<doubleressort;
	int i;
	cin >>i;
	return 0;
}
