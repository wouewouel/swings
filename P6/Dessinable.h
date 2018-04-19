#pragma once
#include "SupportADessin.h"
class Dessinable{
	protected:
		SupportADessin* support;
	public:
		Dessinable(SupportADessin* support):support(support){}
		
		virtual ~Dessinable(){}
		
		virtual void dessine()const =0;
	};
