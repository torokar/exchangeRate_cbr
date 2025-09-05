cmake_minimum_required(VERSION 3.16)
project(ExchangeRateCbr VERSION 1.0.0)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/./lib/qcustomplot
    ${CMAKE_CURRENT_SOURCE_DIR}/QT
)

include_directories(${CMAKE_SOURCE_DIR}/lib/qcustomplot)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Поиск Qt6
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets PrintSupport)

# Проверка, что все компоненты Qt6 найдены
if(NOT Qt6_FOUND)
    message(FATAL_ERROR "Qt6 not found!")
endif()

if(NOT Qt6PrintSupport_FOUND)
    message(WARNING "Qt6 PrintSupport not found! Trying alternative approach...")
    find_library(QT6_PRINTSUPPORT_LIBRARY NAMES Qt6PrintSupport PATHS /usr/lib/x86_64-linux-gnu)
    if(QT6_PRINTSUPPORT_LIBRARY)
        message(STATUS "Found Qt6PrintSupport: ${QT6_PRINTSUPPORT_LIBRARY}")
    else()
        message(FATAL_ERROR "Qt6PrintSupport library not found")
    endif()
endif()

# Используем pkg-config для поиска libpqxx
find_package(PkgConfig REQUIRED)
pkg_check_modules(PQXX REQUIRED libpqxx)

# Поиск CURL
find_package(CURL REQUIRED)
find_package(Iconv REQUIRED)

# Исходные файлы
file(GLOB SOURCES "QT/*.cpp")
list(REMOVE_ITEM SOURCES "QT/Progress.cpp")
file(GLOB HEADERS "QT/*.h")
file(GLOB FORMS "QT/*.ui")

# Создание исполняемого файла
add_executable(ExchangeRateCbr ${SOURCES} ${HEADERS} ${FORMS})
include_directories(${Iconv_INCLUDE_DIRS})

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/./lib/qcustomplot
)

# Подключение библиотек
target_link_libraries(ExchangeRateCbr PRIVATE 
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    CURL::libcurl 
    ${PQXX_LIBRARIES}
    ${Iconv_LIBRARIES}
    pq
)

# Добавляем Qt6PrintSupport, если найден
if(Qt6PrintSupport_FOUND)
    target_link_libraries(ExchangeRateCbr PRIVATE Qt6::PrintSupport)
elseif(QT6_PRINTSUPPORT_LIBRARY)
    target_link_libraries(ExchangeRateCbr PRIVATE ${QT6_PRINTSUPPORT_LIBRARY})
endif()

# Добавляем пути к заголовкам
target_include_directories(ExchangeRateCbr PRIVATE 
    ${PQXX_INCLUDE_DIRS}
    QT/
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib/qcustomplot
)

# Добавляем флаги компиляции
target_compile_options(ExchangeRateCbr PRIVATE 
    ${PQXX_CFLAGS_OTHER}
)
