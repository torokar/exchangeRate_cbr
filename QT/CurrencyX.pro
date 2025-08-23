QT += core gui widgets sql xml concurrent testlib printsupport
CONFIG += c++17 qtestlib warn_on

TARGET = Currence


#--------------------------------------------------
# Тестовые файлы
#--------------------------------------------------
TESTSOURCES += tst_Graphics2DHistogrammTest.cpp
TESTHEADERS += TestGraph.h


#--------------------------------------------------
# PostgresSQL
#--------------------------------------------------

unix {
    LIBS += -L/usr/lib/x86_64-linux-gnu -lpq
    INCLUDEPATH += /usr/include/postgresql

    # Проверка наличия libpq
    !exists(/usr/lib/x86_64-linux-gnu/libpq.so) {
        error("libpq не найден! Установите: sudo apt install libpq-dev")
    }
}

#--------------------------------------------------
# CURL
#--------------------------------------------------

unix {
    LIBS += -lcurl
    message("Используется системный curl")
}

#--------------------------------------------------
# libpqxx
#--------------------------------------------------

# Пути к libpqxx
LIBPQXX_INSTALL_DIR =  /home/andreyonkhonov/clone/exchangeRate_cbr/lib/libpqxx-install
exists($$LIBPQXX_INSTALL_DIR) {`
    INCLUDEPATH += $$LIBPQXX_INSTALL_DIR/include
    LIBS += -L$$LIBPQXX_INSTALL_DIR/lib -lpqxx
    message("Подключен libpqxx из: $$LIBPQXX_INSTALL_DIR")
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
        message("Плагин платформы: $$platformPlugin.file")
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
        message("Используем системную libiconv из /usr/local/lib")
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
    customgraph.cpp \
    main.cpp \
    mainwindow.cpp \
    second_window.cpp

HEADERS += \
    ../lib/qcustomplot/qcustomplot.h \
    DATABASE.h \
    config_parser.h \
    connection_cb.h \
    container.h \
    convertCP1251.h \
    customgraph.h \
    mainwindow.h \
    second_window.h \
    write_to_file.h


FORMS += \
    customgraph.ui \
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

