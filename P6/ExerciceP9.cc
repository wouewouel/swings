#include <iostream>
#include "TextViewer.h"
#include "Ressort.h"
#include "Pendule.h"
#include "Systeme.h"
#include "Integrateur.h"


using namespace std;

int main ()
{
		SupportADessin* text(new(TextViewer));
		Vecteur a(1,0,0);
		Vecteur P1(1,0,1);
		Vecteur Q1(1,2,3);
		//Oscillateur* r1(new(Ressort(4,2,1,a,P1,Q1,text)));
		//Oscillateur* p1(new(Pendule(Pendule(4,2,1,3,4,text))));
		IntegrateurEulerCromer integrateur;
		Systeme s(text,integrateur);
		
		//s.ajoute(r1);
		//s.ajoute(p1);
		//*r1.dessine();
		//*p1.dessine();
		cout<<"salut"<<endl;
		return 0;
}
