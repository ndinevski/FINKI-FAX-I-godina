// Креирајте класа Rabotnik која во себе содржи:
// ime (низа од максимум 30 знаци)
// prezime (низа од максимум 30 знаци)
// plata (целобројна вредност)
// За оваа класа да се креираат default конструктор и конструктор со аргументи. Да се имплементираат и следните методи:
// getPlata() која ја враќа платата на работникот
// pecati() која ги печати името, презимето и платата.
// Креирајте класа Fabrika во која има:
// rabotnik [100] (низа од вработени)
// brojVraboteni (целобројна вредност)
// Во класата имплементирајте ги следните методи:
// pecatiVraboteni() ги печати сите вработени
// pecatiSoPlata(int plata) ги печати сите вработени со плата поголема или еднаква на дадената во аргументот(int plata).
// Во главната функција се внесуваат податоци за n вработени. Притоа прво се внесува n, па податоците за сите n вработени. Во последниот ред се чита минималната плата.
// На излез да се прикажат прво сите вработени, а потоа само оние со поголема плата од минималната. Треба да се корисатат методите pecatiVraboteni и pecatiSoPlata!

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

class Rabotnik{
    char ime[30];
    char prezime[30];
    int plata;
public:
    Rabotnik(){}
    Rabotnik(char * i, char * p, int pl){
        strcpy(ime, i);
        strcpy(prezime, p);
        plata=pl;
    }
    ~Rabotnik(){}
    int getPlata(){
        return plata;
    }
    void pecati(){
        cout<<ime<<" "<<prezime<<" "<<plata<<endl;
    }
};

class Fabrika{
    Rabotnik rabotnik[100];
    int brojVraboteni;
public:
    Fabrika(){
        brojVraboteni=0;
    }
    Fabrika(Rabotnik * r, int n){
        brojVraboteni=n;
        for(int i=0;i<n;i++){
            rabotnik[i]=r[i];
        }
    }
    ~Fabrika(){}
    void pecatiVraboteni(){
        cout<<"Site vraboteni: "<<endl;
        for(int j=0;j<brojVraboteni;j++){
            rabotnik[j].pecati();
        }
    }
};


int main(){
    int n;
    cin>>n;
    Rabotnik r[100];
    Fabrika f(r,n);
    for(int i=0;i<n;i++){
        char ime[30],prezime[30];
        int plata;
        cin>>ime>>prezime>>plata;
        r[i]= Rabotnik(ime, prezime, plata);
    }
    int maksPlata;
    cin>>maksPlata;
    f.pecatiVraboteni();
    return 0;
}