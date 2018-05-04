#include <iostream>
#include "text_viewer.h"
#include "Ressort.h"
#include "Pendule.h"
#include "Systeme.h"
#include "Integrateur.h"
#include "constantes.h"
#include "support_a_dessin.h"
#include <cmath>



using namespace std;

int main ()
{
        SupportADessin* text(new TextViewer(cout));
		
		Vecteur a1(1,0,0);
        Vecteur P1(1);
        Vecteur Q1(1);
		Oscillateur* r1(new Ressort(4,2,1,a1,P1,Q1,text));
		Oscillateur* p1(new Pendule(5,2,1,5,8,text));
        IntegrateurEulerCromer integrateur;
        Systeme s(text,integrateur);

        s.ajoute(r1);
        s.ajoute(p1);
        r1->dessine();
        p1->dessine();

        s.dessine();
        s.evolue(5,0.2);
        s.dessine();
        Systeme s2(text,integrateur);
        Vecteur a2(0.8,0,0.6);
        Vecteur P2(0.18);
        Vecteur Q2(0);
        Oscillateur* ressort2(new Ressort(0.25,0.33,0.15,a2,P2,Q2,text));
        Oscillateur* pendule2(new Pendule(1,1,0,M_PI/2,0,text));
        s2.ajoute(ressort2);
        s2.ajoute(pendule2);
        double dt(0.01);
        for(double t(0);t<=0.03;t+=dt){
            cout<<"t= "<<t<<endl;
            s2.dessine();
            s2.evolue(t,dt);
        }

		return 0;
}
