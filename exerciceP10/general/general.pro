QMAKE_CXXFLAGS += -std=c++11

TEMPLATE = lib

CONFIG = staticlib

SOURCES = \
    Vecteur.cc \
    Oscillateur.cc \
    Pendule.cc \
    Ressort.cc \
    constantes.cc \
    Integrateur.cc \
    Systeme.cc \
    DoubleRessort.cc

HEADERS += \
    Vecteur.h \
    Oscillateur.h \
    Pendule.h \
    Ressort.h \
    Integrateur.h \
    dessinable.h \
    support_a_dessin.h \
    Systeme.h \
    constantes.h \
    DoubleRessort.h
