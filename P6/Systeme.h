#pragma once
#include <vector>
#include "Oscillateur.h"
#include "Dessinable.h"
#include <memory>
class Systeme : public Dessinable{
	
	private:
		std::vector <std::unique_ptr<Oscillateur>>systeme;
	public:
		void ajoute(Oscillateur* o);
		
		virtual void dessine()const override;
			
		void evolue(double t);
};
