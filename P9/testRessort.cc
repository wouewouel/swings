#include <iostream>
#include <vector>
#include <string>
#include "Ressort.h"
using namespace std;

int main ()
{
	Ressort ressort1(1,1,1);
	cout<<ressort1;
	cout<<ressort1.equation_evolution(0);
	//ressort1.testevolution(0.1,1);
	Vecteur a(0.8,0,0.6);
	Vecteur P(0.18);
	Vecteur Q(0.0);
	Ressort ressort2(0.25,0.33,0.15,a,P,Q);
	cout<<ressort2;
	cout<<ressort2.equation_evolution(0);
	ressort2.testevolution(0.01,0.03);//il y a un bug avec 0.1 en dt et 0.3 en t
	
	
	return 0;
} 

