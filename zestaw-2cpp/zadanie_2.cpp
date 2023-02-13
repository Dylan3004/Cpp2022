//Zad4
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

int BeginSort(vector<int> &tab, int begin, int end)
{
    //wyznaczenie połowy
    //int pivot = tab[(end-begin)/2+begin];
    int half = (end - begin) / 2 + begin;
    int pivot = tab[half];
    while (begin <= end)
    {
        while (tab[begin] < pivot)
        {
            begin++;
        }
        while (tab[end] > pivot)
        {
            end--;
        }
        if (begin <= end)
        {
            swap(tab[begin++], tab[end--]);
        }
    }
    return begin;
}
void QuickSort(vector<int> &tab, int begin, int end)
{
    if (begin < end)
    {
        int c = BeginSort(tab, begin, end);

        //QuickSort(tab, begin, (c + 1)mod size.tab());
        QuickSort(tab, begin, c - 1);

        QuickSort(tab, c, end);
    }
    else
    {
        return;
    }
}

int main()
{
    vector<int> sort;
    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<int> distrib(1, 10000);
    for (int i = 0; i < 10000; i++)
    {
        sort.push_back(distrib(gen));
        cout << sort[i] << "  ";
    }
    cout << endl;

    QuickSort(sort, 0, sort.size() - 1);
    for (int i = 0; i < sort.size(); i++)
    {
        cout << sort[i] << "  ";
    }
}