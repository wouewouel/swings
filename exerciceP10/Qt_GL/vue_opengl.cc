#include "vue_opengl.h"
#include "vertex_shader.h" // Identifiants Qt de nos différents attributs
#include "Systeme.h"
#include "Pendule.h"
#include "Ressort.h"
#include "DoubleRessort.h"
#include "glsphere.h"

// ======================================================================
void VueOpenGL::dessine(Systeme const& a_dessiner)
{
    prog.setUniformValue("vue_modele", matrice_vue);
    a_dessiner.dessine();
}
//**********************************************************//
void VueOpenGL::dessine(Pendule const& P)  {

    QMatrix4x4 origine;
    origine.translate(P.get_O1(),P.get_O2(),P.get_O3()); // met les coord que t'as dans Doubleressort::Origine
    dessineAxes(origine); // dessine le repère principal

    prog.setUniformValue("vue_modele", matrice_vue*origine);

  QMatrix4x4 matrice;

glBegin(GL_LINES);
  prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); // rouge
  prog.setAttributeValue(SommetId,  0.0, 0.0,0.0);

  prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); // vert
  prog.setAttributeValue(SommetId,  P.get_L()*sin(P.get_P()),
                                   -P.get_L()*cos(P.get_P()),
                                    0.0);
glEnd();


matrice.translate(P.get_O1()+P.get_L()*sin(P.get_P()),P.get_O2() -P.get_L()*cos(P.get_P()), P.get_O3()+0.0);
matrice.scale(0.2);
glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // passe en mode "fil de fer"
 dessineSphere(matrice, 1.0, 1.0, 0.0);
}
//**********************************************************//

void VueOpenGL::dessine(Ressort const& R)  {

    QMatrix4x4 origine;
    origine.translate(R.get_O1(),R.get_O2(),R.get_O3()); // met les coord que t'as dans Doubleressort::Origine
    //dessineAxes(origine); // dessine le repère principal

    prog.setUniformValue("vue_modele", matrice_vue*origine);
/*
    glBegin(GL_LINES);
      prog.setAttributeValue(CouleurId, 1.0, 0.0, 1.0); //couleur
      prog.setAttributeValue(SommetId,  0.0, 0.0, 0.0);

      prog.setAttributeValue(CouleurId, 1.0, 1.0, 0.0); //couleur
      prog.setAttributeValue(SommetId,  -R.get_P()*R.get_A(), 0.0, 0.0);
    glEnd();

*/
    glBegin(GL_LINE_STRIP);
      prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); //couleur
      prog.setAttributeValue(SommetId,  0.0, 0.0, 0.0);
      for(double i(0.2); i<1 ; i+=0.2){                                               //pour le fun
          prog.setAttributeValue(CouleurId, 1-i, i, 2*i ); //couleur                  //
          prog.setAttributeValue(SommetId,  (-R.get_P()*R.get_A())*(i), 0.0, 0.0);    //
      }                                                                               //
      prog.setAttributeValue(CouleurId, 0.0, 1.0, .0); //couleur
      prog.setAttributeValue(SommetId,  -R.get_P()*R.get_A(), 0.0, 0.0);
    glEnd();
}

// ======================================================================

void VueOpenGL::dessine(DoubleRessort const& dr) {

    QMatrix4x4 origine;
    origine.translate(dr.get_O1(),dr.get_O2(),dr.get_O3()); // met les coord qu t'as dans Doubleressort::Origine

    prog.setUniformValue("vue_modele", matrice_vue*origine);

    glBegin(GL_LINES);                                                          //première boule
      prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); //couleur
      prog.setAttributeValue(SommetId,  0.0, 0.0, 0.0);

      prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); //couleur
      prog.setAttributeValue(SommetId,  dr.get_L1()+dr.get_P1(),0.0,  0.0);
    glEnd();

    QMatrix4x4 matrice;
    matrice.translate(dr.get_O1()+ dr.get_L1()+dr.get_P1(), dr.get_O2()+ 0.0, dr.get_O3()+0.0);
    matrice.scale(0.05);
    dessineSphere(matrice, 1.0, 0.0, 0.0);

     //******************************************************************//

    prog.setUniformValue("vue_modele", matrice_vue*origine);

    glBegin(GL_LINES);                                                          //deuxième boule
       prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); //couleur
       prog.setAttributeValue(SommetId,  dr.get_L1()+dr.get_P1(),0.0, 0.0);

       prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); //couleur
       prog.setAttributeValue(SommetId,  dr.get_L1()+dr.get_L2()-dr.get_P2(),0.0,0.0);
     glEnd();

     matrice.setToIdentity();
     matrice.translate(dr.get_O1()+dr.get_L1()+dr.get_L2()-dr.get_P2(),dr.get_O2()+0.0,dr.get_O3()+0.0);
     matrice.scale(0.05);
     dessineSphere(matrice, 1.0, 0.0, 0.0);
     //******************************************************************//
     prog.setUniformValue("vue_modele", matrice_vue*origine);

     glBegin(GL_LINES);                                                          //Troisième point
       prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); //couleur
       prog.setAttributeValue(SommetId,  dr.get_L1()+dr.get_L2()-dr.get_P2(),0.0,0.0);

       prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); //couleur
       prog.setAttributeValue(SommetId,  dr.get_L1()+dr.get_L2()+dr.get_L3(),0.0,0.0);
       glEnd();

     matrice.translate(dr.get_L1()+dr.get_L2()+dr.get_L3(),0.0,0.0);

     //******************************************************************//

}

//******************************************************************//
  void VueOpenGL::dessinePhase(Oscillateur const& O) {                     //dessine l'espace des phases !!

      QMatrix4x4 origine;
      origine.translate(0.0, 0.0, 0.0);
      dessineAxes(origine); // dessine le repère principal

      pos_phase.push_back(O.getP().getvalue(0));
      pos_phase.push_back(O.getQ().getvalue(0));

      glBegin(GL_LINE_STRIP);
       for(size_t i(0); i<pos_phase.size() ; i+=2){
            prog.setAttributeValue(CouleurId, 0.2, 1, 2 ); //couleur cyan
            prog.setAttributeValue(SommetId,  pos_phase[i], pos_phase[i+1], 0.0);
        }
      glEnd();
      QMatrix4x4 matrice ;
      matrice.translate(pos_phase[pos_phase.size()-2],pos_phase.back(),0.0);
      matrice.scale(0.02);
      dessineSphere(matrice, 1.0, 0.0, 0.0);
  }

// ======================================================================
void VueOpenGL::init()
{
  /* Initialise notre vue OpenGL.
   * Dans cet exemple, nous créons et activons notre shader.
   *
   * En raison du contenu des fichiers *.glsl, le shader de cet exemple
   * NE permet QUE de dessiner des primitives colorées 
   * (pas de textures, brouillard, reflets de la lumière ou autres).
   *
   * Il est séparé en deux parties VERTEX et FRAGMENT.
   * Le VERTEX :
   * - récupère pour chaque sommet des primitives de couleur (dans
   *     l'attribut couleur) et de position (dans l'attribut sommet)
   * - multiplie l'attribut sommet par les matrices 'vue_modele' et
   *     'projection' et donne le résultat à OpenGL
   *   - passe la couleur au shader FRAGMENT.
   *
   * Le FRAGMENT :
   *   - applique la couleur qu'on lui donne
   */

  prog.addShaderFromSourceFile(QGLShader::Vertex,   ":/vertex_shader.glsl");
  prog.addShaderFromSourceFile(QGLShader::Fragment, ":/fragment_shader.glsl");

  /* Identifie les deux attributs du shader de cet exemple
   * (voir vertex_shader.glsl).
   *
   * L'attribut identifié par 0 est particulier, il permet d'envoyer un
   * nouveau "point" à OpenGL
   * 
   * C'est pourquoi il devra obligatoirement être spécifié et en dernier 
   * (après la couleur dans cet exemple, voir plus bas).
   */

  prog.bindAttributeLocation("sommet",  SommetId);
  prog.bindAttributeLocation("couleur", CouleurId);
  
  // Compilation du shader OpenGL
  prog.link();

  // Activation du shader
  prog.bind();

  /* Activation du "Test de profondeur" et du "Back-face culling"
   * Le Test de profondeur permet de dessiner un objet à l'arrière-plan
   * partielement caché par d'autres objets.
   * 
   * Le Back-face culling consiste à ne dessiner que les face avec ordre 
   * de déclaration dans le sens trigonométrique.
   */
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  sphere.initialize();                                      // initialise la sphère
  initializePosition();
}

// ======================================================================
void VueOpenGL::initializePosition()
{
  // position initiale
  matrice_vue.setToIdentity();
  matrice_vue.translate(0.0, 0.0, -6.0);
 // matrice_vue.rotate(60.0, 0.0, 1.0, 0.0);
 // matrice_vue.rotate(45.0, 0.0, 0.0, 1.0);
}

// ======================================================================
void VueOpenGL::translate(double x, double y, double z)
{
  /* Multiplie la matrice de vue par LA GAUCHE.
   * Cela fait en sorte que la dernière modification apportée
   * à la matrice soit appliquée en dernier (composition de fonctions).
   */
  QMatrix4x4 translation_supplementaire;
  translation_supplementaire.translate(x, y, z);
  matrice_vue = translation_supplementaire * matrice_vue;
}

// ======================================================================
void VueOpenGL::rotate(double angle, double dir_x, double dir_y, double dir_z)
{
  // Multiplie la matrice de vue par LA GAUCHE
  QMatrix4x4 rotation_supplementaire;
  rotation_supplementaire.rotate(angle, dir_x, dir_y, dir_z);
  matrice_vue = rotation_supplementaire * matrice_vue;
}

// ======================================================================
void VueOpenGL::dessineCube (QMatrix4x4 const& point_de_vue)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  glBegin(GL_QUADS);
  // face coté X = +1
  prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); // rouge
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);

  // face coté X = -1
  prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); // vert
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);

  // face coté Y = +1
  prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); // bleu
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);

  // face coté Y = -1
  prog.setAttributeValue(CouleurId, 0.0, 1.0, 1.0); // cyan
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);

  // face coté Z = +1
  prog.setAttributeValue(CouleurId, 1.0, 1.0, 0.0); // jaune
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);

  // face coté Z = -1
  prog.setAttributeValue(CouleurId, 1.0, 0.0, 1.0); // magenta
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);

  glEnd();
}

//==========================================================
void VueOpenGL::dessineAxes (QMatrix4x4 const& point_de_vue, bool en_couleur)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  glBegin(GL_LINES);

  // axe X
  if (en_couleur) {
    prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); // rouge
  } else {
    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // blanc
  }
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 1.0, 0.0, 0.0);

  // axe Y
  if (en_couleur) prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); // vert
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 0.0, 1.0, 0.0);

  // axe Z
  if (en_couleur) prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); // bleu
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 0.0, 0.0, 1.0);

  glEnd();
}

//==========================================================

void VueOpenGL::dessineSphere (QMatrix4x4 const& point_de_vue,
                               double rouge, double vert, double bleu)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
  prog.setAttributeValue(CouleurId, rouge, vert, bleu);  // met la couleur
  sphere.draw(prog, SommetId);                           // dessine la sphère
}
