#include <iostream>
#include <vector>
#include <string>
#include "Vecteur.h"
using namespace std;


int main(){
//Un vecteur en 3D :
Vecteur vect1(1.0, 2.0, -0.1);

//Un autre vecteur en 3D:
Vecteur vect2(2.6, 3.5,  4.1);

Vecteur vect3(vect1);  		//Copie de V1
//Vecteur vect4(4);    		// le vecteur nul en 4D(en fait non)

cout << "Vecteur 1 : "<< vect1 << endl; //test affichage
cout << "Vecteur 2 : " << vect2 << endl;//
cout << "Vecteur 3 : " << vect3 << endl;//
//cout << "Vecteur 4 : " << vect4 << endl;//

cout << "Le vecteur 1 est ";
if (vect1 == vect2) {		//Test operateur comparaison
    cout << "egal au";
} else {
    cout << "different du";
}
cout << " vecteur 2," << endl << " et est ";
if (vect1 != vect3) {		//Test operateur difference
    cout << "different du";
} else {
    cout << "egal au";
}
cout << " vecteur 3. \n" << endl;
//try {
//	if (vect1 == vect4) {
//		cout << "egal au";
//	} else {
//		cout << "different du";
//		} 
//	cout << "vecteur 4";
//	}
//catch(string err){
//	cerr <<"vect1 et vect4 incompatibles avec l'operation == car erreur : \n"
//		 << err << endl << endl;
//	}
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
Vecteur v(1); 								//Test vecteur a une dimension
Vecteur v2(0);			
cout<<"v+v2= "<<v+v2<<endl;
Vecteur v3;
v3.set_coord(1,2); 							//Test de set_coord
cout<<"v3= "<<v3<<endl;
Vecteur v4(1,2,3);
cout<<v4.normalise()<<endl;					//Test normalise
cout<<v4;									//v4 n'est pas modifie


int i; //revoir pas mal d erreur
cin >>i;
}
