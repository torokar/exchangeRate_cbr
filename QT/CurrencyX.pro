QT += core gui widgets sql
CONFIG += c++17

TARGET = YourAppName

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

CURL_INSTALL_DIR = /media/andreyonkhonov/DATA/lib/curl-8.8.0/installCurl

INCLUDEPATH += $$CURL_INSTALL_DIR/include

LIBS += -L$$CURL_INSTALL_DIR/lib -lcurl

#--------------------------------------------------
# libpqxx
#--------------------------------------------------

# Пути к libpqxx
LIBPQXX_INSTALL_DIR =  /media/andreyonkhonov/DATA/Development/libs/libpqxx-install/
exists($$LIBPQXX_INSTALL_DIR) {
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

    # Копирование плагина xcb при сборке
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

unix {
    # Проверяем существование библиотеки
    !exists(/usr/local/lib/libiconv.so) {
        warning("libiconv не найден в /usr/local/lib!")
    }

    # Проверяем заголовочный файл
    !exists(/usr/local/include/iconv.h) {
        warning("iconv.h не найден в /usr/local/include!")
    }
}

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    DATABASE.h \
    container.h \
    mainwindow.h \
    write_to_file.h

FORMS += \
    mainwindow.ui

target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
