#include <string>
#include <iostream>

using namespace std;

// Объявляем класс Characteristic заранее, чтобы потом объявить дружбу
class Characteristic;

class Weapon {
private:
    string name;
    double damage;
    double weight;

public:
    // Конструкторы и деструктор
    Weapon(string n, double d, double w);
    Weapon();
    ~Weapon();

    // Методы
    void printInfo() const;

    bool isTooHeavy(double maxWeight) const;

    double totalWeight(const Weapon& other) const;
    double totalWeight(double otherWeight) const;

    // GET-методы
    string getName() const;
    double getDamage() const;
    double getWeight() const;

    // SET-метод
    void setDamage(double newDamage);

    // Дружба с классом Characteristic
    friend class Characteristic;
};
