QMAKE_CXXFLAGS += -std=c++11

TARGET = ex_P10_text

LIBS += -L../general -lgeneral

PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
    ExerciceP9.cc \
    text_viewer.cc
    
HEADERS += \
    ../general/Systeme.h \
    text_viewer.h \
    ../general/dessinable.h \
    ../general/support_a_dessin.h \
    ../general/Ressort.h \
    ../general/Pendule.h \
    ../general/Integrateur.h \
    ../general/constantes.h \
    ../general/Oscillateur.h
