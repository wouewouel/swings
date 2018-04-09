#include <iostream>
#include <vector>
#include <string>
#include "Pendule.h"
using namespace std;

int main ()
{
    Pendule pendule(1,1,1);
	cout<<pendule;
	cout<<pendule.equation_evolution(5);
	int i;
	cin >>i;
	return 0;
} 

