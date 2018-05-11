#pragma once
#include "Vecteur.h"
#include "Dessinable.h"


class Oscillateur:public Dessinable {
				
	protected:
		Vecteur P; //Parametre
	
		Vecteur Q; //Vitesse
	
	public:
	
		
		Oscillateur(double a, double b, double c,                          //Oscillateur de dimension 3
					double x, double y, double z,SupportADessin* vue=nullptr) :Dessinable(vue), P(a,b,c) , Q(x,y,z) {} // donnes a,b,c a P et x,y,z a Q
		
		Oscillateur(double a,double x,SupportADessin* vue=nullptr): Dessinable(vue),P(a),Q(x){} // Oscillateur de dimension 1 ( a corriger plus tard)
		
		Oscillateur(Vecteur P,Vecteur Q,SupportADessin* vue=nullptr):Dessinable(vue),P(P),Q(Q){
			if (!(P.dimension_ok(Q))){
				Vecteur nul;
				P=nul;
				Q=nul;
			}
			};//revoir plus tard pour etre sur que dimP=dimQ
								
		virtual Vecteur equation_evolution(double t) const;
	
		Vecteur getP() const ;
	
		Vecteur getQ() const ;
		
		void setP(Vecteur const&); 
			
		void setQ(Vecteur const&);
		
		virtual void dessine()const override{}
		
	
	};
	

		std::ostream& operator<<(std::ostream& sortie, Oscillateur const& O) ;
		
		void affiche_get(Oscillateur const& O, size_t const& t); //methode pour tester les methodes get
		
		void affiche_set(Oscillateur& O); //methode pour tester les methodes set
	
	
	
	
