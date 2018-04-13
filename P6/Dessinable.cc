#include <iostream>
#include "SupportADessin.h"
#include "Dessinable.h"
using namespace std;



	virtual void Dessinable:: dessine() override {
			  support->dessine(*this); 
			  }
			  
