#include <iostream>
#include "lab4_2.h"

using namespace std;

// Класс характеристик
class Characteristic {
private:
    double strength;
public:
    Characteristic(double s) : strength(s) {}

    double GetDamage(const Weapon& w) const {
        // Доступ к закрытому полю damage через дружбу
        return strength + w.damage;
    }
};

// Класс MyMath со статическими методами
class MyMath {
private:
    static int callCount; // счётчик вызовов

public:
    static double Add(double a, double b) {
        callCount++;
        return a + b;
    }
    static double Sub(double a, double b) {
        callCount++;
        return a - b;
    }
    static double Mult(double a, double b) {
        callCount++;
        return a * b;
    }
    static double Div(double a, double b) {
        callCount++;
        return (b != 0) ? a / b : 0;
    }

    static int getCallCount() {
        return callCount;
    }
};

// Инициализация статического поля
int MyMath::callCount = 0;

int main() {
    cout << "Проверка класса Weapon" << endl;
    Weapon sword("Меч", 50.0, 5.5);
    sword.printInfo();

    cout << "\nПроверка GET и SET" << endl;
    cout << "Имя: " << sword.getName() << endl;
    cout << "Урон: " << sword.getDamage() << endl;
    cout << "Вес: " << sword.getWeight() << endl;

    sword.setDamage(75.0);
    cout << "Новый урон: " << sword.getDamage() << endl;

    cout << "\nПроверка дружбы с Characteristic" << endl;
    Characteristic hero(25.0);
    cout << "Итоговый урон героя: " << hero.GetDamage(sword) << endl;

    cout << "\nПроверка MyMath" << endl;
    cout << "Сложение: " << MyMath::Add(5, 3) << endl;
    cout << "Вычитание: " << MyMath::Sub(10, 4) << endl;
    cout << "Умножение: " << MyMath::Mult(6, 7) << endl;
    cout << "Деление: " << MyMath::Div(20, 4) << endl;

    cout << "Количество вызовов MyMath: " << MyMath::getCallCount() << endl;

    cout << "\nКонец программы" << endl;
    return 0;
}
