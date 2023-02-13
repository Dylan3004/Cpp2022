//
// Created by DW on 2022-06-14.
//
#include<vector>
#include<iostream>
#include<algorithm>
#include <numeric>
#include <random>
#include <string>
#include <cstdlib>
#include <functional>
#include <numeric>
using namespace std;
int main () {
    vector<int> vec = {1, 2, 5, 8, 4, 3, 9, 0, 3, 6};


    auto sklejka = [](string name, int a) -> string{

        return  move(name) + "-" + to_string(a);
    };

    string a = accumulate(next(vec.begin()),vec.end(),to_string(vec[0]),sklejka);
    string c = accumulate(next(vec.begin()),vec.end(), to_string(vec[0]),sklejka);
    int wielkosc = a.length();

    for(int i=0;i<wielkosc;++i)
    {
        cout<<a[i];
    }

}