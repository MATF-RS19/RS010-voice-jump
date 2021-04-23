cmake_minimum_required(VERSION 3.5)
project(voice_jump VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)

find_library(FFTW_LIBRARY
     NAMES fftw3 fftw)
set(FFTW_LIBRARIES "${FFTW_LIBRARY}")
if(UNIX AND NOT WIN32)
     find_library(FFTW_libm_LIBRARY
         NAMES m)
     list(APPEND FFTW_LIBRARIES "${FFTW_libm_LIBRARY}")
endif()

set(SOURCES
main.cpp
player.cpp
recorder.cpp
obstacle.cpp
score.cpp
game_over.cpp
flower.cpp
resources.qrc
)


set(HEADERS
player.h
recorder.h
obstacle.h
score.h
game_over.h
flower.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} ${FFTW_LIBRARIES})
qt5_use_modules(${PROJECT_NAME} Core Gui Widgets Multimedia MultimediaWidgets)
