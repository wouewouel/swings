#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include "Pendule.h"

using namespace std;
double g(9.81);
Vecteur Pendule::equation_evolution(double t)const{
	Vecteur retour={"a",(-g/L)*sin(P.getvalue(0))-lambda*(Q.getvalue(0))/(m*L*L)};
	return retour;
}
void Pendule::affiche(ostream& out){
	constexpr int col1(5);
	constexpr int col2(20);
	out<<"##Pendule"<<endl;
	out<<setw(col2)<<"masse(m):"<<setw(col1)<<m<<endl;
	out<<setw(col2)<<"Longueur(L):"<<setw(col1)<<L<<endl;
	out<<setw(col2)<<"Frottement(lambda):"<<setw(col1)<<lambda<<endl<<endl;
	out<<setw(col2)<<"P(vecteur position):"<<setw(col1)<<P<<endl;
	out<<setw(col2)<<"Q(vecteur vitesse):"<<setw(col1)<<Q<<endl;
}

void Pendule::testevolution(double dt,double tfinal){
	IntegrateurEulerCromer integrateur;
	for(double t(0);t<=tfinal;t+=dt){
		cout<<endl<<"t= "<<t<<endl;
		cout<<"#Parametre "<<P<<endl;
		cout<<"#Vitesse "<<Q<<endl;
		integrateur.integre(*this,t,dt);
	}
}

std::ostream& operator<<(std::ostream& out,Pendule pendule){
	pendule.affiche(out);
	return out;
}
