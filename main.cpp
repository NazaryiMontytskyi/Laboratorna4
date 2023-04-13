#include "functions.h"

int main() {
    ThreeOctalNumbers octal_digits;
    CreateNumbers(octal_digits);

    octal_digits.ShowN1();
    octal_digits.ShowN2();

    IncrementOctalNumber(octal_digits);
    SumTwoOctalNumbers(octal_digits);
    ConvertValuesToBin(octal_digits);

    return 0;
}
