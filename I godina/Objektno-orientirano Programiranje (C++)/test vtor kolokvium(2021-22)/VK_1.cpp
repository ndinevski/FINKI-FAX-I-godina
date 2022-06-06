#include<iostream>
#include <algorithm>
#include <cctype>
#include<cstring>
using namespace std;

class Sneakers {
private:
    char model[50];
    int size;
    float price;

public:
    Sneakers(const char *model = "", int size = 38, float price = 1000) : size(size), price(price) {
        strncpy(this->model, model, 49);
        this -> model[49] = 0;
    }

    friend istream &operator>>(istream &in, Sneakers &s) {
        return in >> s.model >> s.size >> s.price;
    }

    friend ostream &operator<<(ostream &out, const Sneakers &s) {
        return out << "Model: " << s.model << " Size: " << s.size << " Price: " << s.price;
    }

    Sneakers &operator+=(float increment) {
        price += increment;
        return *this;
    }

    Sneakers &operator*=(float coefficient) {
        price *= coefficient;
        return *this;
    }

    bool operator==(Sneakers &s) {
        return strcmp(this->model, s.model) == 0 && this->size == s.size;
    }

    char *getModel() {
        return model;
    }

    int getSize() const {
        return size;
    }

    void setSize(int size) {
        this->size = size;
    }

    float getPrice() const {
        return price;
    }

    void setPrice(float price) {
        this->price = price;
    }
};

class SneakersShop{
protected:
    char ime[50];
    Sneakers * patiki;
    int n;
    static int poskapuvanje;
public:
    SneakersShop(const char * ime=""){
        strcpy(this->ime, ime);
        this->n=0;
        this->patiki = new Sneakers[n];
    }
    static void setIncreasePercentage(int a){
        SneakersShop::poskapuvanje = a;
    }
    static int getIncreasePercentage(){
        return SneakersShop::poskapuvanje;
    }
    SneakersShop & operator +=( Sneakers & nov){

        Sneakers * tmp = new Sneakers[n+1];
        copy(patiki, patiki + n, tmp);
        delete [] patiki;
        tmp[n++] = nov;
        patiki = tmp;
        return *this;

    }

    virtual float checkItemAvailability(char * model, int gol){
        for(int i=0;i<n;i++){
            if(!strcmp(model, patiki[i].getModel()) && gol==patiki[i].getSize()){
                return (float)patiki[i].getPrice();
            }
        }
        return 0;
    }

    SneakersShop & operator ++(){
        for(int i=0;i<n;i++){
            float novacena;
            novacena=((float)patiki[i].getPrice())*(1+(float)SneakersShop::poskapuvanje/100);
            patiki[i].setPrice(novacena);
        }
        return *this;
    }

    friend ostream & operator << ( ostream & o, SneakersShop & s){
        o<<"Sneakers shop: "<<s.ime<<endl;
        o<<"List of sneakers: "<<endl;
        if(s.n==0){
            o<<"EMPTY"<<endl;
            return o;
        }
        for(int i=0;i<s.n;i++){
            o<<i+1<<". "<<s.patiki[i]<<endl;
        }
        return o;
    }
};
int SneakersShop::poskapuvanje = 5;


class OnlineSneakersShop : public SneakersShop{
protected:
    char url[100];
    static int const popust=10;
public:
    OnlineSneakersShop(const char * ime="", const char * url=""): SneakersShop(ime){
        strcpy(this->url, url);
    }
    float checkItemAvailability(char * model, int size){
        float obicnacena = SneakersShop::checkItemAvailability(model, size);
        if(obicnacena==0){
            return 0;
        }
        return (float)obicnacena*(100-popust)/100.0;

    }
    friend ostream & operator << ( ostream & o, OnlineSneakersShop & s){
        o<<"Online sneakers shop: "<<s.ime<<" URL: "<<s.url<<endl;
        o<<"List of sneakers: "<<endl;
        if(s.n==0){
            o<<"EMPTY"<<endl;
            return o;
        }
        for(int i=0;i<s.n;i++){
            o<<i+1<<". "<<s.patiki[i]<<endl;
        }
        return o;
    }
};
//int OnlineSneakersShop::popust = 10;

void printShop(SneakersShop *shop) {
    OnlineSneakersShop *casted = dynamic_cast<OnlineSneakersShop *>(shop);
    if (casted) {
        cout << (*casted);
    } else {
        cout << (*shop);
    }
}

int main() {
    int testCase;
    cin >> testCase;
    char name[100];
    char url[100];

    if (testCase == 1) {
        cout << "TESTING CLASS SneakersShop: CONSTRUCTOR AND OPERATOR <<" << endl;
        cin >> name;
        SneakersShop shop(name);
        cout << shop;
    } else if (testCase == 2) {
        cout << "TESTING CLASS OnlineSneakersShop: CONSTRUCTOR AND OPERATOR <<" << endl;
        cin >> name >> url;
        OnlineSneakersShop shop(name, url);
        cout << shop;
    } else if (testCase == 3) {
        cout << "TESTING CLASS SneakersShop, CONSTRUCTOR, += and <<" << endl;
        cin >> name;
        SneakersShop shop(name);
        cout << shop;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            Sneakers s;
            cin >> s;
            shop += s;
        }
        cout << shop;
    } else if (testCase == 4) {
        cout << "TESTING CLASS OnlineSneakersShop, CONSTRUCTOR, += and <<" << endl;
        cin >> name >> url;
        OnlineSneakersShop shop(name, url);
        cout << shop;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            Sneakers s;
            cin >> s;
            shop += s;
        }
        cout << shop;
    } else if (testCase == 5) {
        cout << "TESTING METHOD checkItemAvailability" << endl;
        int typeOfShop;
        cin >> typeOfShop >> name; //0 = regular, 1 = online
        SneakersShop *shop;
        if (typeOfShop == 0) {
            shop = new SneakersShop(name);
        } else {
            cin >> url;
            shop = new OnlineSneakersShop(name, url);
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            Sneakers s;
            cin >> s;
            (*shop) += s;
        }
        char model[100];
        int size;
        cin >> model >> size;
        cout << "Price for model " << model << " with size: " << size << " is: "
             << shop->checkItemAvailability(model, size) << endl;
    } else if (testCase == 6) {
        cout << "TESTING OPERATOR ++" << endl;
        int typeOfShop;
        cin >> typeOfShop >> name; //0 = regular, 1 = online
        SneakersShop *shop;
        if (typeOfShop == 0) {
            shop = new SneakersShop(name);
        } else {
            cin >> url;
            shop = new OnlineSneakersShop(name, url);
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            Sneakers s;
            cin >> s;
            (*shop) += s;
        }
        cout << "BEFORE ++ IS CALLED" << endl;
        printShop(shop);
        ++(*shop);
        cout << "AFTER ++ IS CALLED" << endl;
        printShop(shop);
    } else if (testCase == 7) {
        cout << "TESTING OPERATOR ++ AND CHANGE OF STATIC MEMBER" << endl;
        int typeOfShop;
        cin >> typeOfShop >> name; //0 = regular, 1 = online
        SneakersShop *shop;
        if (typeOfShop == 0) {
            shop = new SneakersShop(name);
        } else {
            cin >> url;
            shop = new OnlineSneakersShop(name, url);
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            Sneakers s;
            cin >> s;
            (*shop) += s;
        }

        cout << "BEFORE ++ IS CALLED" << endl;
        printShop(shop);
        ++(*shop);
        cout << "AFTER ++ IS CALLED" << endl;
        printShop(shop);

        cout <<"CHANGING INCREASE PERCENTAGE IN SneakersShop" << endl;
        SneakersShop::setIncreasePercentage(17);

        cout << "BEFORE ++ IS CALLED" << endl;
        printShop(shop);
        ++(*shop);
        cout << "AFTER ++ IS CALLED" << endl;
        printShop(shop);
    }
}
