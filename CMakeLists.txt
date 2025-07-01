cmake_minimum_required(VERSION 3.10)

# Укажите название проекта
project(ExchangeRateCbr)

# Укажите стандарт C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Укажите исходные файлы
file(GLOB SOURCES "*.cpp")  # Находит все .cpp файлы в корне проекта

# Создайте исполняемый файл
add_executable(ExchangeRateCbr ${SOURCES})

# Если у вас есть зависимости, добавьте их здесь
# Например, если вы используете cURL:
find_package(CURL REQUIRED)
target_link_libraries(ExchangeRateCbr PRIVATE CURL::libcurl)
