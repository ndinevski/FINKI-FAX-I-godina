//https://i.imgur.com/9d5m7lD.png

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

class ZicanInstrument{
    protected:
        char ime[20];
        int zici;
        int cenas;
    public:
        ZicanInstrument(char * ime="", int zici=0, int cenas=0){
            strcpy(this->ime,ime);
            this->zici = zici;
            this->cenas = cenas;
        }
        int getZici(){
            return zici;
        }
        virtual float cena() = 0;    
};
bool operator == (ZicanInstrument * a, ZicanInstrument & b){
    return (a->getZici() == b.getZici());
}     


class Mandolina : public ZicanInstrument {
    protected:
        char forma[20];
    public:
        Mandolina(char * ime="", int zici=0, int cenas=0, char * forma="") : ZicanInstrument(ime,zici,cenas){
            strcpy(this->forma,forma);
        }
        float cena(){
            if(!strcmp(this->forma,"Neapolitan")){
                return cenas*1.15;
            }
            return cenas;
        }
        friend ostream &operator <<(ostream &o, Mandolina &m){
            o<<m.ime<<" " <<m.zici<<" " <<m.cena()<<" " <<m.forma<<endl;
            return o;
        }
        
};

class Violina : public ZicanInstrument {
    protected:
        float golemina;
    public:
        Violina(char * ime="", int zici=0, int cenas=0, float golemina=0): ZicanInstrument(ime,zici,cenas){
            this->golemina = golemina;
        }
        float cena(){
            if(golemina==0.25){
                return cenas*1.1;
            }else if(golemina==1){
                return cenas*1.2;
            }
            return cenas;
        }
        friend ostream &operator <<(ostream &o, Violina &v){
            o<<v.ime<<" " <<v.zici<<" " <<v.cena()<<" " <<v.golemina<<endl;
            return o;
        }


};

void pecatiInstrumenti(ZicanInstrument &zi, ZicanInstrument ** inst, int n){
    for(int i=0;i<n;i++){
        if(inst[i]==zi){
            cout<<inst[i]->cena()<<endl;
        }
    }
}

//Vasiot kod ovde:

int main() {
	char ime[20];
	int brojZici;
	float cena;
	char forma[20];
	cin >> ime >> brojZici >> cena >> forma;
	Mandolina m(ime, brojZici, cena, forma);
	int n;
	cin >> n;
	ZicanInstrument **zi = new ZicanInstrument*[2 * n];
	for(int i = 0; i < n; ++i) {
		cin >> ime >> brojZici >> cena >> forma;
		zi[i] = new Mandolina(ime, brojZici, cena, forma);
	}
	for(int i = 0; i < n; ++i) {
		float golemina;
		cin >> ime >> brojZici >> cena >> golemina;
		zi[n + i] = new Violina(ime, brojZici, cena, golemina);
	}
	pecatiInstrumenti(m, zi, 2 * n);
	for(int i = 0; i < 2 * n; ++i) {
		delete zi[i];
	}
	delete [] zi;
	return 0;
}