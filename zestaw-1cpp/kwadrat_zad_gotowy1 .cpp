#include <iostream>

using namespace std;

int gwiazdki;
int pusty;
string pustyl = "";
string pustyp = "";
string scianal = "";
string scianap = "";
int i, j;
int x, y;
int main()
{
    cout << "wpisz liczbe gwiazdek dla danego boku: ";
    cin >> gwiazdki;
    while (gwiazdki < 1)
    {
        cout << "podaj dodatnia liczbe:";
        cin >> gwiazdki;
    }
    cout << "wpisz wielkosc przestrzeni pustej w srodku: ";
    cin >> pusty;
    while (pusty < 0)
    {
        cout << "wpisz ilczbe nieujemna: ";
        cin >> pusty;
    }
    int roznica = gwiazdki - pusty;
    int bok = roznica / 2;
    //stworzenie poziomej struktury kwadratu wewnetrznego
    for (int k = 0; k < pusty / 2; k++)
    {
        pustyl += " ";
        pustyp += " ";
    }
    if (pusty % 2 == 1)
    {
        pustyp += " ";
    }
    //tworzenie parametrow sciany kwadratu zewnetrznego
    int wielkosc_sciany = (gwiazdki - pusty) / 2;
    for (int l = 0; l < wielkosc_sciany; l++)
    {
        scianal += "*";
        scianap += "*";
    }
    if ((gwiazdki - pusty) % 2 == 1)
    {
        scianap += "*";
    }
    // os y
    //gorna czesc
    for (int j = 0; j < wielkosc_sciany; j++)
    {
        for (int i = 0; i < gwiazdki; i++)
        {
            cout << "*";
        }
        cout << endl;
    }
    if (wielkosc_sciany % 2 == 1)
    {
        wielkosc_sciany += 1;
    }
    //przestrzen kwadratu wewnetrznego
    for (int i = 0; i < pusty; i++)
    {
        cout << scianal << pustyl << pustyp << scianal;
    }
    //dolna czesc
    for (int j = 0; j < wielkosc_sciany; j++)
    {
        for (int i = 0; i < gwiazdki; i++)
            cout << "*" << endl;
    }
}