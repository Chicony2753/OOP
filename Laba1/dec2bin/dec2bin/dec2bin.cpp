#include <iostream>
#include <sstream>

using namespace std;

void print(int dec)
{
    if (dec)
    {
        print(dec >> 1);
        cout << (dec & 1);
    }
}

bool check(char num)
{
    if ((num >= '0') && (num <= '9'))
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cout << "Invalid arguments count\n";
        cout << "dec2bin.exe <decimalNumber>\n";
        return 1;
    }

    string decimalString = argv[1];
    int decimalNum = 0;
    int bigNum = pow(2, 31) - 1;
    stringstream convertStr;
    convertStr << decimalString;
    convertStr >> decimalNum;

    for (int i = 0; i < decimalString.size(); i++)
    {
        if (!check(decimalString[i]))
        {
            cout << "Enter only integer number";
            return 1;
        }
    }

    if (decimalString == "0")
    {
        cout << "0";
        return 1;
    }

    if (decimalNum >= bigNum)
    {
        cout << "Number greater than 2^32-1";
        return 1;
    }

    print(decimalNum);
    return 0;
}
