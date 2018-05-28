#include <iostream>
#include <vector>
#include <string>
#include "Vecteur.h"
using namespace std;


int main(){

//Test constructeur 3D

Vecteur vect1(1.0, 2.0, -0.1);				//Un vecteur en 3D 									
																														
Vecteur vect2(2.6, 3.5,  4.1);				//Un autre vecteur en 3D


// Test constructeur de copie

Vecteur vect3(vect1);  						//Copie de V1


//Test surchage operateur

cout << "Vecteur 1 : "<< vect1 << endl; 	//test affichage
cout << "Vecteur 2 : " << vect2 << endl;	//
cout << "Vecteur 3 : " << vect3 << endl;	//

cout << "Le vecteur 1 est ";
if (vect1 == vect2) {						//Test operateur comparaison
    cout << "egal au";
} else {
    cout << "different du";
}
cout << " vecteur 2," << endl << " et est ";
if (vect1 != vect3) {						//Test operateur difference
    cout << "different du";
} else {
    cout << "egal au";
}
cout << " vecteur 3. \n" << endl;

cout<<"vect1^vect2= "<<(vect1^vect2)<<endl;	//Test produit vectoriel
cout<<"vect2^vect1= "<<(vect2^vect1)<<endl; //
cout<<"vect1+vect2= "<<vect1+vect2<<endl; 	//Test operateur addition
cout<<"vect2=vect1= "<<vect2+vect1<<endl; 	//
cout<<"vect1-vect2 ="<<vect1-vect2<<endl;	//Test operateur soustraction
cout<<"vect2-vect1= "<<vect2-vect1<<endl;	//
cout<<"-vect1 ="<<-vect1<<endl; 			//Test oppose
cout<<"vect1*6= "<<vect1*6<<endl;			//Test multiplication scalaire a droite
cout<<"6*vect1= "<<6*vect1<<endl;			//Test multiplication scalaire a gauche
cout<<"vect1*vect2= "<<vect1*vect2<<endl;	//Test produit scalaire
cout<<"vect2*vect1= "<<vect2*vect1<<endl; 	//
cout<<vect1<<vect2<<vect3;					//Les vecteurs ne sont pas modifies


//Test Constructeur a une dimension

Vecteur v(1); 								
Vecteur v2(0);			
cout<<"v+v2= "<<v+v2<<endl;
cout<<v<<endl;


//Test constructeur a deux dimensions

Vecteur vect4(1,2);
cout<<vect4<<endl;


//Test de constructeur par defaut

Vecteur v3;


//Test de set_coord

v3.set_coord(1,2); 							
cout<<"v3= "<<v3<<endl;


//Test de augmente
v3.augmente(4);
cout<<"v3= "<<v3<<endl;

//Test de getvalue
v3.getvalue(1);
cout<<"v3= "<<v3<<endl;


//Test norme

cout<<"v3= "<<v3<<endl;
cout<<"norme de v3= "<<v3.norme()<<endl;
cout<<"norme de v3 au carre= "<<v3.norme2()<<endl<<endl;


//Test normalise

Vecteur v4(1,2,3);
cout<<"Version normalisee de v4"<<v4.normalise()<<endl;					
cout<<"v4= "<<v4<<endl;						//v4 n'est pas modifie

//Test des exceptions
Vecteur v5;
cout<<v5<<endl;
try{
	cout<<v5.normalise();						//Test erreur normalise
}
catch(string erreur){
	cerr<<erreur<<endl;
}
Vecteur v6(4,5,6);
Vecteur v7(2,3);
try{
v6.set_coord(4,3);							//Test de l'erreur Err_segm_fault
}
catch (string erreur){
	cerr<<erreur<<endl;
}
try{
	cout<<(v6^v7)<<endl;					//Test de l'erreur Err_3
}
catch (string erreur){
	cerr<<erreur<<endl;
}
try{
	cout<<v6+v7<<endl;						//Test de l'erreur Err_dim
}
	catch(string erreur){
		cerr<<erreur;
	}
int i; //revoir pas mal d'erreur
cin >>i;
}
