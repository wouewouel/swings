#include <iostream>
#include <vector>
#include "Oscillateur.h"
using namespace std;

int main ()
{
	//Testconstructeur oscillateur
	
	Oscillateur O(1,2,0, 3,4,0);				//Constructeur oscillateur de dimension 3
	Oscillateur O1(12,34, 23,12);				//Constructeur oscillateur de dimension 2
	Oscillateur O2(1,1);						//Constructeur oscillateur de dimension 1
	
	Vecteur P(1,2);
	Vecteur Q(3,4);
	Oscillateur O3(P,Q);						//Constructeur avec des vecteurs en parametres
	
	Oscillateur O3bis(O3);
	//Test affichage
	
	cout<<"Oscillateur O:"<<endl<<O;
	cout<<"Oscillateur O1:"<<endl<<O1;
	cout<<"Oscillateur O2:"<<endl<<O2;
	cout<<"Oscillateur O3:"<<endl<<O3;
	cout<<"Oscillateur O3bis:"<<endl<<O3bis;
	
	//Test des methodes set et get
	
	affiche_get(O,5);							//Test de get
	affiche_set(O);								//Test de set
		
		Vecteur P2(1);
		Vecteur Q2(1,2);
	
	//Test exception
	try{
		Oscillateur O4(P2,Q2);					//Test erreur avec constructeur
	}
	catch( string erreur){
		cerr<<erreur<<endl;
	}
	Oscillateur O5(1,2);
	try{
		O5.setQ(Q2);							//Test erreur set
	}
	catch( string erreur){
		cerr<<erreur<<endl;
	}
	try{
		O5.setP(Q2);							//Test erreur get
	}
	catch(string erreur){
		cerr<<erreur<<endl;
	}
	cout<<O5;
	int i;
	cin >>i;
	return 0;
} 

