cmake_minimum_required(VERSION 3.14)

project(GoaManjat LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(GoaManjat
  AbstractController.h
  AbstractController.cpp
  AbstractUI.h
  AbstractUI.cpp
  Active.h
  Active.cpp
  Character.h
  Character.cpp
  Door.h
  Door.cpp
  DungeonCrawler.h
  DungeonCrawler.cpp
  Floor.h
  Floor.cpp
  GuardController.h
  GuardController.cpp
  Level.h
  Level.cpp
  Npc.h
  Npc.cpp
  Main.cpp
  Passive.h
  Passive.cpp
  Pit.h
  Pit.cpp
  Portal.h
  Portal.cpp
  Ramp.h
  Ramp.cpp
  Switch.h
  Switch.cpp
  TerminalUI.h
  TerminalUI.cpp
  Tile.h
  Tile.cpp
  Wall.h
  Wall.cpp
  GraphicalUI.cpp
  GraphicalUI.h
)
target_link_libraries(GoaManjat Qt${QT_VERSION_MAJOR}::Core)

install(TARGETS GoaManjat
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
