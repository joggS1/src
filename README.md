# Лабораторные работы

Данный репозиторий содержит лабораторные работы, выполненные в рамках курса по предмету "ПРОГРАММНОЕ ОБЕСПЕЧЕНИЕ СИСТЕМ РЕАЛЬНОГО ВРЕМЕНИ". Каждая лабораторная работа находится в отдельной папке и включает исходный код, инструкции по сборке и запуску, а также описание функционала.

## Список лабораторных работ

### [Лабораторная работа №1](./lab_1)
- **Описание**: Изучение основ программирования и базовых операций ввода-вывода.
- **Основной файл**: `main.c`
- **Функционал**: Программа выводит сообщение "Hello World".

### [Лабораторная работа №2](./lab_2)
- **Описание**: Работа с потоками. Программа создает два потока, которые выполняют задачи параллельно.
- **Основной файл**: `main.c`
- **Функционал**:
  - Первый поток выводит сообщение каждые 2 секунды, повторяя это 5 раз.
  - Второй поток выводит сообщение каждую секунду, повторяя это 5 раз.
  - Основной поток ожидает завершения работы потоков в течение 40 секунд.

### [Лабораторная работа №3](./lab_3)
- **Описание**: Взаимодействие клиента и сервера. Реализована клиент-серверная архитектура.
- **Основные файлы**: `client.c`, `server.c`
- **Функционал**:
  - Клиент отправляет сообщение серверу.
  - Сервер возвращает клиенту его сообщение, исключив из него все согласные буквы.
- **Индивидуальное задание**: Вариант 9.

### [Лабораторная работа №4](./lab_4)
- **Описание**: Изучение работы с таймерами и потоками.
- **Основной файл**: `lab_4.c`
- **Функционал**:
  - Создание потока, который выполняет задачу в течение 26 секунд.
  - Установка тайм-аутов для ожидания завершения потока (10 и 25 секунд).
  - Вывод сообщений о состоянии потока.
- **Результаты**: Пример выполнения программы представлен в файле `image.png`.

## Как использовать
1. Перейдите в папку с нужной лабораторной работой.
2. Ознакомьтесь с инструкцией в файле `README.md`.
3. Скомпилируйте и запустите программу, следуя предоставленным инструкциям.
