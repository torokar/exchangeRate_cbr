cmake_minimum_required(VERSION 3.10)

# Укажите название проекта
project(ExchangeRateCbr)

# Укажите стандарт C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Укажите исходные файлы
file(GLOB SOURCES "*.cpp")  # Находит все .cpp файлы в корне проекта

# Найдите библиотеку cURL
find_package(CURL REQUIRED)

# Создайте исполняемый файл
add_executable(ExchangeRateCbr ${SOURCES})

# Свяжите исполняемый файл с библиотекой cURL
target_link_libraries(ExchangeRateCbr PRIVATE CURL::libcurl)
