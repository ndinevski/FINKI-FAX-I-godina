//https://i.imgur.com/NnFT25H.png
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

class NegativnaVrednost{
    public:
    NegativnaVrednost(){}
    void message(){
        cout<<"Oglasot ima nevalidna vrednost za cenata i nema da bide evidentiran!"<<endl;
    }

};


class Oglas{
    protected:
    char naslov[50];
    char kategorija[30];
    char opis[100];
    float cena;
    public:
        Oglas(const char * naslov = "", const char * kategorija = "", const char * opis="", float cena = 0){
            strcpy(this->naslov, naslov);
            strcpy(this->kategorija, kategorija);
            strcpy(this->opis, opis);
            this->cena = cena;
        }
        bool operator > (const Oglas& o){
            if(cena > o.cena){
                return true;
            }
            return false;
        }

        float getCena(){
            return cena;
        }

        char * getKategorija(){
            return kategorija;
        }

        friend ostream & operator <<(ostream & o, Oglas & a){
            return o<<a.naslov<<endl<<a.opis<<endl<<a.cena<<" evra"<<endl;
        }
};

class Oglasnik{
    protected:
        char ime[20];
        Oglas * niza;
        int n;
    public:
        Oglasnik(const char * ime=""){
            strcpy(this->ime, ime);
            this->n=0;
            niza = new Oglas[n];
        }
        Oglasnik & operator += (Oglas & o){
            for(int i=0; i<n; i++){
                if(o.getCena() <  0){
                    throw NegativnaVrednost();
                    return *this;
                }
            }
            Oglas * tmp = new Oglas[n+1];
            copy(niza, niza+n, tmp);
            delete [] niza;
            tmp[n++]=o;
            niza = tmp;
            return *this;
        }
        friend ostream & operator <<(ostream & o, Oglasnik & s){
            o<<s.ime<<endl;
            for (int i = 0; i < s.n; i++){
                o<<s.niza[i]<<endl;
            }
            return o;
        }

        void oglasiOdKategorija(const char *k){
            for(int i = 0; i < n; i++){
                if(strcmp(niza[i].getKategorija(), k)==0){
                    cout<<niza[i]<<endl;
                }
            }
        }
        void najniskaCena(){
            int min=1000000, indeks;
            for(int i= 0; i < n; i++){
                if(niza[i].getCena()<min){
                    min=niza[i].getCena();
                    indeks=i;
                }
            }
            cout<<niza[indeks]<<endl;
        }

};


int main(){
    
    char naslov[50];
    char kategorija[30];
    char opis[100];
    float cena;
    char naziv[50];
    char k[30];
    int n;
    
    int tip;
    cin>>tip;
    
    if (tip==1){
        cout<<"-----Test Oglas & operator <<-----" <<endl;
        cin.get();
		cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o(naslov, kategorija, opis, cena);
        cout<<o;
    }
    else if (tip==2){
    	cout<<"-----Test Oglas & operator > -----" <<endl;
        cin.get();
		cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o1(naslov, kategorija, opis, cena);
        cin.get();
		cin.getline(naslov,49);
        cin.getline(kategorija,29);
        cin.getline(opis,99);
        cin>>cena;
        Oglas o2(naslov, kategorija, opis, cena);
        if (o1>o2) cout<<"Prviot oglas e poskap."<<endl;
        else cout<<"Prviot oglas ne e poskap."<<endl;    
    }
    else if (tip==3){
        cout<<"-----Test Oglasnik, operator +=, operator << -----" <<endl ;
        cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
        	Oglas o(naslov, kategorija, opis, cena);
            ogl+=o;
        }
        cout<<ogl;
    }
    else if (tip==4){
      	cout<<"-----Test oglasOdKategorija -----" <<endl ;
      	cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
        	Oglas o(naslov, kategorija, opis, cena);
            ogl+=o;
        }
        cin.get();
		cin.getline(k,29);
        cout<<"Oglasi od kategorijata: " <<k<<endl;
      	ogl.oglasiOdKategorija(k);
    
    }
    else if (tip==5){
    	cout<<"-----Test Exception -----" <<endl ;
      	cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
        	Oglas o(naslov, kategorija, opis, cena); 
            try{           
			ogl+=o;
            }
            catch (NegativnaVrednost & e){
                e.message();
            }
        }
        cout<<ogl;
    
    }
    else if (tip==6){
    	cout<<"-----Test najniskaCena -----" <<endl ;
      	cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
        	Oglas o(naslov, kategorija, opis, cena);            
            ogl+=o;            
        }
        cout<<"Oglas so najniska cena:"<<endl;
      	ogl.najniskaCena();
    
    }
    else if (tip==7){
    	cout<<"-----Test All -----" <<endl ;
      	cin.get();
		cin.getline(naziv,49);
        cin>>n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++){
            cin.get();
            cin.getline(naslov,49);
            cin.getline(kategorija,29);
            cin.getline(opis,99);
            cin>>cena;
        	Oglas o(naslov, kategorija, opis, cena);   
            try{         
            ogl+=o;
            }
            catch(NegativnaVrednost e){
                e.message();
            }
        }
        cout<<ogl;
        
        cin.get();
        cin.get();
		cin.getline(k,29);
        cout<<"Oglasi od kategorijata: " <<k<<endl;
      	ogl.oglasiOdKategorija(k);
        
        cout<<"Oglas so najniska cena:"<<endl;
      	ogl.najniskaCena();
    
    }
    
	return 0;
}
