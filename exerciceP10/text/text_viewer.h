#ifndef TEXT_VIEWER_H
#define TEXT_VIEWER_H

#include <iostream>
#include "support_a_dessin.h"


class TextViewer : public SupportADessin {
 public:
 TextViewer(std::ostream& flot)
    : flot(flot)
  {}
  virtual ~TextViewer() {}

  virtual void dessine(Pendule const& p) override;
  virtual void dessine(Ressort const& r) override;
  virtual void dessine(Systeme const& a_dessiner) override;
  virtual void dessine(DoubleRessort const& dr) override;
  virtual void dessinePhase(Oscillateur const& O) override;


 private:
  std::ostream& flot;
};

#endif
