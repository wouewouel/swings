CXX = g++
CC  = $(CXX)

CXXFLAGS = -std=c++11  # C++11

# Partie comment‚e : choisissez les options que vous voulez avoir
#                    en commentant la/les lignes correspondantes
#
CXXFLAGS += -pedantic -Wall         # pour les purs et durs
CXXFLAGS += -g                      # pour debugger
# CXXFLAGS += -pg                   # pour profiler
# LDFLAGS  += -pg                   # pour profiler
# CXXFLAGS += -O2                   # pour optimiser la vitesse

all:	TestVecteur	TestOscillateur	TestIntegrateur	TestPendule	TestRessort	ExerciceP9

Vecteur.o:	Vecteur.cc	Vecteur.h

TestVecteur.o:	TestVecteur.cc	Vecteur.h

TestVecteur:	TestVecteur.o	Vecteur.o

#=======================================================================================================================================================

Oscillateur.o:	Oscillateur.cc	Oscillateur.h	Vecteur.h	Dessinable.h

TestOscillateur.o:	TestOscillateur.cc	Oscillateur.h	Vecteur.h Dessinable.h

TestOscillateur:	TestOscillateur.o	Oscillateur.o	Vecteur.o 
#=======================================================================================================================================================

Integrateur.o:	Integrateur.cc	Integrateur.h	Oscillateur.h	Vecteur.h 

TestIntegrateur.o:	TestIntegrateur.cc	Integrateur.h	Oscillateur.h	Vecteur.h

TestIntegrateur:	TestIntegrateur.o	Integrateur.o	Oscillateur.o	Vecteur.o
 
#=======================================================================================================================================================

Pendule.o:	Pendule.cc	Pendule.h	Oscillateur.h	Vecteur.h	Integrateur.h

TestPendule.o:	TestPendule.cc	Pendule.h	Oscillateur.h	Vecteur.h	Integrateur.h

TestPendule:	TestPendule.o	Pendule.o	Oscillateur.o	Vecteur.o	Integrateur.o

#=======================================================================================================================================================

Ressort.o:	Ressort.cc	Ressort.h	Oscillateur.h	Vecteur.h	Integrateur.h

TestRessort.o:	TestRessort.cc	Ressort.h	Oscillateur.h	Vecteur.h	Integrateur.h

TestRessort:	TestRessort.o	Ressort.o	Oscillateur.o	Vecteur.o	Integrateur.o

#=======================================================================================================================================================

TextViewer.o:	TextViewer.cc	TextViewer.h	Ressort.h	Pendule.h	Systeme.h	Integrateur.h	Oscillateur.h	Vecteur.h	SupportADessin.h

ExerciceP9.o:	ExerciceP9.cc	TextViewer.h	Ressort.h	Pendule.h	Systeme.h	Integrateur.h	Oscillateur.h	Vecteur.o

ExerciceP9:	ExerciceP9.o	TextViewer.o	Ressort.o	Pendule.o	Systeme.o	Integrateur.o	Oscillateur.o	Vecteur.o	

#=======================================================================================================================================================	



