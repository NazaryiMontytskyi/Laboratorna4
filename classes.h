#ifndef LAB4OP_CLASSES_H
#define LAB4OP_CLASSES_H

#endif //LAB4OP_CLASSES_H


#include <cstring>
#include <cmath>
#include "binary_numbers.h"

class Numeral_8{
private:
    int eight_number;
    string binary_number;
    int decimal;
public:
    Numeral_8() = default;
    Numeral_8(int);
    Numeral_8(int, string);//конструктор класу із можливістю режиму введення
    void SetNumber(int);
    int GetNumber();
    int GetDecimalNumber();
    void SetDecimal();
    void ReformToBinary_TriadMethod();//переведення у двійкове скороченим методом
    void ReformToBinary_LongestMethod();//переведення у двійкове довшим методом
    void DecToOct(int);//переведення з десяткового в вісімкове
    string GetBinaryVersion();
    Numeral_8 operator+(const Numeral_8 & other);
    void operator++();
    void operator+=(const int);
    void ShowInfo();
};

struct ThreeOctalNumbers{ //допоміжна структура для виконання завдання
    Numeral_8 N1;
    Numeral_8 N2;
    Numeral_8 N3;

    void ShowN1();
    void ShowN2();
    void ShowN3();
};