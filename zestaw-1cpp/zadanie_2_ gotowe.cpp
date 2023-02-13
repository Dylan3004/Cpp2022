#include <iostream>

using namespace std;

int main()
{
    char ciag1[1000];
    char ciag2[1000];
    bool same;
    cout << "wpisz dane wyrazenie: ";
    //cin>>ciag1;
    cin.getline(ciag1, 999);
    cout << "wprowadz drugie wyraenie: ";
    cin.getline(ciag2, 999);
    int i = 0;
    while (ciag2[i] != NULL)
    {
        ciag1[i] = tolower(ciag1[i]);
        ciag2[i] = tolower(ciag2[i]);
        i++;
    }
    int j = 0;
    same = true;
    while (ciag1[j] != NULL)
    {
        if (ciag1[j] != ciag2[j])
        {
            same = false;
        }
        j++;
    }
    if (same)
        cout << "sa takie same";
    else
        cout << "nie sa takie same";
}