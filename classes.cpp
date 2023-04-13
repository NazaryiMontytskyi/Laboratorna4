#include "classes.h"

void Numeral_8::SetNumber(int eight_number) {
    this->eight_number = eight_number;
}

int Numeral_8::GetNumber() {
    return this->eight_number;
}

void Numeral_8::ReformToBinary_TriadMethod() {
    string result = "";
    string number_str = to_string(eight_number);
    for(int i = 0; i < number_str.length(); ++i)
    {
        result += OctToBin(number_str[i]);
        result += " ";
    }


    binary_number = result;
}

string Numeral_8::GetBinaryVersion() {
    return this->binary_number;
}

void Numeral_8::ReformToBinary_LongestMethod() {
    int radix = 1;
    int counter = 0;
    string result = "";
    int tmp = GetDecimalNumber();
    for(int i = 0; radix < tmp; i++)
    {
        radix = (int)pow(2, i);
        counter++;
    }
    radix = radix / 2;

    while(radix)
    {
        if(tmp >= radix)
        {
            result += "1";
            tmp -= radix;
        }
        else
            result += "0";

        radix = radix / 2;
    }
    this->binary_number = result;
}

int Numeral_8::GetDecimalNumber() {
    return this->decimal;
}

Numeral_8 Numeral_8::operator+(const Numeral_8 & other) {
    Numeral_8 result;

    int first = 0;
    int second = 0;
    int decimal_result = 0;

    first = this->decimal;
    second = other.decimal;

    decimal_result = first + second;
    result.DecToOct(decimal_result);
    result.SetDecimal();
    return result;
}

void Numeral_8::DecToOct(int decimal_num) {
    int remainder, quotient, i = 1, octal_num = 0;

    quotient = decimal_num;

    while (quotient != 0) {
        remainder = quotient % 8;
        octal_num += remainder * i;
        i *= 10;
        quotient /= 8;
    }

    eight_number = octal_num;
}

void Numeral_8::SetDecimal() {
    bool flag = true;
    int radix;
    int sum = 0;
    for(int i = 0; flag ;i++)
    {
        if(radix/(int)(pow(10,i)!=0))
        {
            radix = eight_number % (int)(pow(10,i + 1));
            radix = radix / (int)(pow(10,i));
            sum += radix * pow(8, i);
        }
        else
            flag = false;
    }
    this->decimal = sum;
}

void Numeral_8::operator++() {
    this->decimal = this->GetDecimalNumber() + 1;
    this->DecToOct(this->decimal);
}

void Numeral_8::operator+=(const int value) {
    int number = this->GetDecimalNumber();
    number += value;
    this->DecToOct(number);
    this->SetDecimal();
}

Numeral_8::Numeral_8(int number): eight_number(number) {
    SetDecimal();
}

Numeral_8::Numeral_8(int decimal, string mode) {
    if(mode == DECIMAL)
    {
        this->decimal = decimal;
        DecToOct(decimal);
    }
}

void Numeral_8::ShowInfo() {
    cout << "OCTAL: " << this->GetNumber() << endl;
    cout << "DECIMAL: " << this->GetDecimalNumber() << endl;
    if(!this->binary_number.empty())
        cout << "BINARY: " << this->binary_number << endl;
}

void ThreeOctalNumbers::ShowN1() { cout << endl << "N1\n"; N1.ShowInfo(); cout << endl; }
void ThreeOctalNumbers::ShowN2() { cout << endl << "N2\n"; N2.ShowInfo(); cout << endl; }
void ThreeOctalNumbers::ShowN3() { cout << endl << "N3\n"; N3.ShowInfo(); cout << endl; }
