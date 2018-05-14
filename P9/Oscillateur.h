#pragma once
#include "Vecteur.h"
#include "Dessinable.h"


class Oscillateur:public Dessinable {
				
	protected:
		Vecteur P; //Parametre
	
		Vecteur Q; //Vitesse
	
	public:
	
		
		Oscillateur(double a, double b, double c,double x, double y, double z,SupportADessin* vue=nullptr):	//Oscillateur de dimension 3
		Dessinable(vue), P(a,b,c) , Q(x,y,z) {} 
		
		Oscillateur(double a,double x,SupportADessin* vue=nullptr): Dessinable(vue),P(a),Q(x){}				//Oscillateur de dimension 1
		
		Oscillateur(Vecteur P,Vecteur Q,SupportADessin* vue=nullptr):Dessinable(vue),P(P),Q(Q){				//Oscillateur de dimension quelconque
			if (!(P.dimension_ok(Q))){
				Vecteur nul;
				P=nul;
				Q=nul;
			}
			};//revoir plus tard pour etre sur que dimP=dimQ
								
		virtual Vecteur equation_evolution(double t) const;
	
		Vecteur getP() const ;					//Retourne P
	
		Vecteur getQ() const ;					//Retourne Q
		
		void setP(Vecteur const&); 				//Modifie P
			
		void setQ(Vecteur const&);				//Modifie Q
		
		virtual void dessine()const override{}	//Dessine un oscillateur
		
	
	};
	

		std::ostream& operator<<(std::ostream& sortie, Oscillateur const& O);	//Surchage operateur affichage
		
		void affiche_get(Oscillateur const& O,double t); 						//methode pour tester les methodes get
		
		void affiche_set(Oscillateur& O);								 		//methode pour tester les methodes set
	
	
	
	
