#pragma once
#include <vector>

class Vecteur{
	private:
	
		std::vector<double> coordonnees;
				
		bool dimension_3(Vecteur const& autre) const; 	//On teste ici si les deux vecteurs sont de dimensions 3
			
	public:
														
		Vecteur():coordonnees({0}){}; 					//Constructeur vecteur nul
		
		Vecteur(double x):coordonnees({x}){}; 			//Constructeur vecteur dimension 1                                                       
		
		Vecteur(double x,double y):coordonnees({x,y}){};//Constructeur vecteur en dimension 2
		
		Vecteur(double x,double y,double z):coordonnees({x,y,z}){}; 	//Constructeur vecteur R3
		
		bool dimension_ok(Vecteur const& autre) const; 	//On teste ici si les dimensions sont bonnes, public car on l'utilise
														//pour un constructeur d'oscillateur
		
		void augmente(double new_dim);					//On rajoute une dimension
		
		void set_coord(size_t dim, double modif); 		//On modifie la coordonnee indiquee
														//la position indiquee n'est pas celle de C++ ( ne commence pas en 0)
														
		std::vector <double> getcoord() const ;	  		//On renvoie toutes les coordonnées d'un objet de la classe Vecteur
														
		double getvalue(size_t i) const ; 				//On renvoie la coordonnées numero i d'un objet de la classe Vecteur
		
		double norme2() const ;							//On utilise norme2 pour faciliter norme
		
		double norme() const ;							//Norme du vecteur grace a norme2
		
		Vecteur normalise(); 							//Normalise le vecteur
		
		//Surchage operateurs
		//===============================================================================================
		bool operator==(Vecteur const& autre);					//Operateur comparaison egal
		
		bool operator!=(Vecteur const& autre);					//Operateur comparaison different
		
		Vecteur& operator+=(const Vecteur& autre); 				//Addition entre deux vecteurs
		
		Vecteur& operator-=(const Vecteur& autre); 				//Soustraction entre deux vecteurs
		
		const Vecteur operator-()const;							//Renvoie l'oppose du vecteur
			
		Vecteur& operator*=(double scalaire);					//Multiplication scalaire
		
		double operator*(Vecteur autre);						//Produit scalaire
		
		Vecteur operator^(const Vecteur& autre);				//Renvoie le produit vectoriel
	};
		std::ostream& operator <<(std::ostream& out,Vecteur v);	//Operateur affichage
	
		const Vecteur operator+(Vecteur,Vecteur const&);		//Operateur addition
	
		const Vecteur operator-(Vecteur,Vecteur const&);		//Operateur soustraction
	
		const Vecteur operator*(double scalaire,Vecteur v);		//Multiplication scalaire a gauche
	
		const Vecteur operator*(Vecteur v,double scalaire);		//Multiplication scalaire a droite
		//===============================================================================================
