#include <QApplication>
#include "glwidget.h"
#include "Integrateur.h"

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
  Integrateur* I(new IntegrateurEulerCromer());
  GLWidget w(I);
  w.show();

  return a.exec();
}
