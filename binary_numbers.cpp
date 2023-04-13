
//ПЕРЕВЕДЕННЯ ВІСІМКОВОГО ЧИСЛА У ДВІЙКОВЕ

#include "binary_numbers.h"

string OctToBin(char number) {
    string result;
    switch(number){
        case '0':
            result = B_ZERO;
            break;
        case '1':
            result = B_ONE;
            break;
        case '2':
            result = B_TWO;
            break;
        case '3':
            result = B_THREE;
            break;
        case '4':
            result = B_FOUR;
            break;
        case '5':
            result = B_FIVE;
            break;
        case '6':
            result = B_SIX;
            break;
        case '7':
            result = B_SEVEN;
            break;
        default:
            result = "---";
            break;
    }

    return result;
}
