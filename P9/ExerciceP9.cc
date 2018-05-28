#include <iostream>
#include "TextViewer.h"
#include "Ressort.h"
#include "DoubleRessort.h"
#include "Pendule.h"
#include "Systeme.h"
#include "Integrateur.h"
#include "constantes.h"
#include "SupportADessin.h"
#include <cmath>



using namespace std;

int main ()
{
		SupportADessin* text(new TextViewer(cout));
		//Test systeme avec Euler Cromer
		Vecteur a1(1,0,0);
		Vecteur P1(1.0);
		Vecteur Q1(1.0);
		Oscillateur* r1(new Ressort(4,2,1,a1,P1,Q1,text));
		Oscillateur* p1(new Pendule(5,2,1,5,8,text));
		IntegrateurEulerCromer integrateur;
		Systeme s(text,integrateur);
		
		//Test ajoute
		
		s.ajoute(r1);													//Pour un ressort
		s.ajoute(p1);													//Pour un pendule
		
		//Test dessine
		cout<<"Test dessin:"<<endl;
		cout<<1;
		r1->dessine();													//Pour un ressort
		cout<<2;
		//p1->dessine();													//Pour un pendule
		cout<<3;
		//s.dessine();													//Pour un systeme
		
		//Test evolue
		cout<<"Test evolue:"<<endl<<endl;
		s.evolue(5,0.2);
		s.dessine();
		
		
		//Test systeme avec Newmarck
		IntegrateurNewmark integrateur2;
		Systeme s2(text,integrateur2);
		Vecteur a2(0.8,0,0.6);
 		Vecteur P2(0.18);
 		Vecteur Q2(0.0);
		Vecteur P3(0.14,0.13);
		Vecteur Q3(0.12,0.11);
		
 		Oscillateur* ressort2(new Ressort(0.25,0.33,0.15,a2,P2,Q2,text));
 		Oscillateur* pendule2(new Pendule(1,1,0,M_PI/2,0,text));
		Oscillateur* doubleressort(new DoubleRessort(1,1,1,1,1,1,a2,P3,Q3,text));
 		
 		
 		//Test ajoute
 		s2.ajoute(ressort2);
 		s2.ajoute(pendule2);
		s2.ajoute(doubleressort);										//Pour un double ressort
 		
 		
 		//Test dessine	
 		cout<<"Test dessin:"<<endl<<endl;								
 		doubleressort->dessine();										//Pour un double ressort
 		cout<<"Systeme 2:"<<endl<<endl;
 		double dt(0.01);
 		for(double t(0);t<=0.03;t+=dt){
 			cout<<"t= "<<t<<endl<<endl;
			s2.dessine();
			s2.evolue(t,dt);
		}
		
		//Test Phase
            cout<<"##Test Portrait de phase :"<<endl<<endl;
            for(double t(0);t<=0.07;t+=dt){
                text->dessinePhase(*ressort2);
                s2.evolue(t,dt);
        }
		delete text;
		
		return 0;
}
