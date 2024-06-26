cmake_minimum_required(VERSION 3.24)

project(wordchart)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml)

qt_add_executable(wordchart
    src/main.cpp
    src/wordchartmodel.h
    src/wordchartmodel.cpp
    src/fileprocessor.h
    src/fileprocessor.cpp
)

qt_add_qml_module(wordchart
    URI wc
    QML_FILES
        qml/Main.qml
)

target_include_directories(wordchart
    PRIVATE
        src
)

target_link_libraries(wordchart
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Qml
)
