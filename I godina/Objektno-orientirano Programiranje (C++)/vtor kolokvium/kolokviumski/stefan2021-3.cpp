//https://i.imgur.com/L2YUGBI.png

#include<cstring>
#include<iostream>
#include <algorithm>
#include <cctype>
using namespace std;


class InvalidOperation{
public:
    void message(){
        cout<<"Can’t merge two different cryptocurrencies."<<endl;
    }
};

class Cryptocurrency{
protected:
    char * valuta;
    char kod[7];
    float cena;
    float poseduva;
    static float provizija;
public:
    Cryptocurrency(){
        this->valuta = "";
        strcpy(this->kod, "00000000");
        this->cena=0;
        this->poseduva=0;
    }
    Cryptocurrency(char * valuta , char * kod, float cena ){
        this->valuta = new char [strlen(valuta)+1];
        strcpy(this->valuta, valuta);
        strcpy(this->kod, kod);
        this->cena = cena;
        this->poseduva = 0;
    }
    Cryptocurrency(char * valuta , char * kod, float cena , float poseduva ){
        this->valuta = new char [strlen(valuta)+1];
        strcpy(this->valuta, valuta);
        strcpy(this->kod, kod);
        this->cena = cena;
        this->poseduva = poseduva;
    }
    Cryptocurrency(const Cryptocurrency & c){
        this->valuta = new char [strlen(c.valuta)+1];
        strcpy(this->valuta, c.valuta);
        strcpy(this->kod, c.kod);
        this->cena = c.cena;
        this->poseduva = c.poseduva;
    }
    Cryptocurrency & operator = (const Cryptocurrency & c){
        if(this!=&c){
            delete [] valuta;
            this->valuta = new char [strlen(c.valuta)+1];
            strcpy(this->valuta, c.valuta);
            strcpy(this->kod, c.kod);
            this->cena = c.cena;
            this->poseduva = c.poseduva;
        }
        return *this;
    }

    ~Cryptocurrency(){
        delete [] valuta;
    }

    static void setProvision(float a){
        Cryptocurrency::provizija = a;
    }
    static float getProvision(){
        return Cryptocurrency::provizija;
    }
    char * getKod(){
        return kod;
    }
    friend ostream & operator <<(ostream & o, Cryptocurrency & a){
        return o<<a.kod<<" "<<a.valuta<<" "<<a.cena<<" "<<a.poseduva<<" "<<(float)a.cena*a.poseduva<<endl;
    }

    Cryptocurrency & operator += (Cryptocurrency & nov){
        if(strcmp(this->valuta, nov.valuta)!=0){
            throw InvalidOperation();
        }
        this->cena = nov.cena;
        this->poseduva+=nov.poseduva;
        return *this;
    }
    float vkcena(){
        return (float)cena*poseduva;
    }
    float sell(){
        return vkcena() - Cryptocurrency::provizija*vkcena()/100.0;
    }


};

float Cryptocurrency::provizija = 2.5;


class Wallet{
protected:
    char ime[40];
    Cryptocurrency * lista;
    int n;
public:
    Wallet(char * ime = ""){
        strcpy(this->ime, ime);
        this->n=0;
        this->lista = new Cryptocurrency[0];
    }
    Wallet(const Wallet & o){
        strcpy(this->ime, o.ime);
        this->n=o.n;
        this->lista = new Cryptocurrency[n];
        copy(o.lista,o.lista+o.n, this->lista);
    }
    Wallet & operator = (const Wallet & o){
        if(this!=&o){
            delete [] lista;
            strcpy(this->ime, o.ime);
            this->n=o.n;
            this->lista = new Cryptocurrency[n];
            copy(o.lista,o.lista+o.n, this->lista);
        }
        return *this;
    }
    friend ostream & operator <<(ostream & o, Wallet & w){
        o<<w.ime<<endl<<"Cryptocurrencies: "<<endl;
        if(w.n == 0){
            o<<"EMPTY"<<endl;
            return o;
        }
        for(int i=0;i<w.n;i++){
            o<<w.lista[i];
        }
        return o;
    }
    ~Wallet(){
        delete [] lista;
    }

    Wallet & operator +=(Cryptocurrency & nova){
        for(int i=0;i<n;i++){
            if(strcmp(lista[i].getKod(),nova.getKod())==0){
                lista[i]+=nova;
                return *this;
            }
        }
        Cryptocurrency * tmp = new Cryptocurrency[n+1];
        copy(lista, lista+n, tmp);
        delete [] lista;
        lista = new Cryptocurrency[n+1];
        tmp[n++] = nova;
        lista = tmp;
        return *this;
    }

};



int main() {
    int testCase;
    cin >> testCase;

    if (testCase == 0) {
        cout << "Cryptocurrency constructors" << endl;
        Cryptocurrency c1("Cardano", "ADA", 1.45);
        Cryptocurrency c2("Cardano", "ADA", 1.45, 2.5);
        cout << "TEST PASSED" << endl;
    } else if (testCase == 1) {
        cout << "Cryptocurrency copy-constructor and operator =" << endl;
        Cryptocurrency c2("Cardano", "ADA", 1.45, 2.5);
        Cryptocurrency c1 = c2; //copy-constructor
        Cryptocurrency c3("BITCOIN", "BTC", 35000, 0.0001);
        c3 = c2;
        cout << "TEST PASSED" << endl;
    } else if (testCase == 2) {
        cout << "Cryptocurrency operator <<" << endl;
        Cryptocurrency c1("Cardano", "ADA", 1.45);
        Cryptocurrency c2("Cardano", "ADA", 1.45, 2.5);
        cout << c1;
        cout << c2;
    } else if (testCase == 3) {
        cout << "Cryptocurrency operator += (normal behavior)" << endl;
        Cryptocurrency c1("Cardano", "ADA", 1.45, 8);
        Cryptocurrency c2("Cardano", "ADA", 1.39, 2.5);
        cout<<c1<<"+="<<endl<<c2<<"-->"<<endl;
        try{
        cout << (c1 += c2);
        }
        catch (InvalidOperation o){
            o.message();
        }
    } else if (testCase == 4) {
        cout << "Cryptocurrency operator += (abnormal behavior)" << endl;
        Cryptocurrency c1("Cardano", "ADA", 1.45, 8);
        Cryptocurrency c2("Bitcoin", "BTC", 35000, 0.0008);
        cout<<c1<<"+="<<endl<<c2<<"-->"<<endl;
        try{
        cout << (c1 += c2);
        }

        catch (InvalidOperation o){
            o.message();
        }
    } else if (testCase == 5) {
        /*cout << "Cryptocurrency method sell and static members test" << endl;
        int n;
        cin >> n;
        Cryptocurrency *cryptocurrencies1 = new Cryptocurrency[n];
        Cryptocurrency *cryptocurrencies2 = new Cryptocurrency[n];
        char name[50], code[7];
        double price, quantity;
        for (int i = 0; i < n; i++) {
            cin >> name >> code >> price >> quantity;
            cryptocurrencies1[i] = Cryptocurrency(name, code, price, quantity);
            cryptocurrencies2[i] = Cryptocurrency(name, code, price, quantity);
        }
        cout << "BEFORE CHANGE OF PROVISION PERCENT" << endl;
        for (int i = 0; i < n; i++) {
            cout << "    BEFORE SELLING --> " << cryptocurrencies1[i];
            cout << "     PROFIT FROM SELLING -->" << cryptocurrencies1[i].sell() << endl;
            cout << "    AFTER SELLING --> " << cryptocurrencies1[i];
        }
        Cryptocurrency::setProvision(5.1);
        cout << "AFTER CHANGE OF PROVISION PERCENT" << endl;
        for (int i = 0; i < n; i++) {
            cout << "    BEFORE SELLING --> " << cryptocurrencies2[i];
            cout << "     PROFIT FROM SELLING -->" << cryptocurrencies2[i].sell() << endl;
            cout << "    AFTER SELLING --> " << cryptocurrencies2[i];
        }

        delete[] cryptocurrencies1;
        delete[] cryptocurrencies2;*/
    } else if (testCase == 6) {
        cout << "Wallet constructors" << endl;
        Wallet w1("John Doe");
        Wallet w2("John Doe");
        cout << "TEST PASSED" << endl;
    } else if (testCase == 7) {
        cout << "Wallet copy-constructor and operator =" << endl;
        Wallet w1("John Doe");
        Wallet w2("John Doe");
        Wallet w3 = w1; //copy constructor;
        w2 = w1; //operator =
        cout << "TEST PASSED" << endl;
    } else if (testCase == 8) {
        cout << "Wallet operator <<" << endl;
        Wallet w1("John Doe");
        cout << w1;
    } else if (testCase == 9) {
        cout << "Wallet += and <<" << endl;
        Wallet wallet("John Doe");
        int n;
        cin >> n;
        char name[50], code[7];
        double price, quantity;
        try{
        for (int i = 0; i < n; i++) {
            cin >> name >> code >> price >> quantity;
            Cryptocurrency c(name, code, price, quantity);
            wallet += c;
        }
        }

        catch (InvalidOperation o){
            o.message();
        }
        cout << wallet;
    }
    return 0;
}


