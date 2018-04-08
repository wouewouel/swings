#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "Vecteur.h"
using namespace std;


int main()
{
	// un vecteur en 3D :
Vecteur vect1(1.0, 2.0, -0.1);

// un autre vecteur en 3D
Vecteur vect2(2.6, 3.5,  4.1);

Vecteur vect3(vect1);  // copie de V1
Vecteur vect4(4);      // le vecteur nul en 4D

cout << "Vecteur 1 : "<< vect1 << endl;
cout << "Vecteur 2 : " << vect2 << endl;
cout << "Vecteur 3 : " << vect3 << endl;
cout << "Vecteur 4 : " << vect4 << endl;

cout << "Le vecteur 1 est ";
if (vect1 == vect2) {
    cout << "egal au";
} else {
    cout << "different du";
}
cout << " vecteur 2," << endl << " et est ";
if (vect1 != vect3) {
    cout << "different du";
} else {
    cout << "egal au";
}
cout << " vecteur 3. \n" << endl;

cout << "Le vecteur 1 est ";
try {
	if (vect1 == vect4) {
		cout << "egal au";
	} else {
		cout << "different du";
		} 
	cout << "vecteur 4";
	}
catch(string err){
	cerr <<"incompatible avec l'operation == car erreur : \n"
		 << err << endl << endl;
	}

cout<<"(vect1^vect2) ="<<(vect1^vect2)<<endl;
cout<<"(vect2^vect1) ="<<(vect2^vect1)<<endl;
cout<<"vect1+vect2 ="<<vect1+vect2<<endl;
cout<<"vect2+vect1 ="<<vect2+vect1<<endl;
cout<<"vect1-vect2 ="<<vect1-vect2<<endl;
cout<<"vect2-vect1 ="<<vect2-vect1<<endl;
cout<<"-vect1 ="<<-vect1<<endl;
cout<<"vect1*6 ="<<vect1*6<<endl;
cout<<"6*vect1 ="<<6*vect1<<endl;
cout<<"vect1*vect2 ="<<vect1*vect2<<endl;
cout<<"vect2*vect1 ="<<vect2*vect1<<endl;

}
