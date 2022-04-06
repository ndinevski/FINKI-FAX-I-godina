//https://i.imgur.com/hXeh7cN.png

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
enum tip{
    pop,
    rap,
    rok
};

class Pesna{
    char * name;
    int min;
    tip t;
    void copys(const Pesna& p){
        this->name = new char[strlen(p.name)+1];
        strcpy(this->name, p.name);
        this->min = p.min;
        this->t = p.t;
    }
public:
    Pesna(char * name="", int min=0, tip t=pop){
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        this->min = min;
        this->t = t;
    }
    Pesna(const Pesna & p){
        copys(p);
    }
    Pesna &  operator =(const Pesna & p){
        if(&p!=this){
            delete [] name;
            copys(p);
        }
        return *this;
    }
    ~Pesna(){
        delete [] name;
    }
    void pecati(){
        cout<<"\""<<name<<"\""<<"-"<<min<<"min"<< endl;
    }
    int getMin(){
        return min;
    }

    tip getTip(){
        return t;
    }

};

class CD{
    Pesna * pesni;
    int n;
    int max;
    void copys(const CD & p){
        this->max=p.max;
        this->n=p.n;
        this->pesni = new Pesna[this->n];
        for(int i=0;i<this->n;i++){
            pesni[i]=p.pesni[i];
        }
    }
public:
    CD(int max=0){
        this->max=max;
        this->n=0;
        this->pesni=nullptr;
    }
    CD(const CD & p){
        copys(p);
    } 
    ~CD(){
        delete [] pesni;
    }
    void dodadiPesna(Pesna nova){
        if(n<10 && nova.getMin()<=max){
            Pesna * tmp;
            tmp = new Pesna[n+1];
            copy(pesni,pesni+n,tmp);
            tmp[n++]=nova;
            delete [] pesni;
            this->pesni = new Pesna[n];
            pesni = tmp;
            max-=nova.getMin();
        }
    }
    void pecatiPesniPoTip(tip t){
        for(int i=0;i<n;i++){
            if(t==pesni[i].getTip()){
                pesni[i].pecati();
            }
        }
    }
    int getBroj(){
        return n;
    }
    Pesna getPesna(int i){
        return pesni[i];
    }
};

int main() {
	// se testira zadacata modularno
    int testCase;
    cin >> testCase;
	
	int n, minuti, kojtip;
	char ime[50];
	
	if(testCase == 1) {
        cout << "===== Testiranje na klasata Pesna ======" << endl;
        cin >> ime;
        cin >> minuti;
        cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
        Pesna p(ime,minuti,(tip)kojtip);
		p.pecati();
    } else if(testCase == 2) {
        cout << "===== Testiranje na klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        	for (int i=0; i<n; i++)
				(omileno.getPesna(i)).pecati();
	}
    else if(testCase == 3) {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        	for (int i=0; i<omileno.getBroj(); i++)
				(omileno.getPesna(i)).pecati();
    }
    else if(testCase == 4) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);
        	
    }
    else if(testCase == 5) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);
        	
    }
    return 0;
}