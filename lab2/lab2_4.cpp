#include <iostream> // подключаем библиотеку для ввода и вывода данных
using namespace std; // используем пространство имён std, чтобы не писать std:: перед cout и endl
#include "static_func.h"
using namespace MyFuncs;


int main() {
staticFunction(5);
staticFunction(10);
staticFunction(3);
return 0;
}


// Макрос для вычисления суммы двух чисел
#define SUM(a, b) ((a) + (b))


// Объявление функции с одной переменной, содержащей статическую переменную внутри
void staticFunction(int value) {
static int previous = 0; // статическая переменная сохраняет значение между вызовами функции
cout << "Сумма переданного числа и предыдущего: " << value + previous << endl; // вывод суммы текущего и предыдущего значений
previous = value; // сохраняем текущее значение в статическую переменную
}


int main() {
// Вызовы функции с разными параметрами для анализа поведения статической переменной
staticFunction(5);
staticFunction(10);
staticFunction(3);


// Пример использования макроса SUM
int result = SUM(7, 8);
cout << "Сумма через макрос SUM: " << result << endl;


return 0;
}