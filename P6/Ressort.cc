#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Ressort.h"
using namespace std;

Vecteur Ressort::equation_evolution(double t)const{ //rendre plus jolie cette fonction plus tard
	Vecteur g(0,0,9.81);
	double scalaire(g*A);
	Vecteur v={'a',scalaire};
	Vecteur evol=(-k/m)*P-(lambda/m)*Q+v;
	return evol;
}

double Ressort::get_m(){return m;}

double Ressort::get_k(){return k;}

double Ressort::get_lambda(){return lambda;}

Vecteur Ressort::get_A(){return A;}
	
std::ostream& operator<<(std::ostream& out,Ressort ressort){
	constexpr int col1(5);
	constexpr int col2(20);
	out<<"##Ressort"<<endl;
	out<<setw(col2)<<"Raideur (k):"<<setw(col1)<<ressort.get_k()<<endl;
	out<<setw(col2)<<"Masse (m):"<<setw(col1)<<ressort.get_m()<<endl;
	out<<setw(col2)<<"Frottement (lambda):"<<setw(col1)<<ressort.get_lambda()<<endl;
	out<<setw(col2)<<"A(vecteur unitaire de l'axe):"<<setw(col1)<<ressort.get_A()<<endl;
	out<<setw(col2)<<"P(vecteur position):"<<setw(col1)<<ressort.getP()<<endl;
	out<<setw(col2)<<"Q(vecteur vitesse):"<<setw(col1)<<ressort.getQ()<<endl;
	
	return out;
}
	
