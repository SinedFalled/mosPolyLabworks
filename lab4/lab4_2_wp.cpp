#include "lab4_2.h"

// Конструктор с параметрами
Weapon::Weapon(string n, double d, double w) : name(n), damage(d), weight(w) {
    cout << "Создано оружие: " << name << " (урон: " << damage << ", вес: " << weight << ")" << endl;
}

// Конструктор без параметров
Weapon::Weapon() : Weapon("Безымянное оружие", 10.0, 3.0) {
    cout << "Вызван конструктор без параметров." << endl;
}

// Деструктор
Weapon::~Weapon() {
    cout << "Удаляется оружие: " << name
         << " (урон: " << damage
         << ", вес: " << weight << ")" << endl;
}

// Вывод информации
void Weapon::printInfo() const {
    cout << "Название: " << name
         << ", Урон: " << damage
         << ", Вес: " << weight << endl;
}

// Проверка на вес
bool Weapon::isTooHeavy(double maxWeight) const {
    return weight > maxWeight;
}

// Суммарный вес (с перегрузкой)
double Weapon::totalWeight(const Weapon& other) const {
    return totalWeight(other.weight);
}

double Weapon::totalWeight(double otherWeight) const {
    return weight + otherWeight;
}

// GET-методы
string Weapon::getName() const { return name; }
double Weapon::getDamage() const { return damage; }
double Weapon::getWeight() const { return weight; }

// SET-метод
void Weapon::setDamage(double newDamage) {
    damage = newDamage;
}
