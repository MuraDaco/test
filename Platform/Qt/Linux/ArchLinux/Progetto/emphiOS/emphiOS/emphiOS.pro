TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    eosguiapplication.cpp \
    eosquickview.cpp \
    eositem.cpp \
    eosthreadworker.cpp \
    eosthreadcontroller.cpp \
    fw_test.cpp \
    ../../../Driver/hw_rs2lcd.cpp \
    ../../../Driver/qtdef.cpp \
    ../../../Driver/hw_krInterrupt.cpp \
    ../../../Driver/hw_msMicro.cpp \
    ../../../Driver/hw_rs2Buttons.cpp \
    ../../../../../../../Firmware/krTimer.cpp \
    ../../../../../../../Firmware/msDef.cpp \
    ../../../../../../../Firmware/fnDef.cpp \
    ../../../../../../../Firmware/krEvent.cpp \
    ../../../../../../../Firmware/krEventTbl.cpp \
    ../../../../../../../Firmware/krProcess.cpp \
    ../../../../../../../Firmware/krProcessTbl.cpp \
    ../../../../../../../Firmware/krTimerTbl.cpp \
    ../../../../../../../Firmware/msTest.cpp \
    ../../../../../../../Firmware/rs2Buttons.cpp \
    ../../../../../../../Firmware/rs2Lcd.cpp \
    ../../../../../../../Firmware/uiApplication.cpp \
    ../../../../../../../Firmware/uiBase.cpp \
    ../../../../../../../Firmware/uiDef.cpp \
    ../../../../../../../Firmware/uiLbox.cpp \
    ../../../../../../../Firmware/uiPage.cpp \
    ../../../../../../../Firmware/uiPar.cpp \
    ../../../../../../../Firmware/uiStr.cpp \
    ../../../../../../../Firmware/uiVar.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    eosguiapplication.h \
    eosquickview.h \
    eositem.h \
    eosthreadworker.h \
    eosthreadcontroller.h \
    fw_test.h \
    ../../../Driver/qtlcdglo.h \
    ../../../Driver/qtButtonsGlo.h \
    ../../../../../../../Include/Driver/msPlatform.h \
    ../../../../../../../Include/Driver/hw_rs2Lcd.h \
    ../../../../../../../Include/Driver/hw_krInterrupt.h \
    ../../../../../../../Include/Driver/hw_msMicro.h \
    ../../../../../../../Include/Driver/hw_rs2Buttons.h \
    ../../../../../../../Firmware/krTimerGlo.h \
    ../../../../../../../Firmware/krTimer.h \
    ../../../../../../../Firmware/krProcess.h \
    ../../../../../../../Firmware/rs2ButtonsGlo.h \
    ../../../../../../../Firmware/rs2Buttons.h \
    ../../../../../../../Firmware/uiLbox.h \
    ../../../../../../../Firmware/uiLboxGlo.h \
    ../../../../../../../Firmware/uiPage.h \
    ../../../../../../../Firmware/uiPageGlo.h \
    ../../../../../../../Firmware/uiPar.h \
    ../../../../../../../Firmware/uiParDisplayGlo.h \
    ../../../../../../../Firmware/uiParGlo.h \
    ../../../../../../../Firmware/uiApplicationGlo.h \
    ../../../../../../../Firmware/ui_GeneralEdt.h \
    ../../../../../../../Firmware/uiVar.h \
    ../../../../../../../Firmware/uiVarGlo.h \
    ../../../../../../../Firmware/ConfigEasyPicV7.h \
    ../../../../../../../Firmware/fnThermostatGlo.h \
    ../../../../../../../Firmware/krEvent.h \
    ../../../../../../../Firmware/krEventGlo.h \
    ../../../../../../../Firmware/krProcessGlo.h \
    ../../../../../../../Firmware/msTest.h \
    ../../../../../../../Firmware/rs2Lcd.h \
    ../../../../../../../Firmware/ui_fnThermostatDsp.h \
    ../../../../../../../Firmware/ui_fnThermostatEdt.h \
    ../../../../../../../Firmware/ui_rs2ButtonsDsp.h \
    ../../../../../../../Firmware/uiBase.h \
    ../../../../../../../Firmware/uiBaseGlo.h \
    ../../../../../../../Firmware/uiStr.h \
    ../../../../../../../Firmware/uiStrGlo.h
