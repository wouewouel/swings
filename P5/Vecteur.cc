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
	
	vector <double> Vecteur::getcoord() const { //on renvoie toutes les coordonnées d'un objet de la classe Vecteur
			return coordonnees;
			}
			
	double Vecteur::getvalue(size_t i) const { //on renvoie la coordonnées numero i d'un objet de la classe Vecteur
			return coordonnees[i];
			}	
				
	
		
		
	double Vecteur::norme2() const { //on utilise norme2 pour faciliter le calcul de la norme
			double result(0);
			for (auto value : coordonnees){
				result += pow(value,2);
				}
			return result;
			} 			
		
	double Vecteur::norme() const {
			return sqrt(norme2());
			}
	Vecteur Vecteur::normalise(){
		->this*=1/(->this.norme());
		return ->this;
	}
	//Surchage operateurs
	//===============================================================================================
	Vecteur& Vecteur::operator+=(const Vecteur& autre) { //addition
			if(dimension_ok(autre)){
				for(size_t i(0); i < coordonnees.size() ; ++i){
					coordonnees[i]+=autre.getvalue(i);
					}
				}
			return *this;
			}
	
	Vecteur& Vecteur::operator-=(const Vecteur& autre) { //soustraction
			if(dimension_ok(autre)){
				for(size_t i(0); i < coordonnees.size() ; ++i){
					coordonnees[i]-=autre.getvalue(i);
					}
				}
			return *this;
			}
			
	Vecteur Vecteur::operator-(){ //oppose
		Vecteur v(0);
		for(size_t i(0); i < coordonnees.size() ; ++i){
			v.augmente(coordonnees[i]);
		}
		return v;
	}
	Vecteur& Vecteur::operator*=(double scalaire){	//multiplication scalaire
		for(size_t i(0); i < coordonnees.size() ; ++i){
					coordonnees[i]*=scalaire;
					}
			return *this;			
		}
	
	double Vecteur::operator*(Vecteur autre){ //produit scalaire
		double result(0);
			if(dimension_ok(autre)){
				for(size_t i(0); i < coordonnees.size() ; ++i){
					result += (autre.getvalue(i) * coordonnees[i]);
					}
				}
			return result;			
			}
	
	Vecteur Vecteur::operator^(const Vecteur& autre){ //renvoie le produit vectoriel
		Vecteur result(0);
			if (dimension_ok(autre) and dimension_3(autre)){
					result.augmente(coordonnees[1]*autre.getvalue(2)-coordonnees[2]*autre.getvalue(1)); //(U2*V3 - U3*V2)
					result.augmente(coordonnees[2]*autre.getvalue(0)-coordonnees[0]*autre.getvalue(2)); //(U3*V1 - U1*V3)
					result.augmente(coordonnees[0]*autre.getvalue(1)-coordonnees[1]*autre.getvalue(0)); //(U1*V2 - U2*V1)
				}
			return result;
			}
	
	bool Vecteur:: operator==(Vecteur autre){ // operateur comparaison egal
		if (not(dimension_ok(autre))){return false;}
			for(size_t i(0); i < coordonnees.size() ; ++i){
				if(coordonnees[i] != (autre.getcoord())[i]){
					return false;
					}
				}
		return true;
			}
	bool Vecteur::operator!=(Vecteur autre){ //operateur comparaison different
		if (not(dimension_ok(autre))){return true;}
			for(size_t i(0); i < coordonnees.size() ; ++i){
				if(coordonnees[i] != (autre.getcoord())[i]){
					return true;
					}
				}
		return false;
			}
		
	
	ostream& operator<<(ostream& out,Vecteur vect){ //operateur affichage
		out<<"(";
		for(size_t i(0);i<vect.getcoord().size()-1;++i){
			cout<<vect.getvalue(i)<<"; ";
		}
		out<<vect.getvalue(vect.getcoord().size()-1)<<")"<<endl;
		return out;
	}
	
	const Vecteur operator+(Vecteur v,Vecteur const& autre){ // operateur addition
		v+=autre;
		return v;
	}
	
	const Vecteur operator-(Vecteur v,Vecteur const& autre){ // operateur soustraction
		v-=autre;
		return v;
	}
	
	const Vecteur operator*(Vecteur v,double scalaire){ //multiplication scalaire a gauche
		v*=scalaire;
		return v;
	}
	
	const Vecteur operator*(double scalaire,Vecteur v){ //multiplication scalaire a droite
		v*=scalaire;
		return v;
	}
		
	//===============================================================================================
	
 

