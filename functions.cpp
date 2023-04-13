#include "functions.h"
int InputEightNumber()
{
    bool ContainLetters(const string & input);
    bool IsDecimal(const string & input);

    int result;
    string input;
    bool flag;

    do{
        flag = true;
        cout << "Input an octal number: ";
        cin >> input;
        fflush(stdin);
        if(ContainLetters(input)|| IsDecimal(input))
        {
            flag = false;
            cout << "Incorrect input!" << endl;
            fflush(stdin);
        }
    }while(!flag);

    result = stoi(input.c_str());

    return result;
}
bool ContainLetters(const string & input)
{
    bool result = false;
    for(int i = 0; i < input.length(); i++)
        if(isalpha(input[i]))
            result = true;
    return result;
}
bool IsDecimal(const string & input)
{
    bool result = false;
    for(int i = 0; i < input.size(); i++)
        if(input[i]=='9'||input[i]=='8')
            result = true;
    return result;
}
void CreateNumbers(ThreeOctalNumbers & object)
{
    int ChooseFormat();

    for(int i = 0; i < 2; i++)
    {
        cout << endl << i + 1 << " OCTAL DIGIT" << endl;
        if(ChooseFormat()==1)
        {
            int decimal;
            cout << "INPUT DECIMAL NUMBER: ";
            cin >> decimal;
            Numeral_8 number(decimal, DECIMAL);
            switch (i){
                case 0:
                    object.N1 = number;
                    break;
                case 1:
                    object.N2 = number;
                    break;
                default:
                    break;
            }

        }
        else{
            Numeral_8 number(InputEightNumber());
            switch (i){
                case 0:
                    object.N1 = number;
                    break;
                case 1:
                    object.N2 = number;
                    break;
                default:
                    break;
            }
        }
    }

}

void IncrementOctalNumber(ThreeOctalNumbers &object) {
    cout << "N1 BEFORE INCREMENTATION: \n";
    object.N1.ShowInfo();

    ++object.N1;

    cout << endl << "N1 AFTER INCREMENTATION: \n";
    object.N1.ShowInfo();
    cout << endl;
}

int ChooseFormat()
{
    int choose;
    cout << "Choose format:\n1. Decimal\n2. Octal\nCHOOSE: ";
    cin >> choose;
    return choose;
}
void SumTwoOctalNumbers(ThreeOctalNumbers & object)
{
    object.N3 = object.N1 + object.N2;
    cout << "N3 = N1 + N2\n";
    object.ShowN3();
}
void ConvertValuesToBin(ThreeOctalNumbers & object)
{
    cout << "CONVERTION N3 TO BINARY(SHORT METHOD)\n";
    object.N3.ReformToBinary_TriadMethod();
    cout << object.N3.GetBinaryVersion() << endl;

    cout << endl << "CONVERTION N3 TO BINARY(LONGEST VERSION)\n";
    object.N3.ReformToBinary_LongestMethod();
    cout << object.N3.GetBinaryVersion() << endl;
}