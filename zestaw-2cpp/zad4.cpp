#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>

using namespace std;
namespace fs = std::filesystem;

int main()
{

    string path;
    cout << "podaj sciezke do plliku: ";
    getline(cin, path);
    while (!fs::exists(path))
    {
        cout << "zla nazwa";
        getline(cin, path);
    }

    for (const auto &entry : fs::directory_iterator(path))
    {
        if (entry.is_regular_file())
        {
            cout << "nazwa pliku" << entry.path().filename() << endl;
            cout << "rozmiar plik" << entry.file_size() << endl;
        }
        cout << entry.path() << endl;
    }
}