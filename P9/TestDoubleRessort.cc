#include <iostream>
#include <string>
#include <vector>
#include "DoubleRessort.h"
using namespace std;

int main()
{
	Vecteur a(0.8,0,0.6);
	Vecteur P(0.12,0.18);
	Vecteur Q(0.43,0.45);
	//Test constructeur
	DoubleRessort doubleressort(0.25,0.33,0.44,0.43,0.45,0.12,a,P,Q);
	
	
	//Test surchage operateur affichage
	cout<<doubleressort;
	
	//Test equation_evolution
	cout<<doubleressort.equation_evolution(4)<<endl;
	
	//Test evolution
	doubleressort.testevolution(0.1,0.4);
	int i;
	cin >>i;
	return 0;
}
