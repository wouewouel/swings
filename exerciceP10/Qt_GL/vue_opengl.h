#ifndef VUEOPENGL_H
#define VUEOPENGL_H

#include <QGLShaderProgram> // Classe qui regroupe les fonctions OpenGL liées aux shaders
#include <QMatrix4x4>
#include "support_a_dessin.h"
#include "glsphere.h"

class VueOpenGL : public SupportADessin {
 public:
  // méthode(s) de dessin (héritée(s) de SupportADessin)
  virtual void dessine(Systeme const& a_dessiner) override;

  // méthodes de (ré-)initialisation
  void init();
  void initializePosition();

  // méthode set
  void setProjection(QMatrix4x4 const& projection)
  { prog.setUniformValue("projection", projection); }

  // Méthodes set
  void translate(double x, double y, double z);
  void rotate(double angle, double dir_x, double dir_y, double dir_z);
  
  //************************************************************************//
  virtual void dessine(Pendule const& P) override;
  virtual void dessine(Ressort const& R) override;
  virtual void dessine(DoubleRessort const& dr) override;
  virtual void dessinePhase(Oscillateur const& O) override;


  //************************************************************************//

  // méthode utilitaire offerte pour simplifier
  void dessineCube(QMatrix4x4 const& point_de_vue = QMatrix4x4() );
  void dessineAxes(QMatrix4x4 const& point_de_vue, bool en_couleur = true);
  void dessineSphere(QMatrix4x4 const& point_de_vue,
                     double rouge = 1.0, double vert = 1.0, double bleu = 1.0);
 private:
  // Un shader OpenGL encapsulé dans une classe Qt
  QGLShaderProgram prog;

  // Caméra
  QMatrix4x4 matrice_vue;

  GLSphere sphere;
};

#endif
