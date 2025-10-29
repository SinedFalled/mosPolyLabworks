#include <iostream> // подключаем библиотеку для ввода и вывода

// Функция, которая возвращает 0, если число <= 0, иначе сумму чисел от 1 до n
int sumUpTo(int n = 1) {
    if (n <= 0) return 0; // если число 0 или отрицательное
    int sum = 0; // переменная для накопления суммы
    for (int i = 1; i <= n; ++i) { // цикл от 1 до n
        sum += i; // добавляем текущее число к сумме
    }
    return sum; // возвращаем результат
}

// Функция, принимающая 4 параметра, где 2 последних передаются по ссылке
void calculate(int a, int b, int &sumRef, int &prodRef) {
    sumRef = a + b; // записываем сумму в первую ссылку
    prodRef = a * b; // записываем произведение во вторую ссылку
}

int main() {
    // 1. Создаём двумерный массив 2x3
    int arr2D[2][3] = {{1, 2, 3}, {4, 5, 6}};

    // 2. Считаем сумму всех элементов
    int totalSum = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            totalSum += arr2D[i][j];
        }
    }
    std::cout << "Сумма всех элементов двумерного массива: " << totalSum << std::endl;

    // 3. Создаём одномерный массив из 3 элементов
    int arr1D[3];

    // 4. Заполняем его суммами столбцов
    for (int j = 0; j < 3; ++j) {
        arr1D[j] = arr2D[0][j] + arr2D[1][j];
    }

    // 5. Выводим получившийся одномерный массив
    std::cout << "Суммы столбцов: ";
    for (int i = 0; i < 3; ++i) {
        std::cout << arr1D[i] << " ";
    }
    std::cout << std::endl;

    // 6. Переменная float
    float num = 20.84f;

    // 7. Две ссылки на неё
    float &ref1 = num;
    float &ref2 = num;

    // 8. Изменяем значение через одну ссылку
    ref1 = 42.42f;

    // 9. Проверяем, что значение изменилось везде
    std::cout << "num: " << num << ", ref2: " << ref2 << std::endl;

    // 10–11. Проверка функции sumUpTo
    std::cout << "sumUpTo(5): " << sumUpTo(5) << std::endl;
    std::cout << "sumUpTo(): " << sumUpTo() << std::endl;

    // 12–14. Проверка функции calculate
    int a = 3, b = 4, sumResult = 0, prodResult = 0;
    calculate(a, b, sumResult, prodResult);
    std::cout << "Сумма: " << sumResult << ", Произведение: " << prodResult << std::endl;

    // 15. Переменная любого типа
    std::string text = "Пример переменной";
    std::cout << text << std::endl;

    // 16–18. Цикл с переменными внутри
    for (int i = 0; i < 3; ++i) {
        std::cout << "num в цикле: " << num << std::endl;
        int innerVar = i * 10; // новая переменная в теле цикла
        std::cout << "innerVar: " << innerVar << std::endl;
    }

    return 0;
}
