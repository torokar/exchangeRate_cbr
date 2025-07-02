# 💱 КУРС ВАЛЮТ

[![C++ CI](https://github.com/torokar/exchangeRate_cbr/actions/workflows/ci.yml/badge.svg)](https://github.com/torokar/exchangeRate_cbr/actions/workflows/ci.yml)

Приложение на C++, которое получает курс валют с сайта Центрального Банка России, сохраняет данные в файл и базу данных PostgreSQL.

##  Возможности

- 📥 Получение XML-данных с сайта [ЦБ РФ](https://www.cbr.ru)
- 🧩 Парсинг XML и извлечение информации о валютах
- 🗃️ Запись данных в файл (`data_file/data.txt`)
- 🛢️ Отправка данных в PostgreSQL-базу (`mydb`, таблица `exdc`)

##  Технологии

- Язык: **C++**
- Сетевые запросы: **libcurl**
- Работа с БД: **libpqxx** (PostgreSQL C++ API)
- Кодировка: **iconv**

##  Установка и запуск

### 1. Установи зависимости

#### Ubuntu/Debian
```bash
sudo apt update
sudo apt install libcurl4-openssl-dev libpqxx-dev libpq-dev libiconv-hook-dev
```

### 2. Склонируй репозиторий
```bash
git clone https://github.com/torokar/exchangeRate_cbr.git
cd exchangeRate_cbr
```

### 3. Настрой PostgreSQL
```bash
CREATE DATABASE mydb;
CREATE USER service WITH PASSWORD '11111111';
GRANT ALL PRIVILEGES ON DATABASE mydb TO service;
```

### 4. Собери и запусти проект
```bash
g++ -std=c++17 -o exchangerate main.cpp -lpqxx -lpq -lcurl -liconv
./exchangerate
```
##  Планы на будущее
- Web-интерфейс для просмотра данных
- Поддержка разных форматов вывода (CSV, JSON)
 


















