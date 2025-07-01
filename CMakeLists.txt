cmake_minimum_required(VERSION 3.10)

# название проекта
project(ExchangeRateCbr)

# Стандарт C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# директория для исходных файлов
include_directories(src)

# исходные файлы
file(GLOB SOURCES "src/*.cpp")

# исполняемый файл
add_executable(ExchangeRateCbr ${SOURCES})

# Зависимости, добавьте их здесь
# Например, если вы используете cURL:
find_package(CURL REQUIRED)
target_link_libraries(ExchangeRateCbr PRIVATE CURL::libcurl)
