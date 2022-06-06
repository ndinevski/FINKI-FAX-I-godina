//https://i.imgur.com/5jtYI6M.png

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

class Vozac{
    protected:
        char name[100];
        int age;
        int race;
        bool veteran;
        void cpys(const Vozac & o){
            strcpy(this->name, o.name);
            this->age = o.age;
            this->race = o.race;
            this->veteran = o.veteran;
        }
    public:
        Vozac(const char * name="", int age=0, int race=0, bool veteran=false){
            strcpy(this->name, name);
            this->age = age;
            this->race = race;
            this->veteran = veteran;
        }
        Vozac(const Vozac & other){
            cpys(other);
        }
        Vozac& operator=(const Vozac & other){
            if(this!=&other){
                cpys(other);
            }
            return *this;
        }
        friend ostream & operator <<(ostream & o, Vozac & v){
            o<<v.name<<endl<<v.age<<endl<<v.race<<endl;
            if(v.veteran){
                o<<"VETERAN"<<endl;
            }
            return o;
        }
        virtual float zarabotuvacka()=0;
        virtual float danok()=0;

};

bool operator == (Vozac & a, Vozac & b){

}

class Avtomobilist: public Vozac {
    protected:
        float price;
    public:
        Avtomobilist(const char * name="", int age=0, int race=0, bool veteran=false, float price=0): Vozac(name,age,race,veteran){
            this->price=price;
        }
        float zarabotuvacka(){
            return (float)price/5;
        }
        float danok(){
            if(race>10){
                return 0.15*zarabotuvacka();
            }
            return 0.1*zarabotuvacka();
        }
};


class Motociklist: public Vozac{
    protected:
        int mokjnost;
    public:
        Motociklist(const char * name="", int age=0, int race=0, bool veteran=false, int mokjnost=0): Vozac(name,age,race,veteran){
            this->mokjnost=mokjnost;
        }
        float zarabotuvacka(){
            return (float)mokjnost*20;
        }
        
        float danok(){
            if(veteran){
                return 0.25*zarabotuvacka();
            }
            return 0.2*zarabotuvacka();
        }


};

int soIstaZarabotuvachka(Vozac ** vozaci, int n, Vozac * v){
    int cnt=0;
    for(int i = 0; i < n; i++){
        if(vozaci[i]->zarabotuvacka()==v->zarabotuvacka()){
            cnt++;
        }
    }
    return cnt;
}

// vashiot kod ovde

int main() {
	int n, x;
	cin >> n >> x;
	Vozac **v = new Vozac*[n];
	char ime[100];
	int vozrast;
	int trki;
	bool vet;
	for(int i = 0; i < n; ++i) {
		cin >> ime >> vozrast >> trki >> vet;
		if(i < x) {
			float cena_avto;
			cin >> cena_avto;
			v[i] = new Avtomobilist(ime, vozrast, trki, vet, cena_avto);
		} else {
			int mokjnost;
			cin >> mokjnost;
			v[i] = new Motociklist(ime, vozrast, trki, vet, mokjnost);
		}
	}
	cout << "=== DANOK ===" << endl;
	for(int i = 0; i < n; ++i) {
		cout << *v[i];
		cout << v[i]->danok() << endl;
	}
	cin >> ime >> vozrast >> trki >> vet;
	int mokjnost;
	cin >> mokjnost;
	Vozac *vx = new Motociklist(ime, vozrast, trki, vet, mokjnost);
	cout << "=== VOZAC X ===" << endl;
	cout << *vx;
	cout << "=== SO ISTA ZARABOTUVACKA KAKO VOZAC X ===" << endl;
	cout << soIstaZarabotuvachka(v, n, vx);
    for(int i = 0; i < n; ++i) {
        delete v[i];
    }
    delete [] v;
    delete vx;
	return 0;
}
