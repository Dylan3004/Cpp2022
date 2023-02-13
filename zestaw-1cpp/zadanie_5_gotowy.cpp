#include <iostream>
#include <math.h>

using namespace std;
unsigned long long wyniki[200];
int fib(int a)
//dodalem tablice do wpisywania zaistnialych juz wynikow
{
    if (a == 1 || a == 0)
    {
        return a;
    }
    else
    {
        if (wyniki[a] != NULL)
        {
            a = wyniki[a];
        }
        else
        {
            int b = a;
            a = fib(a - 1) + fib(a - 2);
            wyniki[b] = a;
        }
        return a;
    }
}
int fibfor(int a)
{
    int z = 0;
    if (wyniki[a] != NULL)
    {
        z = wyniki[a];
    }
    else
    {
        int y = 1;
        int x = 0;

        if (a == 1)
            return a;

        for (int j = 1; j < a; j++)
        {
            //obecna
            z = x + y;
            //poprzednia
            x = y;
            // dwie temu
            y = z;
        }
    }
    return z;
}

int main()
{
    int a;
    cout << "wpisz dany numer liczby z ciągu fibboniaciego: ";
    cin >> a;
    while (a < 0)
    {
        cout << "podaj nieujemna liczbe";
        cin >> a;
    }
    cout << "podana liczby to (rec):";

    for (int i = 1; i <= a; i++)
    {
        cout << "  " << fib(i);
    }
    cout << "\n";
    cout << "podane liczby to (for):";
    for (int d = 1; d <= a; d++)
    {
        cout << "  " << fibfor(d);
        int g;
    }
}