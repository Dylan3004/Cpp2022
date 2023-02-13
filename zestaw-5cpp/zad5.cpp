//
// Created by DW on 2022-06-15.
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
#include<list>
#include <set>
using namespace std;
auto lambda =[](const auto& a,const auto& b)->bool
{
    list<char> lista ={'a','c','b','d','f','e','h','g'};
    auto dist=find(lista.begin(),lista.end(),a);
    auto fin=distance(lista.begin(),dist);
    auto dist2=find(lista.begin(),lista.end(),b);
    auto fin1 = distance(lista.begin(),dist2);
    return fin<fin1;

    };

int main()
{
    list<char> lista ={'a','c','b','d','f','e','h','g'};

    set<char,decltype (lambda)> mySet ({'a', 'a' , 'a', 'g', 'c', 'b', 'f', 'h', 'c', 'e', 'd', 'e'},lambda);
    for (auto c:mySet) cout << c ;

}

