//
// Created by Dawid on 11/05/2022.
//
#include<iostream>
using namespace std;

class overloded
{
public:
    int a=0;
    int x=0;
    friend overloded operator-(const overloded& obj,const overloded& obj1);
    friend overloded operator+(const overloded& obj,const overloded& obj1);
    friend overloded operator-( overloded obj);
    friend overloded operator+(const overloded& obj);
    overloded():a(0)
    {

    }
     overloded operator++()
    {
        overloded temp;
        temp.a=++a;
        return temp;
    }
    overloded operator++(int)
    {
        overloded temp;
        temp.a=a++;
        return temp;
    }
    overloded operator--()
    {
        overloded temp;
        temp.a=--a;
        return temp;
    }
    overloded operator--(int)
    {
        overloded temp;
        temp.a=a--;
        return temp;
    }
   
    
    
    void pokarz()
    {
        cout<<a<<endl;
    }
};      
        overloded operator-(const overloded& obj,const overloded& obj1)
    {
        overloded temp;
        temp.a = obj.a - obj1.a;
        return temp;
    }
     overloded operator+(const overloded& obj,const overloded& obj1)
    {
        overloded temp;
        temp.a = obj1.a + obj.a;
        return temp;
    }
    overloded operator-( overloded obj)
        {
            obj.a=-obj.a;
            return obj;
        }
    overloded operator+(const overloded& obj)
        {
            return obj;
        }
        
        



int main ()
{
    overloded p1,p2,p3;
    
    p1.pokarz();
    p2.pokarz();
    p2=++p1;
    p1=p2++;
    p1.pokarz();
    p2.pokarz();
    p3 = p1 + p2;
    p3.pokarz();
    p3= p1 - p2;
    p3.pokarz();
    -p3;
    p3.pokarz();
    +p3;
    p3.pokarz();
    //prezentacja
    //dodawanie z przodu dziala
    p2=++++++++p2;
    p2.pokarz();
    //nie dodaje 
    p2++++;
    p2.pokarz();
    //odejmuje poprawnie
    p2=------p2;
    p2.pokarz();
    //nie odejmuje zwraca przed inkrementacja ale tylko o 1
    p2------;
    p2.pokarz();
    
}