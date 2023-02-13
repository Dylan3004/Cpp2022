//
// Created by DW on 2022-06-05.
//
#include <iostream>
#include <string>
using namespace std;

class MozeWykBadania
{
    string badania ="Badania wykonuje , mam w tym wprawe nie zartuje !";
public:
    void wyswietlMozeWykBadania (){cout<<badania;}
};




class MozeNauczac
{
    string nauczanie ="Ucze sie pilnie , wiec zeszyt kartkuje usilnie !";
public:
    void wyswietlMozeNauczac (){cout<<nauczanie;}
};




class MozeBycStudentem
{
    string student ="Moze i studiuje ale calki sprawnie rozwiazuje !";
public:
    void wyswietlMozeBycStudentem (){cout<<student;}
};




class TOsoba
{
    string imie ="Swoje imie mam i na UJ uczeszczam !";
public:
    void wyswietlTOsoba (){cout<<imie;}
};




class TAsystentBadan: public MozeWykBadania , public virtual TOsoba
{
    string asys ="Asystuje i z naukowcami wspolpracuje !";
public:
    void wyswieltTAsystentBadan (){cout<<asys;}
    //wyswietlMozeWykBadania ()

};




class TStudent : virtual public TOsoba , public MozeBycStudentem
{
    string stud = "Studiuje i zdawac probuje !";
public:
    void wyswietlTStudent (){cout<<stud;}
};




class TDoktorant : public TStudent
{
    string tdok = "Magisterke mam ale wiecej z siebie dam ! ";
public:
    void wyswietlTDoktorant(){cout<<tdok;}
};




class TDoktorantBadacz : public TAsystentBadan ,  public TDoktorant
{
    string dokbad = "Badam wszystko co popadnie , co mi tylko w rece wpadnie !";
public:
    void wyswietlTDoktorantBadacz(){cout<<dokbad;}
};




class TDoktorantNaucz : public MozeNauczac , public TDoktorant
{
    string doknaucz = "Doktorantem jestem wiesz ? I naucze ciebie tez !";
public:
    void wyswietlDoktorantNaucz () {cout<<doknaucz;}
};




int main ()
{
    TDoktorantBadacz p1;
    TDoktorantNaucz p2;
    cout<<endl;
    p1.wyswietlMozeWykBadania();
    cout<<endl;
    cout<<endl;
    p2.wyswietlMozeNauczac();
    cout<<endl;
    cout<<endl;
    p1.wyswietlMozeBycStudentem();
    cout<<endl;
    cout<<endl;
    p1.wyswietlTOsoba();
    cout<<endl;
    cout<<endl;
    p1.wyswietlTDoktorantBadacz();
    cout<<endl;
    cout<<endl;
    p1.wyswietlTStudent();
    cout<<endl;
    cout<<endl;
    p1.wyswieltTAsystentBadan();
    cout<<endl;
    cout<<endl;
    p1.wyswietlTDoktorant();
    cout<<endl;
    cout<<endl;
    p2.wyswietlDoktorantNaucz();
    cout<<endl;

}



