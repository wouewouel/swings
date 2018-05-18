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
	Vecteur Q1(1,1);
	//Test constructeur
	DoubleRessort doubleressort(0.25,0.33,0.44,0.43,0.45,0.12,a,P,Q);
	DoubleRessort doubleressort2(doubleressort);
	
	
	//Test surchage operateur affichage
	cout<<"Double ressort: "<<endl<<doubleressort;
	cout<<"Double ressort: "<<endl<<doubleressort2;
	//Test equation_evolution
	cout<<doubleressort.equation_evolution(4)<<endl;
	
	//Test evolution
	doubleressort.testevolution(0.1,0.4);
	
	//Test avec parametre limite
	DoubleRessort doubleressort3 (4,0.33,0.44,0.43,0.45,0.12,a,P,Q);	//Plus grande masse 1
	DoubleRessort doubleressort4 (0.01,0.33,0.44,0.43,0.45,0.12,a,P,Q);	//Plus petite masse 1
	DoubleRessort doubleressort5 (0.25,1,0.44,0.43,0.45,0.12,a,P,Q);	//Plus grand k1
	DoubleRessort doubleressort6 (0.25,0.01,0.44,0.43,0.45,0.12,a,P,Q);	//Plus faible k1
	DoubleRessort doubleressort7 (0.25,0.33,4,0.43,0.45,0.12,a,P,Q);	//Plus grande masse 2
	DoubleRessort doubleressort8 (0.25,0.33,0.01,0.43,0.45,0.12,a,P,Q);	//Plus faible masse 2
	DoubleRessort doubleressort9 (0.25,0.33,0.44,1,0.45,0.12,a,P,Q);	//Plus grand k2 
	DoubleRessort doubleressort10(0.25,0.33,0.44,0.01,0.45,0.12,a,P,Q);	//Plus faible k2 
	DoubleRessort doubleressort11(0.25,0.33,0.44,0.43,1,0.12,a,P,Q);	//Plus grand k3 
	DoubleRessort doubleressort12(0.25,0.33,0.44,0.43,0.01,0.12,a,P,Q);	//Plus faible k3 
	DoubleRessort doubleressort13(0.25,0.33,0.44,0.43,0.45,1,a,P,Q);	//Plus de frottement
	DoubleRessort doubleressort14(0.25,0.33,0.44,0.43,0.45,0.01,a,P,Q);	//Peu de frottement
	DoubleRessort doubleressort15(0.25,0.33,0.44,0.43,0.45,0.12,a,P,Q1);//Vitesse de depart plus elevee
	cout<<"Double ressort 3(Plus grande masse 1)"<<endl<<doubleressort3;
	doubleressort3.testevolution(0.1,1);
	cout<<"Double ressort 4(Plus petite masse 1): "<<endl<<doubleressort4;
	doubleressort4.testevolution(0.1,1);
	cout<<"Double ressort 5(Plus grand k1): "<<endl<<doubleressort5;
	doubleressort5.testevolution(0.1,1);
	cout<<"Double ressort 6(Plus faible k1): "<<endl<<doubleressort6;
	doubleressort6.testevolution(0.1,1);
	cout<<"ressort 7(Plus grande masse 2): "<<endl<<doubleressort7;
	doubleressort7.testevolution(0.1,1);
	cout<<"Double ressort 8(Plus faible masse 2): "<<endl<<doubleressort8;
	doubleressort8.testevolution(0.1,1);
	cout<<"Double ressort 9(Plus grand k2 )"<<endl<<doubleressort9;
	doubleressort9.testevolution(0.1,1);
	cout<<"Double ressort 10(Plus faible k2 ): "<<endl<<doubleressort10;
	doubleressort10.testevolution(0.1,1);
	cout<<"Double ressort 11(Plus grand k3 ): "<<endl<<doubleressort11;
	doubleressort11.testevolution(0.1,1);
	cout<<"Double ressort 12(Plus faible k3): "<<endl<<doubleressort12;
	doubleressort12.testevolution(0.1,1);
	cout<<"ressort 13(Plus de frottement): "<<endl<<doubleressort13;
	doubleressort13.testevolution(0.1,1);
	cout<<"Double ressort 14(Peu de frottement): "<<endl<<doubleressort14;
	doubleressort14.testevolution(0.1,1);
	cout<<"ressort 15(Vitesse de depart plus elevee): "<<endl<<doubleressort15;
	doubleressort15.testevolution(0.1,1);
	//Test exception
	Vecteur P1(2,1);
	Vecteur Q2(1,2,3);
	Vecteur P2(1);
	try{
		DoubleRessort(0.25,0.33,0.44,0.43,0.45,0.12,a,P1,Q2);
	}
	catch( string erreur){
		cerr<<erreur<<endl;
	}
	try{
		DoubleRessort(0.25,0.33,0.44,0.43,0.45,0.12,a,P2,Q2);
	}
		catch(string erreur){
			cerr<<erreur<<endl;
		}
	try{
		DoubleRessort(0.25,0.33,0.44,0.43,0.45,0.12,a,P2,P1);
	}
		catch(string erreur){
			cerr<<erreur<<endl;
		}
	
		
		
	
	int i;
	cin >>i;
	return 0;
}
