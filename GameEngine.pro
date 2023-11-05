QT = core

CONFIG += c++17 cmdline

SOURCES += \
    Main.cpp \
    Sources/Engine.cpp \
    Sources/TextureManager.cpp


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH +=C:\DevLibs\SDL2-2.28.3\include
INCLUDEPATH +=C:\DevLibs\SDL2_image-2.6.3\include
INCLUDEPATH +=Sources

LIBS += -LC:\DevLibs\SDL2-2.28.3\lib\x64
LIBS += -LC:\DevLibs\SDL2_image-2.6.3\lib\x64
LIBS += SDL2.lib
LIBS += SDL2main.lib
LIBS += SDL2_image.lib

HEADERS += \
    Sources/Engine.h \
    Sources/TextureManager.h
