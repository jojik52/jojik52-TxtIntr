#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 4 || argc > 6) {
        cout << "Справочный материал." << endl <<
        "Использование: ./calculator -o operation n1 n2 [n3] [n4]" << endl <<
        "Где operation может быть:" << endl <<
        "  umn - для умножения всех операндов" << endl <<
        "  del - для деления (первого операнда на все остальные)" << endl;
        exit(0);
    }

    string operation = argv[2];

    if (operation == "umn") {
        double product = 1;
        for (int i = 3; i < argc; ++i) {
            product *= atof(argv[i]);
        }
        cout << "Произведение: " << product << endl;
    } else if (operation == "del") {
        double result = atof(argv[3]);
        for (int i = 4; i < argc; ++i) {
            double divisor = atof(argv[i]);
            if (divisor == 0) {
                cout << "Ошибка: Деление на ноль." << endl;
                return 1;
            }
            result /= divisor;
        }
        cout << "Результат деления: " << result << endl;
    } else {
        cout << "Неизвестная операция. Используйте 'mul' или 'div'." << endl;
    }

    return 0;
}
