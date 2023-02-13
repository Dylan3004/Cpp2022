//
// Created by DW on 2022-06-14.
//
#include<vector>
#include<iostream>
#include<algorithm>
#include <numeric>
#include <random>
#include <string>
#include <stdlib.h>
using namespace std;


auto sortuj2 = [](int& a, int& b)->bool {
    string x = to_string(a);
    string y = to_string(b);
    return x.compare(y) <= 0;
};

    auto sortuj=[](int &a,int&b) -> bool
    {
        return a>b;
    };

int main()
{
    std::random_device rd;
    mt19937 g(rd());
    vector <int> vec(100);
    iota(vec.begin(),vec.end(),1);
    cout<<"wstawianie liczb w wektorze";
    for(int i =0;i<100;i++)
    {
        cout<<"  "<<vec[i];
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"pomieszanie liczb w wektorze";
    shuffle(vec.begin(),vec.end(), g);
    for(int i =0;i<100;i++)
    {
        cout<<"  "<<vec[i];
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Sortowanie od najwiekszej";
    sort(vec.begin(),vec.end(),greater<int>());
    for(int i =0;i<100;i++)
    {
        cout<<"  "<<vec[i];
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Ponowne przemieszanie i uzycie sortowania lambda";
    shuffle(vec.begin(),vec.end(), g);
    sort(vec.begin(),vec.end(), sortuj);
    for(int i =0;i<100;i++)
    {
        cout<<"  "<<vec[i];
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Ponowne przemieszanie i uzycie sortowania lambda z orientacja pierwszej liczby";
    sort(vec.begin(),vec.end(), sortuj2);
    for(int i =0;i<100;i++)
    {
        cout<<"  "<<vec[i];
    }




}


