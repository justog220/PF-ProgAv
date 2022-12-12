QT += testlib
QT -= gui

QT += widgets
LIBS += -IGL

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_ei_autotest.cpp \
    ../../algoritmodelpintor.cpp \
    ../../archivosaic.cpp \
    ../../archivospnm.cpp \
    ../../espaciodetrabajo.cpp \
    ../../filtros.cpp \
    ../../gestordearchivos.cpp \
    ../../graficadorhistograma.cpp \
    ../../imagen.cpp \
    ../../pixel.cpp \
    ../../procesadorestadistico.cpp \
    ../../sistema.cpp \
    ../../tablalut.cpp \
    ../../ventanadegraficacion.cpp \
    ../../binarizado.cpp \
    ../../brillo.cpp \
    ../../contraste.cpp \
    ../../filtromediana.cpp \
    ../../filtropasaaltos.cpp \
    ../../filtropasabajos.cpp \
    ../../negativo.cpp
HEADERS += \
    ../../ExcepcionArchivoCorrupto.h \
    ../../ExcepcionArchivoNoSoportado.h \
    ../../algoritmodelpintor.h \
    ../../archivosaic.h \
    ../../archivospnm.h \
    ../../espaciodetrabajo.h \
    ../../filtros.h \
    ../../gestordearchivos.h \
    ../../graficadorhistograma.h \
    ../../imagen.h \
    ../../pixel.h \
    ../../procesadorestadistico.h \
    ../../sistema.h \
    ../../tablalut.h \
    ../../ventanadegraficacion.h \
    ../../binarizado.h \
    ../../brillo.h \
    ../../contraste.h \
    ../../filtromediana.h \
    ../../filtropasaaltos.h \
    ../../filtropasabajos.h \
    ../../negativo.h

DISTFILES += \
    ../../PF_Garcia/lista_de_atajos.txt \
    ../../PF_Garcia/registro.txt
