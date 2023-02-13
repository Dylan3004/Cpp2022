#include <iostream>
#include <string>
using namespace std;

int main()
{
    int arab;
    string rzym;
    int pozycja = 0;
    int i = 0;

    cout << "wypisz liczbe arabska: ";
    cin >> arab;

    while (arab > 3999)
    {
        cout << "za duza wartosc , prosze wpisac ponownie";
        cin >> arab;
    }

    while (arab != 0)
    {

        if (arab >= 1000)
        {

            rzym += "M";
            arab -= 1000;
        }
        else if (arab >= 900)
        {

            rzym += "CM";
            i++;
            arab -= 900;
        }
        else if (arab >= 500)
        {

            rzym += "D";
            arab -= 500;
        }
        else if (arab >= 400)
        {

            rzym += "CD";
            i++;
            arab -= 400;
        }
        else if (arab >= 100)
        {

            rzym += "C";
            arab -= 100;
        }
        else if (arab >= 90)
        {

            rzym += "XC";
            i++;
            arab -= 90;
        }

        else if (arab >= 50)
        {

            rzym += "L";
            arab -= 50;
        }
        else if (arab >= 40)
        {

            rzym += "XL";
            i++;
            arab -= 40;
        }
        else if (arab >= 10)
        {

            rzym += "X";
            arab -= 10;
        }
        else if (arab >= 9)
        {

            rzym += "IX";
            i++;
            arab -= 9;
        }
        else if (arab >= 5)
        {

            rzym += "V";
            arab -= 5;
        }
        else if (arab >= 4)
        {
            rzym += "IV";
            i++;
            arab -= 4;
        }
        else if (arab >= 1)
        {
            rzym += "I";
            arab -= 1;
        }
        i++;
    }
    //int b = rzym.length();
    //cout<<b<<endl;

    for (int j = 0; j <= i; j++)
    {
        cout << rzym[j];
    }
    cin >> arab;
}