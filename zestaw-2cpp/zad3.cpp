#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <initializer_list>
#include <iterator>

using namespace std;

auto fun(const auto &arg)
{

    auto *i = arg.begin();
    auto add = 0;
    for (; i != arg.end(); i++)
    {
        add += *i;
    }
    return add;
}

int main()
{
    initializer_list<int> a = {20, 30, 40};
    cout << fun(a);
    initializer_list<double> b = {3.4, 5.43, 7.5432};
    cout << fun(b);
}