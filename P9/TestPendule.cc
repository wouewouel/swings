#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "constantes.h"
#include "Pendule.h"
using namespace std;

int main ()
{	
	//Test constructeur
	
    Pendule pendule1(1,1,1);
    Pendule pendule2(1,1,0,M_PI/2,0);
    
    
    //Test operateur affichage
    
	cout<<"Pendule 1: "<<endl<<pendule1;
	cout<<"Pendule 2: "<<endl<<pendule2;
	
	
	//Test equation evolution
	cout<<"Pendule 1: "<<endl;
	cout<<pendule1.equation_evolution(5);
	pendule1.testevolution(0.1,1);
	cout<<"Pendule 2: "<<endl;
	cout<<pendule2.equation_evolution(5);
	pendule2.testevolution(0.1,0.4);
	
	//Test avec parametre limite
	Pendule pendule3 (200,1,0,M_PI/2,0);		//Grande masse
	Pendule pendule4 (0.001,1,0,M_PI/2,0);		//Petite masse
	Pendule pendule5 (1,1000,0,M_PI/2,0);		//fil tres grand
	Pendule pendule6 (1,1,1,M_PI/2,0);			//Frottement
	Pendule pendule7 (1,1,0,M_PI/2,M_PI/2);		//Vitesse de depart
	cout<<"Pendule 3(grande masse): "<<endl<<pendule3;
	pendule3.testevolution(0.1,1);
	cout<<"Pendule 4(Petite masse): "<<endl<<pendule4;
	pendule4.testevolution(0.1,1);
	cout<<"Pendule 5(fil tres grand): "<<endl<<pendule5;
	pendule5.testevolution(0.1,1);
	cout<<"Pendule 6(frottement): "<<endl<<pendule6;
	pendule6.testevolution(0.1,1);
	cout<<"Pendule 7(vitesse de depart): "<<endl<<pendule7;
	pendule7.testevolution(0.1,1);
	return 0;
} 

