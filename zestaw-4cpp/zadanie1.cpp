//
// Created by DW on 2022-06-05.
//
#include <iostream>
using namespace std;
#define P(x) std::cout << x << std::endl
class A1 {
    int i { 5 };
public:
    A1(bool) { P("A1 c-tor"); }
    virtual ~A1() { P("A1 d-tor"); }
    int get() const { return i; }
};





class V1 : virtual public A1 { public:
    V1(bool) : A1(true) { P("V1 c-tor"); }
    virtual ~V1() override { P("V1 d-tor"); }
};





class C1 : virtual public V1{
    int i { 5 };
public:
    C1( bool) : A1(true), V1(true) { P("C1 c-tor"); }
    virtual ~C1() override { P("C1 d-tor"); }
    int get() const { return i; }
};





class B2{
    int i { 5 };
public:
    B2(bool) { P("B2 c-tor"); }
    virtual ~B2() { P("B2 d-tor"); }
    int get() const { return i; }
};





class B3{
    int i { 5 };
public:
    B3(bool) { P("B3 c-tor"); }
    virtual ~B3() { P("B3 d-tor"); }
    int get() const { return i; }
};





class V2 : virtual public A1, public B2{
    int i { 5 };
public:
    V2(bool) : B2(true), A1(true) { P("V2 c-tor"); }
    virtual ~V2() override { P("V2 d-tor"); }
    int get() const { return i; }
};





class C2 : virtual public V2, public B3{
    int i{ 5};
public:
    C2( bool) : B3(true), A1(true), V2(true) { P("A1 c-tor"); }
    virtual ~C2() override { P("A1 d-tor"); }
    int get() const { return i; }
};




class M1{
    int i { 5 };
public:
    M1(bool) { P("M1 c-tor"); }

    virtual ~M1() { P("M1 d-tor"); }
    int get() const { return i; }
};




class M2{
    int i { 5 };
public:
    M2(bool) { P("M2 c-tor"); }
    virtual ~M2() { P("M2 d-tor"); }
    int get() const { return i; }
};





class X : public C1, public C2 {
    M1 m1;
    M2 m2;
public:
// zaimplementuj c-tor i d-tor
    X(bool) : V2(true), V1(true), A1(true), C2(true),m1(true),m2(true),
                                                                  C1(true) { P("X c-tor"); }
    virtual ~X() { P("X d-tor"); }

};




int main() {
    A1 *pa = new X(false);
    cout << pa->get() << endl; // zakomentować gdy public A1
    delete pa;
}

