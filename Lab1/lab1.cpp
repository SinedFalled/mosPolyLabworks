#include <iostream> // подключаем заголовок для ввода/вывода
#include <string> // подключаем заголовок для работы со строками std::string
#include <cstdint> // подключаем заголовок для фиксированных целочисленных типов (uint8_t и т.п.)
#include <clocale> // подключаем заголовок для setlocale и исправления кодировки консоли

int main() // точка входа в программу
{ // начало тела функции main
    std::setlocale(LC_ALL, ""); // устанавливаем локаль системы, чтобы корректно выводились кириллические символы

    // Задание 1 вывод строки
    std::cout << "First string" << std::endl; // выводим строку "First string" в консоль

    // Задание 2 вывод двух строк
    std::printf("%s\n", "Первая строка\nВторая строка"); // выводим сразу две строки через printf

    // Задание 3 спецсимволы
    std::cout << u8"Спецсимволы 1.\" \\" << std::endl; // выводим строку со спецсимволами

    // Задание 2.1,2,3 переменные int, float, минимальный тип
    int varInt = 150; // создаём переменную типа int со значением 150
    float varFloat = 15.933f; // создаём переменную типа float со значением 15.933
    uint8_t smallInt = 250; // выбираем тип с минимальным объёмом памяти, который поддерживает значение 250

    // Задание 2.4 вывод переменных
    std::cout << "varInt" << std::endl << std::endl << varInt << std::endl; // вывод имени и значения
    std::cout << "varFloat" << std::endl << std::endl << varFloat << std::endl;
    std::cout << "smallInt" << std::endl << std::endl << static_cast<int>(smallInt) << std::endl; // для uint8_t приводим к int

    // Задание 2.5 дата рождения
    int birthDay = 1; // день рождения
    std::string birthMonth = "января"; // месяц рождения
    int birthYear = 2000; // год рождения

    std::cout << "Моя дата рождения: " << birthDay << " " << birthMonth << " " << birthYear << " года" << std::endl;

    // Задание 2.6 константы
    const double CONST_NUM = 2.3; // числовая константа
    const char CONST_OS[] = "WINDOWS"; // строковая константа

    // Задание 2.7 вывод констант
    std::cout << CONST_NUM << " " << CONST_OS << std::endl;

    return 0; // завершение
}

