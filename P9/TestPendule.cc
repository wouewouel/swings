#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "Pendule.h"
using namespace std;

int main ()
{
    Pendule pendule1(1,1,1);
	cout<<pendule1;
	cout<<pendule1.equation_evolution(5);
	pendule1.testevolution(0.1,1);
	Pendule pendule2(1,1,0,M_PI/2,0);
	cout<<pendule2;
	pendule2.testevolution(0.1,0.3);
	return 0;
} 

