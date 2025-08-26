QT += core gui widgets sql xml concurrent testlib printsupport
CONFIG += c++17 qtestlib warn_on

TARGET = Currence

#--------------------------------------------------
# PostgresSQL
#--------------------------------------------------

unix {
    LIBS += -L/usr/lib/x86_64-linux-gnu -lpq
    INCLUDEPATH += /usr/include/postgresql
}

#--------------------------------------------------
# CURL
#--------------------------------------------------

unix {
    LIBS += -lcurl
}

#--------------------------------------------------
# libpqxx
#--------------------------------------------------

# Пути к libpqxx
LIBPQXX_INSTALL_DIR =  /home/andreyonkhonov/clone/exchangeRate_cbr/lib/libpqxx-install
exists($$LIBPQXX_INSTALL_DIR) {
    INCLUDEPATH += $$LIBPQXX_INSTALL_DIR/include
    LIBS += -L$$LIBPQXX_INSTALL_DIR/lib -lpqxx
} else {
    error("Директория libpqxx не найдена: $$LIBPQXX_INSTALL_DIR")
}

# Подключение PostgreSQL
unix: LIBS += -lpq

#--------------------------------------------------
# Нплагинов Qt
#--------------------------------------------------

# Пути к плагинам
unix:!android {
    QT_PLUGINS_DIR = $$[QT_INSTALL_PLUGINS]
    isEmpty(QT_PLUGINS_DIR) {
        QT_PLUGINS_DIR = /usr/lib/x86_64-linux-gnu/qt5/plugins
    }

    platformPlugin.file = $$QT_PLUGINS_DIR/platforms/libqxcb.so
    exists($$platformPlugin.file) {
        target.path = $$OUT_PWD
        platforms.path = $$target.path/platforms
        platforms.files = $$platformPlugin.file
        INSTALLS += target platforms
    } else {
        warning("Плагин libqxcb.so не найден! Проверьте путь: $$QT_PLUGINS_DIR/platforms/")
    }
}

#--------------------------------------------------
# iconv
#--------------------------------------------------

unix {
    # Проверяем наличие системной библиотеки
    exists(/usr/local/lib/libiconv.so) {
        LIBS += -L/usr/local/lib -liconv
        INCLUDEPATH += /usr/local/include
    }
    else:exists(/usr/lib/x86_64-linux-gnu/libiconv.so) {
        message("Используем системную libiconv из /usr/lib")
        LIBS += -L/usr/lib/x86_64-linux-gnu -liconv
        INCLUDEPATH += /usr/include
    }
}


SOURCES += \
    ../lib/qcustomplot/qcustomplot.cpp \
    configparser.cpp \
    connectionbank.cpp \
    convert1251.cpp \
    customgraph.cpp \
    databaseconfig.cpp \
    dialogprogress.cpp \
    main.cpp \
    mainwindow.cpp \
    second_window.cpp \
    writefile.cpp

HEADERS += \
    ../lib/qcustomplot/qcustomplot.h \
    configparser.h \
    connectionbank.h \
    container.h \
    convert1251.h \
    customgraph.h \
    databaseconfig.h \
    dialogprogress.h \
    mainwindow.h \
    second_window.h \
    writefile.h


FORMS += \
    customgraph.ui \
    dialogprogress.ui \
    mainwindow.ui \
    second_window.ui

target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc

DISTFILES += \
    image/Без названия.png

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

