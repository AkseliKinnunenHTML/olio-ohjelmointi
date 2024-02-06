#include <iostream>
using namespace std;

class Asunto {
public:
    int asukasMaara;
    int neliot;
    Asunto(int a, int n) : asukasMaara(a), neliot(n) {}
    void maarita() {
        cout << "Asunto: asukkaita " << asukasMaara << ", neliöt " << neliot << endl;
    }
    double laskeKulutus(double kerroin) {
        return asukasMaara * neliot * kerroin;
    }
};

class Kerros {
private:
    Asunto as1;
    Asunto as2;
    Asunto as3;
    Asunto as4;
public:
    Kerros(int a1, int n1, int a2, int n2, int a3, int n3, int a4, int n4) : as1(a1, n1), as2(a2, n2), as3(a3, n3), as4(a4, n4) {}
    void maaritaAsunnot() {
        as1.maarita();
        as2.maarita();
        as3.maarita();
        as4.maarita();
    }
    double laskeKulutus(double kerroin) {
        double summa = 0;
        summa += as1.laskeKulutus(kerroin);
        summa += as2.laskeKulutus(kerroin);
        summa += as3.laskeKulutus(kerroin);
        summa += as4.laskeKulutus(kerroin);
        return summa;
    }
};

class Katutaso : public Kerros {
private:
    Asunto as1;
    Asunto as2;
public:
    Katutaso(int a1, int n1, int a2, int n2, int a3, int n3, int a4, int n4) : Kerros(a1, n1, a2, n2, a3, n3, a4, n4), as1(a1, n1), as2(a2, n2) {}
    void maaritaAsunnot() {
        as1.maarita();
        as2.maarita();
    }
    double laskeKulutus(double kerroin) {
        double summa = 0;
        summa += as1.laskeKulutus(kerroin);
        summa += as2.laskeKulutus(kerroin);
        return summa;
    }
};

class Kerrostalo {
private:
    Katutaso eka;
    Kerros toka;
    Kerros kolmas;
public:
    Kerrostalo(int a1, int n1, int a2, int n2, int a3, int n3, int a4, int n4) : eka(a1, n1, a2, n2, a3, n3, a4, n4), toka(a1, n1, a2, n2, a3, n3, a4, n4), kolmas(a1, n1, a2, n2, a3, n3, a4, n4) {}
    double laskeKulutus(double kerroin) {
        double summa = 0;
        summa += eka.laskeKulutus(kerroin);
        summa += toka.laskeKulutus(kerroin);
        summa += kolmas.laskeKulutus(kerroin);
        return summa;
    }
};

int main() {
    Kerrostalo talo(4, 100, 3, 90, 2, 80, 1, 70);
    cout << "Asukkaiden yhteinen kulutus: " << talo.laskeKulutus(0.5) << endl;
    return 0;
}
