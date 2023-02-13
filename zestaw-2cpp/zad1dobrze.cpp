#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    int column;
    int j;

    string str2;

    string str1;

    string out;

    cout << "Wpisz nazwe pliku: ";

    getline(cin, str2);

    cout << "Wpisz liczbe kolumn: ";

    cin >> column;
    //cout << str2;

    ofstream outfile;

    outfile.open(str2 + ".txt", ios::in);

    ifstream file(str2 + ".txt");

    //fstream();

    if (!file)
    {
        cout << "pliku nie ma ";
        exit(1);
    }
    else
    {
        while (!file.eof())
        {

            getline(file, str1);
            out += str1;
        }
        for (int i = 0; i < out.length(); i++)
        {
            j++;
            cout << out[i];
            if (j == column)
            {
                cout << endl;
                j = 0;
            }
        }
    }
}