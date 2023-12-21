#include <iostream>
#include <sstream>

using namespace std;

// Структура для представления дроби
struct Fraction {
    int numerator;
    int denominator;
};

// Функция для вычисления НОД
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Функция для сокращения дроби
void simplifyFraction(Fraction& fraction) {
    int commonDivisor = gcd(fraction.numerator, fraction.denominator);
    fraction.numerator /= commonDivisor;
    fraction.denominator /= commonDivisor;
}

int main() {
    // Входная строка
    string N = "10/26 + 5/152";

    // Выделяем из строки числа
    istringstream iss(N);

    // Переменные для временного хранения чисел и символов
    int num1, denom1, num2, denom2;
    char slash;
    char plus;

    // Определяем первую дробь
    iss >> num1 >> slash >> denom1;

    // Определяем '+' и вторую дробь
    iss >> plus >> num2 >> slash >> denom2;

    // Сумма дробей
    Fraction sum = {
        num1 * denom2 + num2 * denom1,
        denom1 * denom2
    };

    // Сокращение при возможности
    simplifyFraction(sum);

    // Результат
    cout << sum.numerator << '/' << sum.denominator << endl;

    return 0;
}
