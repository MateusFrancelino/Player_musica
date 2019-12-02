TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        manipula_arquivo.cpp

win32: LIBS += -L$$PWD/../../Desktop/SDL2-2.0.10/x86_64-w64-mingw32/lib/ -lSDL2

INCLUDEPATH += $$PWD/../../Desktop/SDL2-2.0.10/x86_64-w64-mingw32/include
DEPENDPATH += $$PWD/../../Desktop/SDL2-2.0.10/x86_64-w64-mingw32/include


win32: LIBS += -L$$PWD/../../Desktop/SDL2_mixer-2.0.4/x86_64-w64-mingw32/lib/ -lSDL2_mixer

INCLUDEPATH += $$PWD/../../Desktop/SDL2_mixer-2.0.4/x86_64-w64-mingw32/include
DEPENDPATH += $$PWD/../../Desktop/SDL2_mixer-2.0.4/x86_64-w64-mingw32/include

HEADERS += \
    declara_botao.h \
    manipula_arquivo.h \
    verifica_cliques_botoes.h

