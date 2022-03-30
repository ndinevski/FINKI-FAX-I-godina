// /https://i.imgur.com/hKtjWlN.png

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

enum Tip{
    LINUX,
    UNIX,
    WINDOWS
};

class OperativenSistem {
    char * name;
    float version;
    Tip t;
    float size;
    void copys(const OperativenSistem & os){
        this->name=new char[strlen(os.name)+ 1];
        strcpy(this->name, os.name);
        this->version=os.version;
        this->t=os.t;
        this->size=os.size;
    }
public:
    OperativenSistem(char * name=nullptr, float version=0,Tip t=LINUX, float size=0){
        this->name=new char[strlen(name)+ 1];
        strcpy(this->name, name);
        this->version=version;
        this->t=t;
        this->size=size;
    }
    OperativenSistem(const OperativenSistem & os){
        copys(os);
    }
    OperativenSistem & operator = (const OperativenSistem & os){
        if(&os!=this){
            delete [] name;
            copys(os);
        }
        return *this;
    }
    ~OperativenSistem(){
        delete [] name;
    }
    void print(){
        cout<<"Ime: "<<name<<" Verzija: "<<version<<" Tip: "<<t<<" Golemina:"<<size<<"GB"<<endl;
    }
    bool ednakviSe(const OperativenSistem &os){
        return (strcmp(this->name, os.name)==0 && this->version==os.version && this->t==os.t && this->size==os.size);
    }
    int sporediVerzija(const OperativenSistem &os){
        if(this->version>os.version){
            return 1;
        }
        if(this->version==os.version){
            return 0;
        }
        return -1;
    }
    bool istaFamilija(const OperativenSistem &sporedba){
        return (strcmp(this->name, sporedba.name)==0 && this->t==sporedba.t);
    }
};

class Repozitorium{
    char name[20];
    OperativenSistem * oss;
    int n;
    void copys(const Repozitorium & r){
        this->n=r.n;
        strcpy(this->name, r.name);
        this->oss=new OperativenSistem[this->n];
        for(int i=0;i<this->n;i++){
            this->oss[i]=r.oss[i];
        }
    }
public:
    Repozitorium(char * name=nullptr){
        this->n=0;
        strcpy(this->name, name);
        this->oss=nullptr;
    }
    Repozitorium(const Repozitorium & r){
        copys(r);
    }
    Repozitorium & operator = (const Repozitorium & r){
        if(&r!=this){
            delete [] oss;
            copys(r);
        }
        return *this;
    }
    ~Repozitorium(){
        delete [] oss; 
    }
    void pecatiOperativniSistemi(){
        cout<<"Repozitorium: "<<this->name<<endl;
        for(int i=0;i<this->n; i++){
            this->oss[i].print();
        }
    }
    void izbrishi(const OperativenSistem &operativenSistem){
        for(int i=0; i<this->n; i++){
            if(this->oss[i].ednakviSe(operativenSistem)){ 
                for(int j=i; j<this->n-1; j++){ 
                    this->oss[j] = this->oss[j+1];
                }
                this->n--; 
            } 
        } 
    }
    void dodadi(const OperativenSistem &nov){
        int flag=0;
        for(int i=0;i<this->n;i++){
            if(this->oss[i].istaFamilija(nov)){
                if(this->oss[i].sporediVerzija(nov)==-1){
                    izbrishi(this->oss[i]);
                    OperativenSistem * tmp= new OperativenSistem[this->n + 1];
                    copy(this->oss,this->oss + this->n, tmp);
                    tmp[this->n++]=nov;
                    delete [] oss;
                    this->oss=new OperativenSistem[this->n];
                    this->oss=tmp;
                }
                if(this->oss[i].sporediVerzija(nov)==0){
                    return;
                }
            }
        }
        OperativenSistem * tmpp= new OperativenSistem[this->n + 1];
            copy(this->oss,this->oss + this->n, tmpp);
            tmpp[this->n++]=nov;
            delete [] oss;
            this->oss=new OperativenSistem[this->n];
            this->oss=tmpp;
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