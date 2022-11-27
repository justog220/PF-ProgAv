QT += testlib widgets
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += tst_ei_autotest.cpp\
        algoritmodelpintor.cpp \
        archivosaic.cpp \
        archivospnm.cpp \
        espaciodetrabajo.cpp \
        filtros.cpp \
        gestordearchivos.cpp \
        graficador.cpp \
        graficadorhistograma.cpp \
        imagen.cpp \
        main.cpp \
        pixel.cpp \
        procesadorestadistico.cpp \
        sistema.cpp

HEADERS += \
    ExcepcionArchivoCorrupto.h \
    ExcepcionArchivoNoSoportado.h \
    algoritmodelpintor.h \
    archivosaic.h \
    archivospnm.h \
    espaciodetrabajo.h \
    filtros.h \
    gestordearchivos.h \
    graficador.h \
    graficadorhistograma.h \
    imagen.h \
    pixel.h \
    procesadorestadistico.h \
    sistema.h
