
#include <vector>
#include <string>
#include <cmath>
#pragma once


class Vecteur{
	private:
	
		std::vector<double> coordonnees;
		
		bool dimension_ok(Vecteur autre) const; // On teste ici si les dimensions sont bonnes
			
			
		bool dimension_3(Vecteur autre) const; //on teste ici si les deux vecteurs sont de dimensions 3
			
	public:
	
		void augmente(double new_dim);
		
		void set_coord(size_t dim, double modif);
		
		void affiche() const ;
		
		bool compare(Vecteur autre) const ;
		
		std::vector <double> getcoord() const ; //on renvoie toutes les coordonnées d'un objet de la classe Vecteur
			
		double getvalue(size_t i) const ; //on renvoie la coordonnées numero i d'un objet de la classe Vecteur
			
		Vecteur addition(const Vecteur& autre) const ;
			
		Vecteur soustraction(const Vecteur& autre) const ; //on fait vecteur actuel - autre
			
		Vecteur oppose() const ;
			
		Vecteur mult(double scalaire) const ;
			
		double prod_scal(Vecteur autre) const ;
	
		Vecteur prod_vect(Vecteur autre) const ;
		
			//on utilise norme2 pour faciliter norme
		double norme2() const ;
		
		double norme() const ;
	};
