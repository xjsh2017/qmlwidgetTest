#-------------------------------------------------
#
# Project created by QtCreator 2017-02-22T15:00:18
#
#-------------------------------------------------

QT       += core gui quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qmlwidgetTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        waveanaldatamodel.cpp

HEADERS  += mainwindow.h \
        waveanaldatamodel.h

FORMS    += mainwindow.ui


# Q_USE_QML_RC
# ![1] search res directories

searchlist_rc += \
    *.qml \
    *.js \
    *.png \
    *.jpg \
    *.gif \
    *.svg \
    *qmldir

for (searchvar_rc, searchlist_rc) {
    qrclist += $$files($$searchvar_rc, true)
}

# ![2] create qml.qrc

RESOURCE_CONTENT = \
"<RCC>" \
" <qresource prefix=\"/\"> "

for(qrcvar, qrclist) {
    resourcefileabsolutepath = $$absolute_path($$qrcvar)
    relativepath_in = $$relative_path($$resourcefileabsolutepath, $$PWD)
    RESOURCE_CONTENT += "<file alias=\"$$relativepath_in\">$$relativepath_in</file>"
}

RESOURCE_CONTENT += \
' </qresource>' \
</RCC>

GENERATED_RESOURCE_FILE = $$PWD/qml.qrc
QMAKE_CLEAN += $$GENERATED_RESOURCE_FILE

write_file($$GENERATED_RESOURCE_FILE, RESOURCE_CONTENT)

OTHER_FILES += $$qrclist

RESOURCES += \
    $$[QT_INSTALL_QML]/XjQmlUi/icons/icons.qrc
