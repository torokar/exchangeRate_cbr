# 💱 Курс Валют - Currency Exchange Rates

[![C++ CI](https://github.com/torokar/exchangeRate_cbr/actions/workflows/ci.yml/badge.svg)](https://github.com/torokar/exchangeRate_cbr/actions/workflows/ci.yml)

Приложение на C++/Qt для получения и анализа курсов валют с сайта Центрального Банка России с графическим интерфейсом.

## 🌟 Возможности

- 📥 **Автоматическое получение** XML-данных с сайта [ЦБ РФ](https://www.cbr.ru)
- 🧩 **Парсинг и обработка** данных о валютах в реальном времени
- 📊 **Графическое отображение** курсов валют с интерактивным графиком
- 🗃️ **Сохранение данных** в текстовые файлы и XML
- 🛢️ **Интеграция с PostgreSQL** - автоматическое сохранение в базу данных
- 📅 **Гибкий выбор даты** - получение исторических данных

## 📸 Скриншоты

![Главное окно](https://github.com/torokar/exchangeRate_cbr/blob/master/screenshots/Снимок%20экрана%20от%202025-09-09%2013-22-01.png)

*Главное окно приложения*

![График валют](https://github.com/torokar/exchangeRate_cbr/blob/master/screenshots/Снимок%20экрана%20от%202025-09-09%2013-23-21.png)

*Интерактивный график курсов валют*

![Таблица данных](https://github.com/torokar/exchangeRate_cbr/blob/master/screenshots/Снимок%20экрана%20от%202025-09-09%2013-22-44.png)

*Таблица с подробными данными о валютах*

## 🛠 Технологии

- **Язык программирования**: C++17
- **Графический фреймворк**: Qt 5.15
- **Сетевые запросы**: libcurl
- **База данных**: PostgreSQL + libpqxx
- **Работа с кодировками**: iconv
- **Графики**: QCustomPlot
- **Сборка**: QMake/CMake

## 📦 Установка и запуск

### Предварительные требования
#### Ubuntu/Debian
```bash
sudo apt update
sudo apt install qtbase5-dev qt5-qmake libcurl4-openssl-dev \
    libpqxx-dev libpq-dev libiconv-hook-dev
```

## 🛢️ PostreSQL Настройка 
    sudo -u postgres psql
    CREATE DATABASE mydb;
    CREATE USER service WITH PASSWORD '11111111';
    GRANT ALL PRIVILEGES ON DATABASE mydb TO service;

## Сборка
    git clone https://github.com/torokar/exchangeRate_cbr.git
    cd exchangeRate_cbr
    cd QT
    qmake
    make
    ./Currence

## ⚙️ Конфигурация базы данных

Приложение автоматически использует следующие параметры подключения:

    Хост: localhost

    Порт: 5432

    База данных: mydb

    Пользователь: service

    Пароль: 11111111

Форматы данных
    Входные данные: XML с сайта ЦБ РФ
    Выходные данные: Текстовые файлы, XML, PostgreSQL, интерактивная таблица и графики

## 🤝 Участие в разработке
Мы приветствуем contributions! Чтобы внести свой вклад:

    Склонируйте репозиторий

    Создайте feature branch (git checkout -b feature/amazing-feature)

    Закоммитьте изменения (git commit -m 'Add amazing feature')

    Запушьте branch (git push origin feature/amazing-feature)

    Откройте Pull Request

## 👥 Авторы

Андрей Онхонов - https://github.com/torokar

Давид Скакодуб - https://github.com/D-SKills


