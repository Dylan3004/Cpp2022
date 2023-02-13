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
#include<list>
#include <map>
using namespace std;

int main ()
{
    map<int, string> mis ={{0,"zero"},{1,"jeden"},{2,"dwa"},{3,"trzy"},{4,"cztery"},{5,"piec"},{6,"szesc"},{7,"siedem"},{8,"osiem"},{9,"dziewiec"}};
    vector <int> vec(9);
    iota(vec.begin(),vec.end(),1);


    transform(vec.begin(),vec.end(),std::ostream_iterator<string>(cout, " "),[mis](int a)
    {
        return  mis.at(a);
    });
}
