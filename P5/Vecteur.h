
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
		Vecteur(unsigned int dimension=1):coordonnees(dimension,0){}; //constructeur vecteur nul, on mettra une dimension 
		                                                              //egale a 1 si l'utilisateur oublie d'indiquer la dimension
		
		Vecteur(double x,double y,double z):coordonnees({x,y,z}){}; //constructeur vecteur R3
		
		
		Vecteur(const Vecteur& autre):coordonnees(autre.getcoord()){}; //constructeur de copie
		
	
		void augmente(double new_dim);//on rajoute une dimension
		
		void set_coord(size_t dim, double modif);
		
		bool operator==(Vecteur autre);//operateur comparaison egal
		
		bool operator!=(Vecteur autre);//operateur comparaison different
		
		std::vector <double> getcoord() const ; //on renvoie toutes les coordonnées d'un objet de la classe Vecteur
			
		double getvalue(size_t i) const ; //on renvoie la coordonnées numero i d'un objet de la classe Vecteur
		
		Vecteur& operator+=(const Vecteur& autre); //addition entre deux vecteurs
		
		Vecteur& operator-=(const Vecteur& autre); //on fait vecteur actuel - autre
		
		Vecteur operator-();//renvoie l'oppose du vecteur
			
		Vecteur& operator*=(double scalaire);//multiplication scalaire
		
		double operator*(Vecteur autre);//produit scalaire
		
		Vecteur operator^(const Vecteur& autre);//renvoie le produit vectoriel
			
		double norme2() const ;//on utilise norme2 pour faciliter norme
		
		double norme() const ;
	};
	std::ostream& operator <<(std::ostream& out,Vecteur v);
	
	const Vecteur operator+(Vecteur,Vecteur const&);
	
	const Vecteur operator-(Vecteur,Vecteur const&);
	
	const Vecteur operator*(double scalaire,Vecteur v);
	
	const Vecteur operator*(Vecteur v,double scalaire);