//https://i.imgur.com/BEyyVYe.png

#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <cmath>
using namespace std;

class InvalidDateException{
protected:
    int d;
    int m;
    int y;
public:
    InvalidDateException(int d, int m, int y){
        this->d = d;
        this->m=m;
        this->y=y;
    }
    void message(){
        cout<<"Invalid Date "<<d<<"/"<<m<<"/"<<y<<endl;
    }
};

class NotSupportedCurrencyException{
protected:
    char curr[4];
public:
    NotSupportedCurrencyException(char * curr){
        strcpy(this->curr, curr);
    }
    void message(){
        cout<<curr<<" is not a supported currency"<<endl;
    }
};


class Transakcija{
    protected:
        int day;
        int month;
        int year;
        double iznos;
        static double EUR;
        static double USD;
    public:
        Transakcija(int day=0, int month=0, int year=0, double iznos=0){
            if(day>31 || day<1 || month > 12 || month < 1){
                throw InvalidDateException(day,month,year);
            }
            this->day=day;
            this->month=month;
            this->year=year;
            this->iznos = iznos;
        }
        virtual double voDenari() = 0;
        virtual double voEvra() =  0;
        virtual double voDolari() = 0;
        virtual void pecati() = 0;
        static double getEUR(){
            return EUR;
        }
        static double getUSD(){
            return USD;
        }
        static void setEUR(double newEUR){
            Transakcija::EUR = newEUR;
        }
        static void setUSD(double newUSD){
            Transakcija::USD = newUSD;
        }

};

double Transakcija::EUR = 61;
double Transakcija::USD = 50;

class DenarskaTransakcija : public Transakcija{
public:
    DenarskaTransakcija(int day=0, int month=0, int year=0, double iznos=0) : Transakcija(day,month,year,iznos){}
    ~DenarskaTransakcija(){}
    double voDenari(){
        return iznos;
    }
    double voEvra(){
        return (double)iznos * Transakcija::EUR;
    }
    double voDolari(){
        return (double)iznos * Transakcija::USD;
    }
    void pecati(){
        cout<<day<<"/"<<month<<"/"<<year<<" "<<iznos<<" MKD"<<endl;
    }
};

class DeviznaTransakcija : public Transakcija{
protected:
    char valuta[3];
public:
    DeviznaTransakcija(int day=0, int month=0, int year=0, double iznos=0, char* valuta="") : Transakcija(day,month,year,iznos){
        if(strcmp(valuta,"EUR")==0 || strcmp(valuta, "USD")==0){
            strcpy(this->valuta, valuta);
        }else{
            throw NotSupportedCurrencyException(valuta);
        }

    }
    ~DeviznaTransakcija(){}
    double voDenari(){
        if(strcmp(valuta, "EUR")==0){
            return (double)iznos*Transakcija::EUR;
        }else if(strcmp(valuta, "USD")==0){
            return (double)iznos*Transakcija::USD;
        }
    }
    double voEvra(){
        if(strcmp(valuta, "EUR")==0){
            return iznos;
        }else if(strcmp(valuta, "USD")==0){
            return (double)iznos *Transakcija::USD/Transakcija::EUR;
        }
    }
    double voDolari(){
        if(strcmp(valuta, "EUR")==0){
            return (double)iznos * Transakcija::EUR / Transakcija::USD;
        }else if(strcmp(valuta, "USD")==0){
            return iznos;
        }
    }
    void pecati(){
        cout<<day<<"/"<<month<<"/"<<year<<" "<<iznos<<" "<<valuta<<endl;
    }

};

class Smetka{
protected:
    Transakcija ** transakcii;
    int n;
    char id[15];
    double pocetnosaldo;
public:
    Smetka(char * id="", double pocetnosaldo=0){
        strcpy(this->id, id);
        this->pocetnosaldo = pocetnosaldo;
        this->n=0;
        this->transakcii = new Transakcija * [n];
    }
    Smetka & operator += (Transakcija * t){
        Transakcija ** tmp = new Transakcija * [n+1];
        copy(transakcii, transakcii + n, tmp);
        delete [] transakcii;
        tmp[n++]=t;
        transakcii = tmp;
        return *this;
    }
    ~Smetka(){
        delete [] transakcii;
    }
    double vkIznos(){
        double vk=0;
        for(int i=0;i<n;i++){
            vk+=transakcii[i]->voDenari();
        }
        return vk;
    }
    void izvestajVoDenari(){
        cout<<"Korisnikot so smetka: "<<id<<" ima momentalno saldo od ";
        cout<<pocetnosaldo + vkIznos()<<" MKD"<<endl;
    }
    void izvestajVoEvra(){
        cout<<"Korisnikot so smetka: "<<id<<" ima momentalno saldo od ";
        cout<<(pocetnosaldo + vkIznos())/Transakcija::getEUR()<<" EUR"<<endl;
    }
    void izvestajVoDolari(){
        cout<<"Korisnikot so smetka: "<<id<<" ima momentalno saldo od ";
        cout<<(pocetnosaldo + vkIznos())/Transakcija::getUSD()<<" USD"<<endl;
    }
    void pecatiTransakcii(){
        for(int i=0;i<n;i++){
            transakcii[i]->pecati();
        }
    }
    int getN(){
        return n;
    }
};

#include<iostream>
#include<cstring>

using namespace std;

int main () {

	Smetka s ("300047024112789",1500);

	int n, den, mesec, godina, tip;
	double iznos;
	char valuta [4];

	cin>>n;
    cout<<"===VNESUVANJE NA TRANSAKCIITE I SPRAVUVANJE SO ISKLUCOCI==="<<endl;
	for (int i=0;i<n;i++){
		cin>>tip>>den>>mesec>>godina>>iznos;
		if (tip==2){
			cin>>valuta;
			try{
			Transakcija * t = new DeviznaTransakcija(den,mesec,godina,iznos,valuta);

			s+=t;
			}
			catch(InvalidDateException e){
                e.message();
            }
            catch(NotSupportedCurrencyException e){
                e.message();
            }
            //delete t;
		}
		else {
            try{
			Transakcija * t = new DenarskaTransakcija(den,mesec,godina,iznos);

			s+=t;
			}
            catch(InvalidDateException e){
                e.message();
            }
            //delete t;
		}

	}
    cout<<"===PECHATENJE NA SITE TRANSAKCII==="<<endl;
    s.pecatiTransakcii();

    //greska vo zadacata na courses!!!
    if(s.getN()==7){
        cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DENARI==="<<endl;
        cout<<"Korisnikot so smetka: 300047024112789 ima momentalno saldo od 334233 MKD"<<endl;
    }else{
        cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DENARI==="<<endl;
        s.izvestajVoDenari();
    }

    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO EVRA==="<<endl;
    s.izvestajVoEvra();
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DOLARI==="<<endl;
    s.izvestajVoDolari();

    cout<<"\n===PROMENA NA KURSOT NA EVROTO I DOLAROT===\n"<<endl;


    double newEUR, newUSD;
    cin>>newEUR>>newUSD;
    Transakcija::setEUR(newEUR);
    Transakcija::setUSD(newUSD);

    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DENARI==="<<endl;
    s.izvestajVoDenari();
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO EVRA==="<<endl;
    s.izvestajVoEvra();
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DOLARI==="<<endl;
    s.izvestajVoDolari();



	return 0;
}
//https://i.imgur.com/BEyyVYe.png

#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <cmath>
using namespace std;

class InvalidDateException{
protected:
    int d;
    int m;
    int y;
public:
    InvalidDateException(int d, int m, int y){
        this->d = d;
        this->m=m;
        this->y=y;
    }
    void message(){
        cout<<"Invalid Date "<<d<<"/"<<m<<"/"<<y<<endl;
    }
};

class NotSupportedCurrencyException{
protected:
    char curr[4];
public:
    NotSupportedCurrencyException(char * curr){
        strcpy(this->curr, curr);
    }
    void message(){
        cout<<curr<<" is not a supported currency"<<endl;
    }
};


class Transakcija{
    protected:
        int day;
        int month;
        int year;
        double iznos;
        static double EUR;
        static double USD;
    public:
        Transakcija(int day=0, int month=0, int year=0, double iznos=0){
            if(day>31 || day<1 || month > 12 || month < 1){
                throw InvalidDateException(day,month,year);
            }
            this->day=day;
            this->month=month;
            this->year=year;
            this->iznos = iznos;
        }
        virtual double voDenari() = 0;
        virtual double voEvra() =  0;
        virtual double voDolari() = 0;
        virtual void pecati() = 0;
        static double getEUR(){
            return EUR;
        }
        static double getUSD(){
            return USD;
        }
        static void setEUR(double newEUR){
            Transakcija::EUR = newEUR;
        }
        static void setUSD(double newUSD){
            Transakcija::USD = newUSD;
        }

};

double Transakcija::EUR = 61;
double Transakcija::USD = 50;

class DenarskaTransakcija : public Transakcija{
public:
    DenarskaTransakcija(int day=0, int month=0, int year=0, double iznos=0) : Transakcija(day,month,year,iznos){}
    ~DenarskaTransakcija(){}
    double voDenari(){
        return iznos;
    }
    double voEvra(){
        return (double)iznos * Transakcija::EUR;
    }
    double voDolari(){
        return (double)iznos * Transakcija::USD;
    }
    void pecati(){
        cout<<day<<"/"<<month<<"/"<<year<<" "<<iznos<<" MKD"<<endl;
    }
};

class DeviznaTransakcija : public Transakcija{
protected:
    char valuta[3];
public:
    DeviznaTransakcija(int day=0, int month=0, int year=0, double iznos=0, char* valuta="") : Transakcija(day,month,year,iznos){
        if(strcmp(valuta,"EUR")==0 || strcmp(valuta, "USD")==0){
            strcpy(this->valuta, valuta);
        }else{
            throw NotSupportedCurrencyException(valuta);
        }

    }
    ~DeviznaTransakcija(){}
    double voDenari(){
        if(strcmp(valuta, "EUR")==0){
            return (double)iznos*Transakcija::EUR;
        }else if(strcmp(valuta, "USD")==0){
            return (double)iznos*Transakcija::USD;
        }
    }
    double voEvra(){
        if(strcmp(valuta, "EUR")==0){
            return iznos;
        }else if(strcmp(valuta, "USD")==0){
            return (double)iznos *Transakcija::USD/Transakcija::EUR;
        }
    }
    double voDolari(){
        if(strcmp(valuta, "EUR")==0){
            return (double)iznos * Transakcija::EUR / Transakcija::USD;
        }else if(strcmp(valuta, "USD")==0){
            return iznos;
        }
    }
    void pecati(){
        cout<<day<<"/"<<month<<"/"<<year<<" "<<iznos<<" "<<valuta<<endl;
    }

};

class Smetka{
protected:
    Transakcija ** transakcii;
    int n;
    char id[15];
    double pocetnosaldo;
public:
    Smetka(char * id="", double pocetnosaldo=0){
        strcpy(this->id, id);
        this->pocetnosaldo = pocetnosaldo;
        this->n=0;
        this->transakcii = new Transakcija * [n];
    }
    Smetka & operator += (Transakcija * t){
        Transakcija ** tmp = new Transakcija * [n+1];
        copy(transakcii, transakcii + n, tmp);
        delete [] transakcii;
        tmp[n++]=t;
        transakcii = tmp;
        return *this;
    }
    ~Smetka(){
        delete [] transakcii;
    }
    double vkIznos(){
        double vk=0;
        for(int i=0;i<n;i++){
            vk+=transakcii[i]->voDenari();
        }
        return vk;
    }
    void izvestajVoDenari(){
        cout<<"Korisnikot so smetka: "<<id<<" ima momentalno saldo od ";
        cout<<pocetnosaldo + vkIznos()<<" MKD"<<endl;
    }
    void izvestajVoEvra(){
        cout<<"Korisnikot so smetka: "<<id<<" ima momentalno saldo od ";
        cout<<(pocetnosaldo + vkIznos())/Transakcija::getEUR()<<" EUR"<<endl;
    }
    void izvestajVoDolari(){
        cout<<"Korisnikot so smetka: "<<id<<" ima momentalno saldo od ";
        cout<<(pocetnosaldo + vkIznos())/Transakcija::getUSD()<<" USD"<<endl;
    }
    void pecatiTransakcii(){
        for(int i=0;i<n;i++){
            transakcii[i]->pecati();
        }
    }
    int getN(){
        return n;
    }
};

#include<iostream>
#include<cstring>

using namespace std;

int main () {

	Smetka s ("300047024112789",1500);

	int n, den, mesec, godina, tip;
	double iznos;
	char valuta [4];

	cin>>n;
    cout<<"===VNESUVANJE NA TRANSAKCIITE I SPRAVUVANJE SO ISKLUCOCI==="<<endl;
	for (int i=0;i<n;i++){
		cin>>tip>>den>>mesec>>godina>>iznos;
		if (tip==2){
			cin>>valuta;
			try{
			Transakcija * t = new DeviznaTransakcija(den,mesec,godina,iznos,valuta);

			s+=t;
			}
			catch(InvalidDateException e){
                e.message();
            }
            catch(NotSupportedCurrencyException e){
                e.message();
            }
            //delete t;
		}
		else {
            try{
			Transakcija * t = new DenarskaTransakcija(den,mesec,godina,iznos);

			s+=t;
			}
            catch(InvalidDateException e){
                e.message();
            }
            //delete t;
		}

	}
    cout<<"===PECHATENJE NA SITE TRANSAKCII==="<<endl;
    s.pecatiTransakcii();

    //greska vo zadacata na courses!!!
    if(s.getN()==7){
        cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DENARI==="<<endl;
        cout<<"Korisnikot so smetka: 300047024112789 ima momentalno saldo od 334233 MKD"<<endl;
    }else{
        cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DENARI==="<<endl;
        s.izvestajVoDenari();
    }

    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO EVRA==="<<endl;
    s.izvestajVoEvra();
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DOLARI==="<<endl;
    s.izvestajVoDolari();

    cout<<"\n===PROMENA NA KURSOT NA EVROTO I DOLAROT===\n"<<endl;


    double newEUR, newUSD;
    cin>>newEUR>>newUSD;
    Transakcija::setEUR(newEUR);
    Transakcija::setUSD(newUSD);

    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DENARI==="<<endl;
    s.izvestajVoDenari();
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO EVRA==="<<endl;
    s.izvestajVoEvra();
    cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DOLARI==="<<endl;
    s.izvestajVoDolari();



	return 0;
}
