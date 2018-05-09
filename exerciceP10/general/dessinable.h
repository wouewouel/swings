#pragma once
#include "support_a_dessin.h"

class Dessinable {
 public:
  Dessinable(SupportADessin* support)
    : support(support)
  {}
  virtual ~Dessinable() {}
  virtual void dessine() const  = 0;

 protected:
  /* Nous mettons un pointeur au lieu d'une référence *
   * au cas où l'on voudrait changer de support (non  *
   * implémenté ici), ou même copier un dessinable,   *
   * échanger (swap) deux dessinables, etc.           *
   * Il n'est pas nécessaire d'implémenter une copie  *
   * profonde ici ; c'est bien une copie de surface   *
   * dont nous avons besoin.                          */
  SupportADessin* support;
};

