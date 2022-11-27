QT -= gui

QT += widgets
LIBS += -IGL


CONFIG += c++11 console qt
CONFIG -= app_bundle


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        algoritmodelpintor.cpp \
        archivosaic.cpp \
        archivospnm.cpp \
        espaciodetrabajo.cpp \
        filtros.cpp \
        gestordearchivos.cpp \
        graficadorhistograma.cpp \
        imagen.cpp \
        main.cpp \
        pixel.cpp \
        procesadorestadistico.cpp \
        sistema.cpp \
        tablalut.cpp \
        ventanadegraficacion.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ExcepcionArchivoCorrupto.h \
    ExcepcionArchivoNoSoportado.h \
    algoritmodelpintor.h \
    archivosaic.h \
    archivospnm.h \
    espaciodetrabajo.h \
    filtros.h \
    gestordearchivos.h \
    graficadorhistograma.h \
    imagen.h \
    pixel.h \
    procesadorestadistico.h \
    sistema.h \
    tablalut.h \
    ventanadegraficacion.h

