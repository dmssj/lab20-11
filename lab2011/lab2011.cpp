#include <iostream>     //лаба арабские числа
#include <string> 
using namespace std;

string arab_rim(int num);
int rim_arab(string rim);
int main() {
    setlocale(LC_ALL, "RU");

    int arab_num;
    string rim_num;

    cout << "ввести арабское число для перевода в римские цифры: "; cin >> arab_num;
    cout << "римское число: " << arab_rim(arab_num) << endl;

    cout << "ввести римское число для перевода в арабские цифры: "; cin >> rim_num;
    cout << "арабское число: " << rim_arab(rim_num) << endl;

    return 0;
}

string arab_rim(int num) {
    string res = "";
    string rim_numbers[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    int arab_numbers[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

    for (int i = 0; i < 13; i++) {
        while (num >= arab_numbers[i]) {
            res += rim_numbers[i];
            num -= arab_numbers[i];
        }
    }

    return res;
}

int rim_arab(string rim) {
    int res = 0, prev_val = 0;

    for (int i = rim.length() - 1; i >= 0; i--) {
        int value = 0;
        if (rim[i] == 'I') value = 1;
        if (rim[i] == 'V') value = 5;
        if (rim[i] == 'X') value = 10;
        if (rim[i] == 'L') value = 50;
        if (rim[i] == 'C') value = 100;
        if (rim[i] == 'D') value = 500;
        if (rim[i] == 'M') value = 1000;


        if (value < prev_val) res -= value;
        else res += value;

        prev_val = value;
    }

    return res;
}