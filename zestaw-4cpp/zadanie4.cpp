//
// Created by DW on 2022-06-05.
//
#include <iostream>
#include <string>
using namespace std;

class Drawing
{
public:
    virtual void drawLine(){}
    virtual void drawCircle(){}
};
class Shape
{
public:
    explicit Shape(Drawing* x);
    virtual void draw (){}
    void setLib(Drawing* x)
    {ptr =x;}
    Drawing*ptr;
};

Shape::Shape(Drawing *x) :ptr(x){}

class Rectangle : public Shape
{
public:
    explicit Rectangle(Drawing *x): Shape(x){}
    void draw() override
    {
        ptr->drawLine();
        cout<<"klasa rectangle"<<endl;
    }
};
class Circle : public Shape
{
public:
    explicit Circle(Drawing*x): Shape(x){}

    void draw ()override
    {
        ptr->drawCircle();
        cout<<"klasa circle"<<endl;
    }
};


class DP1
{
public:
    void static draw_a_line()
    {
        cout<<"-/-/-/-/-/-/-/-/-"<<endl;
    }
    void static draw_a_circle()
    {
        cout<<"   --- "<<endl;
        cout<<"  (   )"<<endl;
        cout<<"   --- "<<endl;
    }

};
class DP2
{
public:
    static void drawline();
    static void drawcircle();
};

void DP2::drawline() {
    cout<<"-------"<<endl;
}

void DP2::drawcircle() {
    cout<<"  ****  "<<endl;
    cout<<" *    * "<<endl;
    cout<<"*      *"<<endl;
    cout<<" *    * "<<endl;
    cout<<"  **** "<<endl;

}

class V2Drawing : public Drawing
{
    DP2 wzor2;
public:
    explicit V2Drawing(DP2 wzor);
    void drawLine () override
    {
        wzor2.drawline();
    }
    void drawCircle() override
    {
        wzor2.drawcircle();
    }
};

V2Drawing::V2Drawing(DP2 wzor) {
    wzor2=wzor;
}

class V1Drawing : public Drawing
{
    DP1 wzor1{};
public:
    explicit V1Drawing(DP1 wzor)
    {
        wzor1 = wzor;
    }
    void drawLine () override
    {
        DP1::draw_a_line();
    }

    void drawCircle() override
    {
        DP1::draw_a_circle();
    }
};





int main ()
{

        DP1 library1; // pierwsza biblioteka
        DP2 library2; // druga biblioteka
        Drawing *d1 = new V1Drawing( library1 );
        Drawing *d2 = new V2Drawing( library2 );
        Shape *p1 = new Rectangle( d1 );
        Shape *p2 = new Circle( d2 );
        p1->draw(); // rectangle linia V1
        p2->draw(); // circle okrag V2
        p1->setLib( d2 );
        p2->setLib( d1 );
        p1->draw(); // rectangle linia V2
        p2->draw(); // circle okrag V1
        delete p1;
        delete p2;
        delete d1;
        delete d2;

}
