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
	int i;
	cin >>i;
	return 0;
} 

