QT += core gui widgets sql xml concurrent testlib printsupport
CONFIG += c++17 qtestlib warn_on

TARGET = Currence


#--------------------------------------------------
# CURL
#--------------------------------------------------

unix {
    # Используем pkg-config для автоматического определения путей
    CONFIG += link_pkgconfig
    PKGCONFIG += libcurl

    # Добавляем стандартные пути для совместимости
    INCLUDEPATH += /usr/include/x86_64-linux-gnu
    INCLUDEPATH += /usr/include
}

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


CONFIG += link_pkgconfig
PKGCONFIG += libpqxx


INCLUDEPATH += $$LIBPQXX_INSTALL_DIR/include

LIBS += -lpqxx -lpq

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
    qlineeditforusers.cpp \
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
    qlineeditforusers.h \
    second_window.h \
    writefile.h


FORMS += \
    customgraph.ui \
    dialogprogress.ui \
    mainwindow.ui \
    qlineeditforusers.ui \
    second_window.ui

target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc

DISTFILES += \
    ../../../Загрузки/ex140_01.rar \
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

