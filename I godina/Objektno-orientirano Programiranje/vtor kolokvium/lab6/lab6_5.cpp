//https://i.imgur.com/AcmmXSk.png

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

class Ekipa{
    protected:
        char name[15];
        int loss;
        int win;
        void cpys(const Ekipa& o){
            strcpy(this->name, o.name);
            this->loss = o.loss;
            this->win = o.win;
        }
    public:
        Ekipa(char * name="", int loss=0, int win=0){
            strcpy(this->name, name);
            this->loss = loss;
            this->win = win;
        }
        Ekipa(const Ekipa & other){
            cpys(other);
        }
        Ekipa& operator=(const Ekipa & other){
            if(this != &other){
                cpys(other);
            }
            return *this;
        }
        ~Ekipa(){}
        void pecati(){
            cout<<"Ime: "<<name<<" Pobedi: "<<win<<" Porazi: "<<loss;
        }
};

class FudbalskaEkipa: public Ekipa{
    private:
        int crveni;
        int zolti;
        int draw;
    public:
        FudbalskaEkipa(char * name="", int loss=0, int win=0, int crveni=0, int zolti=0, int draw=0): Ekipa(name, loss, win){
            this->crveni=crveni;
            this->zolti=zolti;
            this->draw = draw;
        }
        FudbalskaEkipa(const FudbalskaEkipa & f, int crveni=0, int zolti=0, int draw=0): Ekipa(f){
            this->crveni=crveni;
            this->zolti=zolti;
            this->draw = draw;
        }
        FudbalskaEkipa(const FudbalskaEkipa & other):Ekipa (other){
            this->crveni=other.crveni;
            this->zolti=other.zolti;
            this->draw = other.draw;
        }
        FudbalskaEkipa& operator = (const FudbalskaEkipa & f){
            if(this!=&f){
                this->crveni=f.crveni;
                this->zolti=f.zolti;
                this->draw = f.draw;
            }
            return *this;
        }
        ~FudbalskaEkipa(){}
        int points(){
            return win*3+draw;
        }
        void pecati(){
            Ekipa::pecati();
            cout<<" Nereseni: "<<draw<<" Poeni: "<<points();
        }
};

int main(){
	char ime[15];
	int pob,por,ck,zk,ner;
	cin>>ime>>pob>>por>>ck>>zk>>ner;
	FudbalskaEkipa f1(ime,pob,por,ck,zk,ner);
	f1.pecati();
	return 0;
}