#include <iostream>
#include <string>
#include <iomanip>
#include "Ressort.h"
using namespace std;

	void Ressort::affiche(std::ostream& out)const{						//Methode affichage des attributs du double ressort
		constexpr int col1(5);
		constexpr int col2(20);
		out<<"##Ressort"<<endl;
		out<<setw(col2)<<"Raideur (k):"<<setw(col1)<<k<<endl;
		out<<setw(col2)<<"Masse (m):"<<setw(col1)<<m<<endl;
		out<<setw(col2)<<"Frottement (lambda):"<<setw(col1)<<lambda<<endl<<endl;
		out<<setw(col2)<<"A(vecteur unitaire de l'axe):"<<setw(col1)<<A<<endl;
		out<<setw(col2)<<"P(vecteur position):"<<setw(col1)<<P<<endl;
		out<<setw(col2)<<"Q(vecteur vitesse):"<<setw(col1)<<Q<<endl;
	}

	Vecteur Ressort::equation_evolution(double t)const{					//Fonction qui renvoie le vecteur de l'equation d'evolution
		Vecteur g(0,0,-9.81);
		Vecteur v={g*A};
		Vecteur evol=-(k/m)*P-(lambda/m)*Q+v;
		return evol;
	}

	
	void Ressort::testevolution(double dt,double tfinal){				//Fonction qui teste l'equation d'evolution
		IntegrateurEulerCromer integrateur;
		for(double t(0);t<=tfinal;t+=dt){
			cout<<endl<<"t= "<<t<<endl;
			cout<<"#Parametre "<<P<<endl;
			cout<<"#Vitesse "<<Q<<endl;
			integrateur.integre(*this,t,dt);
		}
	}
		
	std::ostream& operator<<(std::ostream& out,Ressort const& ressort){	//Surchage operateur affichage
		ressort.affiche(out);
		return out;
	}
		
