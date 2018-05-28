#pragma once
#include "Vecteur.h"
#include "Dessinable.h"
#include <string>

class Oscillateur:public Dessinable {
				
	protected:
		Vecteur P; 																							//Parametre
	
		Vecteur Q; 																							//Vitesse
		
		Vecteur Origine;																					//Origine
	
	public:
	
		Oscillateur(double a,double x,SupportADessin* vue=nullptr): Dessinable(vue),P(a),Q(x){}				//Oscillateur de dimension 1
		
		Oscillateur(double a,double b,double c,double d,SupportADessin* vue=nullptr):						//Oscillateur de dimension 2
		Dessinable(vue),P(a,b),Q(c,d){}
		
		Oscillateur(double a, double b, double c,double x, double y, double z,SupportADessin* vue=nullptr):	//Oscillateur de dimension 3
		Dessinable(vue), P(a,b,c) , Q(x,y,z) {} 
		
		Oscillateur(Vecteur P,Vecteur Q,SupportADessin* vue=nullptr,double xo=0,double yo=0,double zo=0):	//Oscillateur de dimension quelconque
		Dessinable(vue),P(P),Q(Q),Origine(xo,yo,zo){				
			if (P.getcoord().size()!=Q.getcoord().size()){
				throw std::string("Erreur constructeur, vecteurs dimensions differentes");
			}
			}//revoir plus tard pour etre sur que dimP=dimQ
								
		virtual Vecteur equation_evolution(double t) const;
	
		Vecteur getP() const ;																				//Retourne P
	
		Vecteur getQ() const ;																				//Retourne Q
		
		void setP(Vecteur const&); 																			//Modifie P
			
		void setQ(Vecteur const&);																			//Modifie Q
		
		virtual void dessine()const override{}																//Dessine un oscillateur
		
		void set_support(SupportADessin* const& S) {support=S;}												//Modifie le support

        virtual double get_O1() const {return Origine.getvalue(0);}
        virtual double get_O2() const {return Origine.getvalue(1);}
        virtual double get_O3() const {return Origine.getvalue(2);}
	
	};
	

		std::ostream& operator<<(std::ostream& sortie, Oscillateur const& O);								//Surchage operateur affichage
		
		void affiche_get(Oscillateur const& O,double t); 													//Methode pour tester les methodes get
		
		void affiche_set(Oscillateur& O);								 									//Methode pour tester les methodes set
	
	
	
	
