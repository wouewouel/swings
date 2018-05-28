#pragma once
#include "Vecteur.h"
#include "Dessinable.h"
#include "support_a_dessin.h"

class Oscillateur:public Dessinable {
				
	protected:
		Vecteur P; //Parametre
	
		Vecteur Q; //Vitesse

        Vecteur Origine;
	
	public:
	


		Oscillateur(double a, double b, double c,                          //Oscillateur de dimension 3
                    double x, double y, double z,SupportADessin* vue=nullptr,
                    double xo=0,double yo=0,double zo=0) :
            Dessinable(vue), P(a,b,c) , Q(x,y,z),Origine(xo,yo,zo) {} // donnes a,b,c à P et x,y,z a Q
		
        Oscillateur(double a,double x,SupportADessin* vue=nullptr,double xo=0,double yo=0,double zo=0):
            Dessinable(vue),P(a),Q(x),Origine(xo,yo,zo) {} //( Oscillateur de dimension 1
		
        Oscillateur(Vecteur P,Vecteur Q,SupportADessin* vue=nullptr, double xo=0,double yo=0,double zo=0):
            Dessinable(vue),P(P),Q(Q),Origine(xo,yo,zo){
            if (P.getcoord().size() !=Q.getcoord().size()){
                throw std::string("Erreur constructeur, vecteurs dimensions différentes");
			}
            };
								
		virtual Vecteur equation_evolution(double t) const;
	
		Vecteur getP() const ;
	
		Vecteur getQ() const ;
		
		void setP(Vecteur const&); 
			
		void setQ(Vecteur const&);
		
        virtual void dessine()const override{}

        void set_support(SupportADessin* const& S) {support=S;}

        virtual double get_O1() const {return Origine.getvalue(0);}
        virtual double get_O2() const {return Origine.getvalue(1);}
        virtual double get_O3() const {return Origine.getvalue(2);}

	
	};
	

		std::ostream& operator<<(std::ostream& sortie, Oscillateur const& O) ;
		
        void affiche_get(Oscillateur const& O, double t); //methode pour tester les methodes get
		
		void affiche_set(Oscillateur& O); //methode pour tester les methodes set
	
	
	
	
