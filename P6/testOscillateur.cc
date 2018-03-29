#include <iostream>
#include <vector>
#include <string>
#include "Oscillateur.h"
using namespace std;

void affiche_get(Oscillateur const& O, size_t const& t) {
	  cout <<" Tests de get() : \n   de son parametre : " 
		   << O.getP()        << "   de sa vitesse    : "
		   << O.getQ() 		  << endl;
	  cout <<" Sa fonction d'evolution donne pour t = "
		   << t << " : " << O.equation_evolution(t) << endl;
   }
   
void affiche_set(Oscillateur& O) {
	  O.setP(Vecteur (-2, -1, 0)); 
	  cout <<" Tests de set() : \n   de son parametre : " 
		   << O.getP()        
		   << "   donne : " << endl
		   << O;
		   
	  O.setQ(Vecteur (-6, 12, 0)); 
	  cout  << "   de sa vitesse    : " 
		    <<O.getQ()
		    << "   donne : " << endl		
		    << O 		     << endl;
   }

int main ()
{

	Oscillateur O(1,2,0, 3,4,0);
	cout << O;
	size_t t(5);
	
	affiche_get(O,t);
	
	affiche_set(O);
	int i;
	cin >>i;
	return 0;
} 

