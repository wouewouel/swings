#include <iostream>
#include <vector>
#include <string>
#include "Ressort.h"
using namespace std;

int main ()
{ 
	//Test constructeur
	
	Ressort ressort1(1,1,1);
	Vecteur a(0.8,0,0.6);
	Vecteur P(0.18);
	Vecteur Q(0.0);
	Ressort ressort2(0.25,0.33,0.15,a,P,Q);
	Ressort ressort3(0.25,0.33,0.15,0.18,1,a);
	
	
	//Test operateur affichage
	
	cout<<"Ressort1:"<<endl<<ressort1;
	cout<<"Ressort2:"<<endl<<ressort2;
	cout<<"Ressort3:"<<endl<<ressort3;
	
	//Test equation evolution
	
	cout<<"Ressort 1:"<<endl<<"equation_evolution: ";
	cout<<ressort1.equation_evolution(0);
	ressort1.testevolution(0.1,1);
	cout<<"Ressort 2:"<<endl<<"equation_evolution: ";
	cout<<ressort2.equation_evolution(0);
	ressort2.testevolution(0.01,0.03);
	
	
	//Test avec parametre limite
	Ressort ressort4 (200,1,0,1,0);		//Grande masse
	Ressort ressort5 (0.001,1,0,1,0);	//Petite masse
	Ressort ressort6 (1,1000,0,1,0);	//Raideur tres grande
	Ressort ressort7 (1,1,1,1,0);		//Frottement
	Ressort ressort8 (1,1,0,1,1);		//Vitesse de depart
	cout<<"Ressort 4(grande masse): "<<endl<<ressort4;
	ressort4.testevolution(0.1,1);
	cout<<"Ressort 5(petite masse): "<<endl<<ressort5;
	ressort5.testevolution(0.1,1);
	cout<<"Ressort 6(raideur tres grande): "<<endl<<ressort6;
	ressort6.testevolution(0.1,1);
	cout<<"Ressort 7(frottement): "<<endl<<ressort7;
	ressort7.testevolution(0.1,1);
	cout<<"Ressort 8(vitesse de depart): "<<endl<<ressort8;
	ressort8.testevolution(0.1,1);
	 
	return 0;
} 

