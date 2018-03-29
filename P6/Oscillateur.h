#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Vecteur.h"


class Oscillateur {
				
	private:
		Vecteur P;
	
		Vecteur Q;
	
	public:
	
		Oscillateur(unsigned int n) :  P(n), Q(n) {} //	Constructeur qui intitialise P et Q à des vect de n dim de 0
		Oscillateur() :  Oscillateur(1) {}
		Oscillateur(double a, double b, double c, 
					double x, double y, double z) : P(a,b,c) , Q(x,y,z) {} // donnes a,b,c a P et x,y,z a Q
								
		Vecteur equation_evolution(double t) const;
	
		Vecteur getP() const ;
	
		Vecteur getQ() const ;
		
		void setP(Vecteur const&); 
			
		void setQ(Vecteur const&);
	
	};
	

		std::ostream& operator<<(std::ostream& sortie, Oscillateur const& O) ;
	
	
	
	
