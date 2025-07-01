cmake_minimum_required(VERSION 3.10)

# Укажите название проекта
project(ExchangeRateCbr)

# Укажите стандарт C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Укажите путь к библиотеке pqxx
set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/pqxx")

# Укажите исходные файлы
file(GLOB SOURCES "*.cpp")  # Находит все .cpp файлы в корне проекта

# Найдите библиотеки cURL и libpqxx
find_package(CURL REQUIRED)
find_package(PQXX REQUIRED)

# Создайте исполняемый файл
add_executable(ExchangeRateCbr ${SOURCES})

# Свяжите исполняемый файл с библиотеками cURL и libpqxx
target_link_libraries(ExchangeRateCbr PRIVATE CURL::libcurl pqxx)
