//https://i.imgur.com/JhIW4la.png

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
enum Tip{
    LINUX,
    UNIX,
    WINDOWS
};
class OperativenSistem{
    char * name;
    float version;
    Tip t;
    float size;
    void cpy(const OperativenSistem & o){
        this->name = new char[strlen(o.name)+1];
        strcpy(this->name, o.name);
        this->version = o.version;
        this->t=o.t;
        this->size=o.size;
    }
public:
    OperativenSistem(char * name="", float version=0,Tip t=LINUX, float size=0){
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        this->version = version;
        this->t=t;
        this->size=size;
    }
    OperativenSistem(const OperativenSistem & o){
        cpy(o);
    }
    OperativenSistem & operator = ( const OperativenSistem & o){
        if(&o!=this){
            delete [] name;
            cpy(o);
        }
        return *this;
    }
    ~OperativenSistem(){
        delete [] name;
    }
    void pecati(){
        cout<<"Ime: "<<name<<" Verzija: "<<version<<" Tip: "<<t<<" Golemina:"<<size<<"GB"<<endl;
    }
    bool ednakviSe(const OperativenSistem &os){
        return (strcmp(this->name, os.name)==0 && this->version==os.version && this->t==os.t && this->size==os.size);
    }
    int sporediVerzija(const OperativenSistem &os){
        if(this->version == os.version){
            return 0;
        }else if(this->version > os.version){
            return 1;
        }
        return -1;
    }
    bool istaFamilija(const OperativenSistem &sporedba){
        return (strcmp(this->name,sporedba.name)==0 && this->t==sporedba.t);
    }
};

class Repozitorium{
    char name[20];
    OperativenSistem * lista;
    int n;
public:
    Repozitorium(const char *name){
        strcpy(this->name, name);
        this->lista=nullptr;
        this->n=0;
    }
    Repozitorium(const Repozitorium & r){
        strcpy(this->name, r.name);
        this->n=r.n;
        this->lista = new OperativenSistem[r.n];
        copy(r.lista,r.lista + r.n, this->lista);
    }
    ~Repozitorium(){
        delete [] lista;
    }
    void pecatiOperativniSistemi(){
        cout<<"Repozitorium: "<<name<<endl;
        for(int i=0;i<n;i++){
            lista[i].pecati();
        }
    }
    void dodadi(const OperativenSistem &nov){
        for(int i=0;i<n;i++){
            if(lista[i].istaFamilija(nov)){
                if(lista[i].sporediVerzija(nov)==-1){
                    lista[i]=nov;
                    return;
                }
            }
        }
        OperativenSistem * tmp;
        tmp = new OperativenSistem[n+1];
        copy(lista, lista + n, tmp);
        delete [] lista;
        lista = new OperativenSistem [n+1];
        tmp[n++]=nov;
        lista=tmp;
    }
    void izbrishi(const OperativenSistem &operativenSistem){
        for(int i=0; i<this->n; i++){
            if(this->lista[i].ednakviSe(operativenSistem)){
                for(int j=i; j<this->n-1; j++){
                    this->lista[j] = this->lista[j+1];
                }
                this->n--;
            }
        }
    }
};


int main() {
    char repoName[20];
    cin>>repoName;
    Repozitorium repozitorium=Repozitorium(repoName);
    int brojOperativniSistemi = 0;
    cin>>brojOperativniSistemi;
    char ime[20];
    float verzija;
    int tip;
    float golemina;
    for (int i = 0; i<brojOperativniSistemi; i++){
        cin>>ime;
        cin>>verzija;
        cin>>tip;
        cin>>golemina;
        OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
        repozitorium.dodadi(os);
    }

    repozitorium.pecatiOperativniSistemi();
     cin>>ime;
    cin>>verzija;
    cin>>tip;
    cin>>golemina;
    OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
    cout<<"=====Brishenje na operativen sistem====="<<endl;
    repozitorium.izbrishi(os);
    repozitorium.pecatiOperativniSistemi();
    return 0;
}
