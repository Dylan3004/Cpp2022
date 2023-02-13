#include <iostream>
#include <string>


using namespace std;


class klasa {
public:
    unsigned long a=0;
    friend ostream & operator <<( ostream& s,  const klasa& x );
    friend istream& operator >>( istream& s,  klasa& x );

    klasa()
    {

    }
    klasa(char x) {
        a = x;
    }

    klasa(const char *x) {
        int temp = 0;
        for (int i = 0; i < strlen(x); i++) {
            temp += x[i];
        }
        a = temp;
    }

    klasa(string x) {
        for (int i = 0; i < x.length(); i++) {
            a += x[i];
        }
    }

    void wypisz() {
        cout << a << endl;
    }


    // ~klasa()
    // {
    //     delete &a;
    // }
};
ostream& operator <<( ostream& s,  const klasa& x )
{

   return s  << x.a ;

}
istream& operator >>( istream& s,  klasa& x )
{
     s  >> x.a ;

    if(s.fail())
    {
        s.clear();
        string temp;
        s >> temp;
        x.a=klasa(temp).a;

    }
    return s;
}


int main() {
    string d = "ABABABA";
    char c = 'b';
    char b[] = "alibaba";
    klasa pierwsza(c);
    klasa druga(d);
    klasa trzecia(b);
    pierwsza.wypisz();
    druga.wypisz();
    trzecia.wypisz();
    klasa k1;
    cout<<"wpisz klase: ";
    cin>>k1;
    cout<<endl;
    cout<<k1;


    return 0;
}
