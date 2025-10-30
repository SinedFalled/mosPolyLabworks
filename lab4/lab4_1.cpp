#include <iostream>
#include <string>

using namespace std;

class Weapon {
private:
    string name;
    double damage;
    double weight;

public:
    // Конструктор с параметрами
    Weapon(string n, double d, double w) : name(n), damage(d), weight(w) {
        cout << "Создано оружие: " << name << " (урон: " << damage << ", вес: " << weight << ")" << endl;
    }

    // Конструктор без параметров — вызывает основной конструктор
    Weapon() : Weapon("Безымянное оружие", 10.0, 3.0) {
        cout << "Вызван конструктор без параметров." << endl;
    }

    // Деструктор
    ~Weapon() {
        cout << "Удаляется оружие: " << name
             << " (урон: " << damage
             << ", вес: " << weight << ")" << endl;
    }

    // Метод для вывода данных
    void printInfo() const {
        cout << "Название: " << name
             << ", Урон: " << damage
             << ", Вес: " << weight << endl;
    }

    // Проверка, может ли кто-то поднять оружие
    bool isTooHeavy(double maxWeight) const {
        return weight > maxWeight;
    }

    // Суммарный вес (с другим оружием)
    double totalWeight(const Weapon& other) const {
        // используем перегрузку
        return totalWeight(other.weight);
    }

    // Перегрузка метода — принимает просто вес
    double totalWeight(double otherWeight) const {
        return weight + otherWeight;
    }
};

int main() {
    cout << "Создание объектов" << endl;
    Weapon sword("Меч", 50.0, 5.5);
    Weapon defaultWeapon;

    cout << "\nИнформация об оружbb" << endl;
    sword.printInfo();
    defaultWeapon.printInfo();

    cout << "\nПроверка деструктора" << endl;
    {
        Weapon axe("Топор", 70.0, 7.8);
        axe.printInfo();

        Weapon* spear = new Weapon("Копьё", 40.0, 4.2);
        spear->printInfo();

        cout << "\nУдаляем динамический объект" << endl;
        delete spear; // важно!
    }

    cout << "\nПроверка методов" << endl;
    cout << "Слишком ли тяжёл меч для персонажа с пределом 4 кг? "
         << (sword.isTooHeavy(4.0) ? "Да" : "Нет") << endl;

    cout << "Суммарный вес меча и оружия по умолчанию: "
         << sword.totalWeight(defaultWeapon) << " кг" << endl;

    cout << "Суммарный вес меча и произвольного веса (2 кг): "
         << sword.totalWeight(2.0) << " кг" << endl;

    cout << "\nКонец программы" << endl;
    return 0;
}
