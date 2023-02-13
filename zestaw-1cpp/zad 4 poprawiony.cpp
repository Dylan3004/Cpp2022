#include <iostream>
#include <math.h>

using namespace std;
//rekurencja
int fib(int a)
{

    if (a == 1 || a == 0)
    {
        return a;
    }
    else
    {
        a = fib(a - 1) + fib(a - 2);
        return a;
    }
}
//iteracja
int fibfor(int a)
{
    int y = 1;
    int x = 0;
    int z = 0;

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
    return z;
}

int main()
{
    int a;
    cout << "wpisz dany numer liczby z ciągu fibboniaciego";
    cin >> a;
    while (a <= 0)
    {
        cout << "podaj dodatia liczbe";
        cin >> a;
    }
    cout << "podana liczby to (rec):";
    clock_t time1 = clock();
    for (int i = 1; i <= a; i++)
    {
        cout << "  " << fib(i);
    }
    cout << "\n";
    time1 = clock() - time1;
    cout << "czas pracy to (rec)" << (long double)time1 / CLOCKS_PER_SEC << "sekund";
    cout << "\n";
    cout << "podane liczby to (for):";
    clock_t time2 = clock();
    for (int d = 1; d <= a; d++)
    {
        cout << "  " << fibfor(d);
    }
    time2 = clock() - time1;
    cout << "\n";
    cout << "czas pracy to (for)" << (long double)time2 / CLOCKS_PER_SEC << "sekund";
}