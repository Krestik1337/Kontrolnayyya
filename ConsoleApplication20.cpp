#include <iostream>
#include <fstream>
#include <clocale>
#include "Header.h"

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "Объектов создано (до начала работы): " << Kvartira::getCount() << "\n\n";

    std::ifstream fin("kvartiry.txt");
    if (!fin.is_open()) {
        std::cout << "Не удалось открыть файл kvartiry.txt\n";
        return 1;
    }

    int n = 0;
    fin >> n;
    if (n <= 0) {
        std::cout << "В файле нет записей.\n";
        fin.close();
        return 0;
    }

    Kvartira* arr = new Kvartira[n];

    std::cout << "Объектов создано (после выделения памяти): " << Kvartira::getCount() << "\n\n";

    for (int i = 0; i < n; i++) {
        if (!arr[i].readFromFile(fin)) {
            std::cout << "Ошибка чтения записи #" << i + 1 << "\n";
            fin.close();
            delete[] arr;
            return 1;
        }
    }
    fin.close();

    std::cout << "Все квартиры\n";
    for (int i = 0; i < n; i++) {
        std::cout << i + 1 << ". ";
        arr[i].print();
    }

    std::cout << "\nКвартиры в Центральном районе\n";
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].isCentral()) {
            arr[i].print();
            found++;
        }
    }
    if (found == 0) {
        std::cout << "Таких квартир нет.\n";
    }

    delete[] arr;

    std::cout << "\nОбъектов создано (после очистки памяти): " << Kvartira::getCount() << "\n";

    return 0;
}
