cmake_minimum_required(VERSION 3.5)

project(FinalProject VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        wordsetwidget.cpp
        basicbutton.cpp
        myBackground.cpp
        myButton.cpp
        myFont.cpp
        myLabelButton.cpp
        myLineEdit.cpp
        mysubwidget.cpp
        addingwidget.cpp
        reviewwidget.cpp
        wordsection.cpp
        wordwidget.cpp
        mainWidget.cpp
        myTextEdit.cpp
        cardset.cpp
        card.cpp
        calendar.cpp
        myFile.cpp
        mainwindow.h
        wordsetwidget.h
        mainWidget.h
        basicbutton.h
        addingwidget.h
        myLabelButton.h
        myButton.h
        myLineEdit.h
        myBackground.h
        myFont.h
        myTextEdit.h
        calendar.h
        cardset.h
        card.h
        reviewwidget.h
        mysubwidget.h
        wordwidget.h
        wordsection.h
        myFile.h
        wordlewidget.cpp
        wordlewidget.h

        textwidget.cpp
        textwidget.h
        textsection.cpp
        textsection.h
        newwordwidget.cpp
        newwordwidget.h
        oldwordwidget.cpp
        oldwordwidget.h
        sentencewidget.cpp
        sentencewidget.h
        notewidget.cpp
        notewidget.h
        mainwindow.ui
        imgs.qrc

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(FinalProject
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET FinalProject APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(FinalProject SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(FinalProject
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(FinalProject PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(FinalProject PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS FinalProject
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(FinalProject)
endif()
