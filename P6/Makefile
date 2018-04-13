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

all:	testVecteur	testOscillateur	TestIntegrateur	testPendule	testRessort

Vecteur.o:	Vecteur.cc	Vecteur.h

testVecteur.o:	testVecteur.cc	Vecteur.h

testVecteur:	testVecteur.o	Vecteur.o

#============================================================================================

Oscillateur.o:	Oscillateur.cc	Oscillateur.h	Vecteur.h	Dessinable.h

testOscillateur.o:	testOscillateur.cc	Oscillateur.h	Vecteur.h Dessinable.h

testOscillateur:	testOscillateur.o	Oscillateur.o	Vecteur.o 
#============================================================================================

Integrateur.o:	Integrateur.cc	Integrateur.h	Oscillateur.h	Vecteur.h 

TestIntegrateur.o:	TestIntegrateur.cc	Integrateur.h	Oscillateur.h	Vecteur.h

TestIntegrateur:	TestIntegrateur.o	Integrateur.o	Oscillateur.o	Vecteur.o
 
#============================================================================================

Pendule.o:	Pendule.cc	Pendule.h	Oscillateur.h	Vecteur.h

testPendule.o:	testPendule.cc	Pendule.h	Oscillateur.h	Vecteur.h

testPendule:	testPendule.o	Pendule.o	Oscillateur.o	Vecteur.o

#============================================================================================

Ressort.o:	Ressort.cc	Ressort.h	Oscillateur.h	Vecteur.h

testRessort.o:	testRessort.cc	Ressort.h	Oscillateur.h	Vecteur.h

testRessort:	testRessort.o	Ressort.o	Oscillateur.o	Vecteur.o

#============================================================================================


