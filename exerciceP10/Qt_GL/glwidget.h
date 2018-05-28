#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>        // Classe pour faire une fenêtre OpenGL
#include <QTime>            // Classe pour gérer le temps
#include "vue_opengl.h"
#include "Systeme.h"
#include "Integrateur.h"
#include "Ressort.h"
#include "Pendule.h"
#include "DoubleRessort.h"


class GLWidget : public QGLWidget

{
public:
  GLWidget(Integrateur& I,QWidget* parent = nullptr, bool dessine_normal=true, size_t index=0)
    : QGLWidget(parent) , c(&vue, I), dessine_normal(dessine_normal),index(index) {

      Vecteur a2(0.8,0,0.6);
      Vecteur P2(0.18);
      Vecteur Q2(0);
      Vecteur P3(-1,1);
      Vecteur Q3(0.12,0.11);

      Oscillateur* r1(new Ressort(0.25,0.33,0.05,a2,P2,Q2,&vue));           // Après l'argument qui appellent le support à dessin
      Oscillateur* p1(new Pendule(1,1,0.05,M_PI/2,0,&vue));                 // on peut changer les coordonnées de l'origine pour chaque
      Oscillateur* dr(new DoubleRessort(1,2,1,2,0.2,0.001,a2,P3,Q3,&vue));  // oscillateur afin qu'ils ne soient pas tous au même
                                                                            // endroit

     c.ajoute(r1);
     c.ajoute(p1);
     c.ajoute(dr);

      //C'est ici qu'on initialise le système (ça ne marche pas si on le met dans init()...

  }

  virtual ~GLWidget() {}

private:
  // Les 3 méthodes clés de la classe QGLWidget à réimplémenter
  virtual void initializeGL()                  override;
  virtual void resizeGL(int width, int height) override;
  virtual void paintGL()                       override;

  // Méthodes de gestion d'évènements
  virtual void keyPressEvent(QKeyEvent* event) override;
  virtual void timerEvent(QTimerEvent* event)  override;
  virtual void mousePressEvent(QMouseEvent* event) override;
  virtual void mouseMoveEvent(QMouseEvent* event)  override;

  // Méthodes de gestion interne
  void pause();

  // Vue : ce qu'il faut donner au contenu pour qu'il puisse se dessiner sur la vue
  VueOpenGL vue;

  // position de la souris
  QPointF lastMousePosition;

  // Timer
  int timerId;
  // pour faire évoluer les objets avec le bon "dt"
  QTime chronometre;

  // objets à dessiner, faire évoluer
  Systeme c;

  // précise si on dessine le système ou le portrait de phase
  bool dessine_normal;

  // précise le portrait de phase du i-ème oscillateur à afficher si dessine_normal est false
  size_t index;
};

#endif // GLWIDGET_H
