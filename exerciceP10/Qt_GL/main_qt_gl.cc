#include <QApplication>
#include "glwidget.h"
#include "Integrateur.h"

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
  IntegrateurEulerCromer I;     // on utilise une référence pour mettre l'integrateur dans le systeme
  GLWidget w(I);
  w.show();

  return a.exec();
}
