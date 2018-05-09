#include <iostream>
#include <string>
#include <iomanip>
#include "DoubleRessort.h"
using namespace std;

	
void DoubleRessort::affiche(std::ostream& out)const{
	constexpr int col1(5);
	constexpr int col2(20);
	out<<"##DoubleRessort"<<endl;
	out<<setw(col2)<<"Raideur (k1):"<<setw(col1)<<k1<<endl;
	out<<setw(col2)<<"Masse (m1):"<<setw(col1)<<m1<<endl;
	out<<setw(col2)<<"Raideur (k2):"<<setw(col1)<<k2<<endl;
	out<<setw(col2)<<"Masse (m2):"<<setw(col1)<<m2<<endl;
	out<<setw(col2)<<"Raideur (k3):"<<setw(col1)<<k3<<endl;
	out<<setw(col2)<<"Frottement (lambda):"<<setw(col1)<<lambda<<endl<<endl;
	out<<setw(col2)<<"A(vecteur unitaire de l'axe):"<<setw(col1)<<A<<endl;
	out<<setw(col2)<<"P(vecteur position):"<<setw(col1)<<P<<endl;
	out<<setw(col2)<<"Q(vecteur vitesse):"<<setw(col1)<<Q<<endl;
}

Vecteur DoubleRessort::equation_evolution(double t)const {
	Vecteur retour(2);
	retour.set_coord(1,(-lambda/m1)*getQ().getvalue(0)-((k1+k3)/m1)*getP().getvalue(0)+(k3/m1)*getP().getvalue(1));
	retour.set_coord(2,(-lambda/m2)*getQ().getvalue(1)-((k2+k3)/m2)*getP().getvalue(1)+(k3/m2)*getP().getvalue(0));
	return retour;
};
	

void DoubleRessort::testevolution(double dt,double tfinal){//voir si on met un integrateur en parametre pour choisir
	IntegrateurEulerCromer integrateur;                    //l'integration
	for(double t(0);t<=tfinal;t+=dt){
		cout<<endl<<"t= "<<t<<endl;
		cout<<"#Parametre "<<P<<endl;
		cout<<"#Vitesse "<<Q<<endl;
		integrateur.integre(*this,t,dt);
	}
}

ostream& operator<<(ostream& out,DoubleRessort const& doubleressort){
	doubleressort.affiche(out);
	return out;
}
