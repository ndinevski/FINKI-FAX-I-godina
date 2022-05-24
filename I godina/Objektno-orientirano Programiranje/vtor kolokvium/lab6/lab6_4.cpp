//https://i.imgur.com/GTC7WhV.png

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

class Nediviznina{
    protected:
        char * adresa;
        int mk;
        int price;
        void cpys(const Nediviznina& o){
            this->adresa = new char[strlen(o.adresa)+1];
            strcpy(this->adresa, o.adresa);
            this->mk = o.mk;
            this->price = o.price;
        }
    public:
        Nediviznina(char * adresa="", int mk=0, int price=0){
            this->adresa = new char[strlen(adresa)+1];
            strcpy(this->adresa, adresa);
            this->mk = mk;
            this->price = price;
        }
        Nediviznina(const Nediviznina& other){
            cpys(other);
        }
        Nediviznina& operator=(const Nediviznina& other){
            if(this != &other){
                delete [] adresa;
                cpys(other);
            }
            return *this;
        }
        friend istream& operator>>(istream& in, Nediviznina& nov){
            in>>nov.adresa>>nov.mk>>nov.price;
            return in;
        }
        ~Nediviznina(){
            delete [] adresa;
        }
        int cena(){
            return mk*price;
        }
        void pecati(){
            cout<<adresa<<", Kvadratura: "<<mk<<", Cena po Kvadrat: "<<price;
        }
        char * getAdresa(){
            return adresa;
        }
        float danokNaImot(){
            return 0.05*cena();
        }

};

class Vila: public Nediviznina{
    private:
        int danokLuksuz;
    public:
        Vila(char * adresa="", int mk=0, int price=0, int danokLuksuz=0): Nediviznina(adresa, mk , price){
            this->danokLuksuz=danokLuksuz;
        }
        Vila(const Nediviznina & other, int danokLuksuz=0): Nediviznina(other){
            this->danokLuksuz=danokLuksuz;
        }
        Vila(const Vila & other):Nediviznina (other){
            this->danokLuksuz=other.danokLuksuz;
        }
        Vila & operator = (const Vila & l ){
            if(this!=&l){
                Nediviznina::operator=(l);
                this->danokLuksuz=l.danokLuksuz;
            }
            return *this;
        }
        friend istream& operator>>(istream& in, Vila& nov){
            // Nediviznina tmp(nov);
            in>>nov.adresa>>nov.mk>>nov.price;
            in>>nov.danokLuksuz;
            return in;
        }
        void pecati(){
            Nediviznina::pecati ();
            cout<<", Danok na luksuz: "<<danokLuksuz;
        }
        float danokNaImot(){
            return Nediviznina::danokNaImot()+danokLuksuz*Nediviznina::cena()/100.0;
        }
};




int main(){
    Nediviznina n;
    Vila v;
    cin>>n;
    cin>>v;
    n.pecati();
    cout<<endl<<"Danok za: "<<n.getAdresa()<<", e: "<<n.danokNaImot()<<endl;
    v.pecati();
    cout<<endl<<"Danok za: "<<v.getAdresa()<<", e: "<<v.danokNaImot()<<endl;
    return 0;
}