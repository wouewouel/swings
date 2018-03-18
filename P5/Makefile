CXX = g++
CC  = $(CXX)

CXXFLAGS = -std=c++11  # C++11

# Partie comment‚e : choisissez les options que vous voulez avoir
#                    en d‚commentant la/les lignes correspondantes
#
CXXFLAGS += -pedantic -Wall         # pour les purs et durs
CXXFLAGS += -g                      # pour debugger
# CXXFLAGS += -pg                   # pour profiler
# LDFLAGS  += -pg                   # pour profiler
# CXXFLAGS += -O2                   # pour optimiser la vitesse

all: testVecteur testOscillateur

Vecteur.o: Vecteur.cc Vecteur.h

testVecteur.o: testVecteur.cc Vecteur.h

testVecteur: testVecteur.o Vecteur.o

#=======================================================================

Oscillateur.o: Oscillateur.cc Oscillateur.h Vecteur.h

testOscillateur.o: testOscillateur.cc Oscillateur.h Vecteur.h

testOscillateur: testOscillateur.o Oscillateur.o Vecteur.o
