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
    ../../../Driver/hw_krInterrupt.cpp \
    ../../../Driver/hw_msMicro.cpp \
    ../../../Driver/hw_rs2Buttons.cpp \
    ../../../Driver/hw_rs2lcd.cpp \
    ../../../Driver/qtdef.cpp \
    ../../../../../../../Firmware/ap/fnDef.cpp \
    ../../../../../../../Firmware/ap/krEventTbl.cpp \
    ../../../../../../../Firmware/ap/krProcessTbl.cpp \
    ../../../../../../../Firmware/ap/krTimerTbl.cpp \
    ../../../../../../../Firmware/ap/uiAppButton.cpp \
    ../../../../../../../Firmware/ap/uiApplication.cpp \
    ../../../../../../../Firmware/ap/uiDef.cpp \
    ../../../../../../../Firmware/kr/krEvent.cpp \
    ../../../../../../../Firmware/kr/krProcess.cpp \
    ../../../../../../../Firmware/kr/krTimer.cpp \
    ../../../../../../../Firmware/rs/rs2Buttons.cpp \
    ../../../../../../../Firmware/rs/rs2Lcd.cpp \
    ../../../../../../../Firmware/ui/uiBase.cpp \
    ../../../../../../../Firmware/ui/uiButton.cpp \
    ../../../../../../../Firmware/ui/uiLbox.cpp \
    ../../../../../../../Firmware/ui/uiPage.cpp \
    ../../../../../../../Firmware/ui/uiPar.cpp \
    ../../../../../../../Firmware/ui/uiStr.cpp \
    ../../../../../../../Firmware/ui/uiVar.cpp \
    ../../../../../../../Firmware/uy/msDef.cpp \
    ../../../../../../../Firmware/uy/msTest.cpp

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
    ../../../../../../../Include/driver/msPlatform.h \
    ../../../../../../../Include/driver/hw_krInterrupt.h \
    ../../../../../../../Include/driver/hw_msMicro.h \
    ../../../../../../../Include/driver/hw_rs2Buttons.h \
    ../../../../../../../Include/driver/hw_rs2Lcd.h \
    ../../../../../../../Firmware/ap/fnThermostatGlo.h \
    ../../../../../../../Firmware/ap/krEventGlo.h \
    ../../../../../../../Firmware/ap/krProcessGlo.h \
    ../../../../../../../Firmware/ap/krTimerGlo.h \
    ../../../../../../../Firmware/ap/ui_AppFatTestDsp.h \
    ../../../../../../../Firmware/ap/ui_fnThermostatDsp.h \
    ../../../../../../../Firmware/ap/ui_fnThermostatEdt.h \
    ../../../../../../../Firmware/ap/ui_GeneralEdt.h \
    ../../../../../../../Firmware/ap/ui_rs2ButtonsDsp.h \
    ../../../../../../../Firmware/ap/uiAppButton.h \
    ../../../../../../../Firmware/ap/uiApplicationGlo.h \
    ../../../../../../../Firmware/cf/cfInclude.h \
    ../../../../../../../Firmware/kr/krEvent.h \
    ../../../../../../../Firmware/kr/krProcess.h \
    ../../../../../../../Firmware/kr/krTimer.h \
    ../../../../../../../Firmware/rs/rs2ADC.h \
    ../../../../../../../Firmware/rs/rs2ADCGlo.h \
    ../../../../../../../Firmware/rs/rs2Buttons.h \
    ../../../../../../../Firmware/rs/rs2ButtonsGlo.h \
    ../../../../../../../Firmware/rs/rs2Glcd.h \
    ../../../../../../../Firmware/rs/rs2Lcd.h \
    ../../../../../../../Firmware/rs/rs2Touch.h \
    ../../../../../../../Firmware/rs/rs2TouchGlo.h \
    ../../../../../../../Firmware/ui/uiBase.h \
    ../../../../../../../Firmware/ui/uiBaseGlo.h \
    ../../../../../../../Firmware/ui/uiButton.h \
    ../../../../../../../Firmware/ui/uiButtonGlo.h \
    ../../../../../../../Firmware/ui/uiLbox.h \
    ../../../../../../../Firmware/ui/uiLboxGlo.h \
    ../../../../../../../Firmware/ui/uiPage.h \
    ../../../../../../../Firmware/ui/uiPageGlo.h \
    ../../../../../../../Firmware/ui/uiPar.h \
    ../../../../../../../Firmware/ui/uiParDisplayGlo.h \
    ../../../../../../../Firmware/ui/uiParGlo.h \
    ../../../../../../../Firmware/ui/uiStr.h \
    ../../../../../../../Firmware/ui/uiStrGlo.h \
    ../../../../../../../Firmware/ui/uiVar.h \
    ../../../../../../../Firmware/ui/uiVarGlo.h \
    ../../../../../../../Firmware/uy/msTest.h \

DISTFILES += \
    deployment.pri
