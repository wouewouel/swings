#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "Vecteur.h"
using namespace std;


	bool Vecteur::dimension_ok(Vecteur autre) const { // On teste ici si les dimensions sont bonnes
			if(coordonnees.size() == (autre.getcoord()).size() ){
				return true;
			}else {
				string Err_dim("Les deux vecteurs ont des dimensions différentes !");
				throw Err_dim;
				//je ne sais pas si on doit mettre un return false ou pas 
				}
			}
			
	bool Vecteur::dimension_3(Vecteur autre) const { //on teste ici si les deux vecteurs sont de dimensions 3
			if((coordonnees.size() == 3) and (autre.getcoord().size()==3)){
				return true;
			}else {
				string Err_3("Les deux vecteurs ne sont pas de dimensions 3 !");
				throw Err_3;
				//je ne sais pas si on doit mettre un return false ou pas 
				}
			}			
	
	void Vecteur::augmente(double new_dim) {
			coordonnees.push_back (new_dim); 
			}
	void Vecteur::set_coord(size_t dim, double modif){
			if(dim <= coordonnees.size() ){
				coordonnees[dim-1] = modif;
			}else {
				string Err_segm_fault("le vecteur ne possède pas autant de dimension(s) !");
				throw  Err_segm_fault;
				}
			}
	void Vecteur::affiche() const {
			for (auto val : coordonnees){
				cout << val <<" ";
				}
			cout << endl;
			}
	bool Vecteur::compare(Vecteur autre) const {
			if(dimension_ok(autre)){
				for(size_t i(0); i < coordonnees.size() ; ++i){
					if(coordonnees[i] != (autre.getcoord())[i]){
						return false;
						} else {continue;	}
					}
				}
		return true;
			}
	vector <double> Vecteur::getcoord() const { //on renvoie toutes les coordonnées d'un objet de la classe Vecteur
			return coordonnees;
			}
	double Vecteur::getvalue(size_t i) const { //on renvoie la coordonnées numero i d'un objet de la classe Vecteur
			return coordonnees[i];
			}		
			
	Vecteur Vecteur::addition(const Vecteur& autre) const {
			Vecteur result;
			if(dimension_ok(autre)){
				for(size_t i(0); i < coordonnees.size() ; ++i){
					result.augmente(autre.getvalue(i) + coordonnees[i])	;
					}
				}
			return result;
			}
			
	Vecteur Vecteur::soustraction(const Vecteur& autre) const { //on fait vecteur actuel - autre
			Vecteur result;
			if(dimension_ok(autre)){
				for(size_t i(0); i < coordonnees.size() ; ++i){
					result.augmente(coordonnees[i] - autre.getvalue(i))	;
					}

				}
			return result;
			}
			
	Vecteur Vecteur::oppose() const {
			Vecteur result;
			for(size_t i(0); i < coordonnees.size() ; ++i){
					result.augmente( - coordonnees[i]);
					}
			return result;
			}
			
	Vecteur Vecteur::mult(double scalaire) const {
			Vecteur result;
			for(size_t i(0); i < coordonnees.size() ; ++i){
					result.augmente(scalaire * coordonnees[i]);
					}
			return result;			
			}
			
	double Vecteur::prod_scal(Vecteur autre) const {
			double result(0);
			if(dimension_ok(autre)){
				for(size_t i(0); i < coordonnees.size() ; ++i){
					result += (autre.getvalue(i) * coordonnees[i]);
					}
				}
			return result;			
			}
	
	Vecteur Vecteur::prod_vect(Vecteur autre) const {
			Vecteur result;
			if (dimension_ok(autre) and dimension_3(autre)){
					result.augmente(coordonnees[1]*autre.getvalue(2)-coordonnees[2]*autre.getvalue(1)); //(U2*V3 - U3*V2)
					result.augmente(coordonnees[2]*autre.getvalue(0)-coordonnees[0]*autre.getvalue(2)); //(U3*V1 - U1*V3)
					result.augmente(coordonnees[0]*autre.getvalue(1)-coordonnees[1]*autre.getvalue(0)); //(U1*V2 - U2*V1)
				}
			return result;
			}
		
			//on utilise norme2 pour faciliter norme
	double Vecteur::norme2() const {
			double result(0);
			for (auto value : coordonnees){
				result += pow(value,2);
				}
			return result;
			} 			
		
	double Vecteur::norme() const {
			return sqrt(norme2());
			} 
 

