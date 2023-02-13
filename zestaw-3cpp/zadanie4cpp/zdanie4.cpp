#include<iostream>
#include<vector>
using namespace std;
template <class T>
class Tsmartpointer
{
public:
    T* a;
    explicit Tsmartpointer(T* x = NULL)
    {
        a=x;
    }
    ~Tsmartpointer()
    {
        delete (a);
    }
    T* operator ->()
    {

        return a;
    }
    T& operator *()
    {
        return *a;
    }
    int fun()
    {
        //int *b = a;
        return 5+(*a);
    }
};


int main ()
{
    Tsmartpointer<int> ptr(new int());
    *ptr=10;
    cout << *ptr << endl;
    Tsmartpointer<vector<int> > ptr2(new vector<int>);
    ptr2->push_back(123);
    cout << ptr2->front() << endl;
}
