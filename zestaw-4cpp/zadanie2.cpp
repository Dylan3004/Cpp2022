////
//// Created by DW on 2022-06-05.
////
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <random>
#include <memory>
using namespace std;

class Obserwator {
public:
    Obserwator(const char* s) : nazwa{s ? s : "nienazwany"} { /* nic nie robi */ }
    virtual ~Obserwator() { } // klasa bazowa
    const char* id() const { return nazwa.c_str(); }
    virtual void update() = 0; // metoda czysto wirtualna
private:
    string nazwa;
};

class Manager {
public:
    void dodaj(Obserwator* p);
    void usun(Obserwator* p);
    void powiadom();
    void obserwatorzy() const;
private:
    list<Obserwator*> klient;
};

void Manager::obserwatorzy() const {
    if (klient.empty()) cout << "Brak obserwatorow\n";
    auto it = klient.cbegin();
    while(it != klient.cend()) {
        cout << "Obserwator " << (*it)->id() << endl;
        ++it;
    }
}

void Manager::powiadom() {
    for (auto& p : klient) p->update();
}

void Manager::dodaj(Obserwator* p) {
    if (find(begin(klient),end(klient),p) == end(klient)) {
        klient.push_back(p);
    } else {
        cout << "Obserwator " << p->id() << " jest juz na liscie\n";
    }
}

void Manager::usun(Obserwator* p) {
    klient.erase(find(begin(klient),end(klient),p));
}

class Meteo : public Manager {
public:
    double getT() const { return t; }
    void operator()(size_t n);
private:
    double t {0.};
    double a {5.};
    double b {25.};
    double losuj(double a, double b);
    random_device rd;
    mt19937 gen { rd() };
    uniform_real_distribution<> dis { a, b };
};

double Meteo::losuj(double a, double b) {
    return dis(gen);
}

void Meteo::operator()(size_t n) {
    while (n--) {
        t = losuj(a,b);
        powiadom();
    }
}

class Monitor : public Obserwator {
public:
    Monitor(const char* s, const Meteo& r) : Obserwator(s), ref(r) { }
    void update() override {
        t = ref.getT();
        cout << "Obserwator " << id() << " t = " << t << endl;
    }
private:
    double t {0.};
    const Meteo& ref;
};

class MonitorSredni : public Obserwator {
public:
    MonitorSredni(const char* s, const Meteo& r)  : Obserwator(s), ref(r) { }
    void update() {
        vec.push_back(ref.getT());
        tsr = 0.;
        for (const auto& d : vec) tsr += d;
        tsr /= vec.size();
        cout << "Obserwator " << id() << " t srednia = " << tsr << endl;
    }

private:
    double tsr {0.};
    vector<double> vec;
    const Meteo& ref;
};

int main() {
    Meteo stacja;
    unique_ptr<Obserwator> p1(new Monitor("Monitor 1",stacja));
    unique_ptr<Obserwator> p2(new Monitor("Monitor 2",stacja));
    unique_ptr<Obserwator> p3(new Monitor("Monitor 3",stacja));
    unique_ptr<Obserwator> p4(new Monitor("Monitor 4",stacja));

    stacja.obserwatorzy(); // pusta lista
    stacja.dodaj(p1.get());
    stacja.dodaj(p2.get());
    stacja.dodaj(p3.get());
    stacja.dodaj(p4.get());
    cout<<endl;
    stacja.obserwatorzy();
    cout<<endl;
    // lista nazw wszystkich podłączonych obserwatorów
    stacja(2);
    cout<<endl;// dwa losowania, stacja.operator()(2);
    stacja.dodaj(p1.get()); // sprawdzenie, czy p1 jest już na liście
    stacja.usun(p3.get()); // od teraz p3 nie jest obserwatorem
    stacja(3);
}
