QT += testlib
QT -= gui

QT += widgets
LIBS += -IGL

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_ei_autotest.cpp \
    ../../PF_Garcia/algoritmodelpintor.cpp \
    ../../PF_Garcia/archivosaic.cpp \
    ../../PF_Garcia/archivospnm.cpp \
    ../../PF_Garcia/espaciodetrabajo.cpp \
    ../../PF_Garcia/filtros.cpp \
    ../../PF_Garcia/gestordearchivos.cpp \
    ../../PF_Garcia/graficadorhistograma.cpp \
    ../../PF_Garcia/imagen.cpp \
    ../../PF_Garcia/pixel.cpp \
    ../../PF_Garcia/procesadorestadistico.cpp \
    ../../PF_Garcia/sistema.cpp \
    ../../PF_Garcia/tablalut.cpp \
    ../../PF_Garcia/ventanadegraficacion.cpp
HEADERS += \
    ../../PF_Garcia/ExcepcionArchivoCorrupto.h \
    ../../PF_Garcia/ExcepcionArchivoNoSoportado.h \
    ../../PF_Garcia/algoritmodelpintor.h \
    ../../PF_Garcia/archivosaic.h \
    ../../PF_Garcia/archivospnm.h \
    ../../PF_Garcia/espaciodetrabajo.h \
    ../../PF_Garcia/filtros.h \
    ../../PF_Garcia/gestordearchivos.h \
    ../../PF_Garcia/graficadorhistograma.h \
    ../../PF_Garcia/imagen.h \
    ../../PF_Garcia/pixel.h \
    ../../PF_Garcia/procesadorestadistico.h \
    ../../PF_Garcia/sistema.h \
    ../../PF_Garcia/tablalut.h \
    ../../PF_Garcia/ventanadegraficacion.h

DISTFILES += \
    ../../PF_Garcia/lista_de_atajos.txt \
    ../../PF_Garcia/registro.txt
