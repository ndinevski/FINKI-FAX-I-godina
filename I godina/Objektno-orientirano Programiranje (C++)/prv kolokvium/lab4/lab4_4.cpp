//https://i.imgur.com/wlYM76G.png
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
enum zanr{
    action,
    comedy,
    drama
};

class Film{
    char * name;
    int size;
    zanr z;
    void copy(const Film & f){
        this->name=new char[strlen(f.name)+1];
        strcpy(this->name,f.name);
        this->size=f.size;
        this->z=f.z;
    }
public:
    Film(char * name="", int size=0,zanr z=action){
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
        this->size=size;
        this->z=z;
    }
    Film(const Film & f){
        copy(f);
    }
    Film & operator = (const Film & f){
        if(&f!=this){
            delete [] name;
            copy(f);
        }
        return *this;
    }
    ~Film(){
        delete [] name;
    }
    void pecati(){
        cout<<size<<"MB-\""<<name<<"\""<<endl;
    }
    zanr getZanr(){
        return z;
    }
    int getSize(){
        return size;
    }
};

class DVD{
    Film *filmovi;
    int n;
    int size;
    void copys(const DVD & d){
        this->size=d.size;
        this->n=d.n;
        this->filmovi=new Film[this->n];
        for(int i=0;i<this->n;i++){
            filmovi[i]=d.filmovi[i];
        }
    }
public:
    DVD(int size=0){
        this->filmovi=nullptr;
        this->size=size;
        this->n=0;
    }
    DVD(const DVD & d){
        copys(d);
    }
    DVD &operator = (const DVD & d){
        if(&d!=this){
            delete [] filmovi;
            copys(d);
        }
        return *this;
    }
    ~DVD(){
        delete [] filmovi;
    }
    int getBroj(){
        return n;
    }
    // int getFilm(){
    //     return 
    // }
    int calculateSize(){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=filmovi[i].getSize();
        }
        return sum;
    }
    void dodadiFilm(Film f){
        if(50-calculateSize()>=f.getSize()){
            if(n<5){
                Film * tmp;
                tmp=new Film[n+1];
                copy(filmovi,filmovi+n,tmp);
                delete [] filmovi;
                this->filmovi=new Film[n+1];
                tmp[n++]=f;
                filmovi=tmp;
            }
        }
    }
    void pecatiFilmoviDrugZanr(zanr kojzanr){
        for(int i=0;i<n;i++){
            if(kojzanr!=filmovi[i].getZanr()){
                filmovi[i].pecati();
            }
        }
    }
    Film getFilm(int i){
        for(int j=0;j<n;j++){
            if(i==j){
                return filmovi[j];
            }
        }
    }
    float procentNaMemorijaOdZanr(zanr z){
        int sumaeden=0;
        int suma=0;
        for(int i=0;i<n;i++){
            suma+=filmovi[i].getSize();
            if(filmovi[i].getZanr()==z){
                sumaeden+=filmovi[i].getSize();
            }
        }
        return (float)100*sumaeden/suma;
    }

};




int main() {
    //se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, memorija, kojzanr;
    char ime[50];

    if (testCase == 1) {
        cout << "===== Testiranje na klasata Film ======" << endl;
        cin >> ime;
        cin >> memorija;
        cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
        Film f(ime, memorija, (zanr) kojzanr);
        f.pecati();
    } else if (testCase == 2) {
        cout << "===== Testiranje na klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        for (int i = 0; i < n; i++)
            (omileno.getFilm(i)).pecati();
    } else if (testCase == 3) {
        cout << "===== Testiranje na metodot dodadiFilm() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        for (int i = 0; i < omileno.getBroj(); i++)
            (omileno.getFilm(i)).pecati();
    } else if (testCase == 4) {
        cout << "===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        omileno.pecatiFilmoviDrugZanr((zanr) kojzanr);

    } else if (testCase == 5) {
        cout << "===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        omileno.pecatiFilmoviDrugZanr((zanr) kojzanr);
    }else if (testCase == 6){
		cout<<"===== Testiranje na metodot procentNaMemorijaOdZanr() od klasata DVD =====" <<endl;
		DVD omileno(40);
		cin >> n;
		for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        cout<<"Procent na filmovi od dadeniot zanr iznesuva: "<<omileno.procentNaMemorijaOdZanr((zanr) kojzanr)<<"%\n";
		
	}
    return 0;
}