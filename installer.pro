#-------------------------------------------------
#
# Project created by QtCreator 2020-03-03T15:17:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += widgets-private

TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

CONFIG += resources_big

TARGET = installer


LIBS += -lole32 -luuid

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    installer.cpp \
    gui/basepage.cpp \
    gui/install/pagesmanager.cpp \
    gui/install/installerwizard.cpp \
    gui/basewizard.cpp \
    gui/install/pages/intropage.cpp \
    gui/install/pages/folderchoosingpage.cpp \
    gui/wdirectory.cpp \
    gui/install/pages/settingspage.cpp \
    data/dataprovider.cpp \
    gui/install/pages/addingstartmenupage.cpp \
    gui/install/pages/readyforinstallpage.cpp \
    gui/install/pages/installprocesspage.cpp \
    cores/installationcore.cpp \
    gui/install/pages/finishpage.cpp \
    cores/algorithm/installalgorithm.cpp \
    cores/algorithm/process.cpp \
    system/system.cpp \
    cores/algorithm/database.cpp \
    cores/algorithm/files.cpp \
    cores/algorithm/folders.cpp \
    gui/dialogforms.cpp

HEADERS  += installer.h \
    gui/basepage.h \
    gui/install/pagesmanager.h \
    gui/install/installerwizard.h \
    gui/basewizard.h \
    gui/install/pages/intropage.h \
    gui/install/pages/folderchoosingpage.h \
    gui/wdirectory.h \
    gui/install/pages/settingspage.h \
    data/dataprovider.h \
    constants.h \
    gui/install/pages/addingstartmenupage.h \
    gui/install/pages/readyforinstallpage.h \
    gui/install/pages/installprocesspage.h \
    cores/installationcore.h \
    names.h \
    gui/install/pages/finishpage.h \
    cores/algorithm/installalgorithm.h \
    cores/algorithm/process.h \
    system/system.h \
    cores/algorithm/database.h \
    cores/algorithm/files.h \
    cores/algorithm/folders.h \
    gui/dialogforms.h

FORMS += \
    gui/install/pages/intropage.ui \
    gui/install/pages/folderchoosingpage.ui \
    gui/install/pages/settingspage.ui \
    gui/install/pages/addingstartmenupage.ui \
    gui/install/pages/readyforinstallpage.ui \
    gui/install/pages/installprocesspage.ui \
    gui/install/pages/finishpage.ui

RESOURCES += \
    resources.qrc

TRANSLATIONS = lang/installer_ru.ts
