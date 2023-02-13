#include <iostream>
#include <string>

using namespace std;

int main()
{
    string wyraz1;
    string wyrazodw;
    int dlugosc1 = 0;
    cout << "wprowadz wyrazenie: ";
    getline(cin, wyraz1);

    dlugosc1 = wyraz1.size();
    int dlugosc = dlugosc1;
    int j = 0;
    bool palindrom = true;

    while (wyraz1[j] != NULL)
    {
        wyraz1[j] = tolower(wyraz1[j]);
        j++;
    }
    //tworzenie ciagu odwrotnego
    for (int i = 0; i <= dlugosc; i++)
    {
        wyrazodw[i] = wyraz1[dlugosc1 - 1];
        dlugosc1 = dlugosc1 - 1;
    }
    //petla sprawdzajaca spacje i przesuwajaca przy spacji ciag o jedno miejsce
    for (int i = 0; i <= dlugosc; i++)
    {
        int b = i;
        if (isspace(wyrazodw[i]))
        {

            for (; b - 1 <= dlugosc; b++)
            {
                wyrazodw[b] = wyrazodw[b + 1];
            }
            b = i;
        }
        if (isspace(wyraz1[i]))
        {
            for (; b - 1 <= dlugosc; b++)
            {

                wyraz1[b] = wyraz1[b + 1];
            }
            b = i;
        }
        //sprawdzenie zgodnosci
        if (wyraz1[i] != wyrazodw[i])
        {
            cout << wyraz1[i];

            palindrom = false;
        }
    }

    if (palindrom == false)
    {
        cout << "to nie jest palindrom";
    }
    else
    {
        cout << "to jest palindrom";
    }
}