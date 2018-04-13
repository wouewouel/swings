#pragma once
#include "SupportADessin.h"
class Dessinable{
	private:
		SupportADessin support;
	public:
		  virtual void dessine() override;
	};
