QT += core gui
greaterThan(QT_MAJOR_VERSION , 4): QT += widgets

CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        AbstractController.cpp \
        AbstractUI.cpp \
        Active.cpp \
        Character.cpp \
        Door.cpp \
        DungeonCrawler.cpp \
        Floor.cpp \
        GuardController.cpp \
        Level.cpp \
        Npc.cpp \
        Main.cpp \
        Passive.cpp \
        Pit.cpp \
        Portal.cpp \
        Ramp.cpp \
        Switch.cpp \
        TerminalUI.cpp \
        Tile.cpp \
        Wall.cpp \
        GraphicalUI.cpp \
    attackcontroller.cpp \
    button.cpp \
    dungeoncrawlersaver.cpp \
    levelchanger.cpp \
    lootchest.cpp \
    mainwindow.cpp \
    mainwindowgame.cpp \
    mainwindowgamelost.cpp \
    mainwindowgamewon.cpp \
    path.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


HEADERS += \
    AbstractController.h \
    AbstractUI.h \
    Active.h \
    Character.h \
    Door.h \
    DungeonCrawler.h \
    Floor.h \
    GuardController.h \
    Level.h \
    Npc.h \
    Passive.h \
    Pit.h \
    Portal.h \
    Ramp.h \
    Switch.h \
    TerminalUI.h \
    Tile.h \
    Wall.h \
    GraphicalUI.h \
    attackcontroller.h \
    button.h \
    dungeoncrawlersaver.h \
    levelchanger.h \
    lootchest.h \
    mainwindow.h \
    mainwindowgame.h \
    mainwindowgamelost.h \
    mainwindowgamewon.h \
    path.h

FORMS += \
    mainwindow.ui \
    mainwindowgame.ui \
    mainwindowgamelost.ui \
    mainwindowgamewon.ui
