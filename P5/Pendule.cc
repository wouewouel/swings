#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include "Pendule.h"

using namespace std;
double g(9.81);
Vecteur Pendule::equation_evolution(double t){
	Vecteur retour={'a',(-g/L)*sin(P.getvalue(0))-lambda*(Q.getvalue(0))/(m*L*L)};
	return retour;
}

double Pendule::get_m(){return m;}

double Pendule::get_L(){return L;}

double Pendule::get_lambda(){return lambda;}

std::ostream& operator<<(std::ostream& out,Pendule pendule){
	constexpr int col1(5);
	constexpr int col2(20);
	out<<"##Pendule"<<endl;
	out<<setw(col2)<<"masse(m):"<<setw(col1)<<pendule.get_m()<<endl;
	out<<setw(col2)<<"Longueur(L):"<<setw(col1)<<pendule.get_L()<<endl;
	out<<setw(col2)<<"Frottement(lambda):"<<setw(col1)<<pendule.get_lambda()<<endl;
	out<<setw(col2)<<"P(vecteur position):"<<setw(col1)<<pendule.getP()<<endl;
	out<<setw(col2)<<"Q(vecteur vitesse):"<<setw(col1)<<pendule.getQ()<<endl;
	return out;
}
