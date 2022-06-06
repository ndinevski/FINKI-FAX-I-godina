//https://i.imgur.com/SGxLTRP.png
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

class InvalidProductionDate{
    public:
        InvalidProductionDate(){}
        void message(){
            cout<<"Невалидна година на производство"<<endl;
        }
};


enum tip{
    smartphone,
    computer
};

class Device{
    protected:
        char model[100];
        tip ured;
        static float casovi;
        int godina;
        void cpys(const Device & d){
            strcpy(this->model, d.model);
            this->ured = d.ured;
            this->godina = d.godina;
        }
    public:
        Device(const char * model="", tip ured=smartphone, int godina=0){
            strcpy(this->model, model);
            this->ured = ured;
            this->godina = godina;
        }
        Device(const Device& other){
            cpys(other);
        }
        Device & operator = (const Device & d){
            if(this!=&d){
                cpys(d);
            }
            return *this;
        }
        static void setPocetniCasovi(int a){
            Device::casovi = a;
        }
        int getYear(){
            return godina;
        }
        friend ostream & operator << ( ostream & o , Device & d){
            o<<d.model<<endl;
            if((int)d.ured==0){
                o<<"Mobilen ";
                if(d.godina>2015){
                    o<<Device::casovi + 2;
                }else{
                    o<<Device::casovi;
                }
            }else{
                o<<"Laptop ";
                if(d.godina>2015){
                    o<<Device::casovi + 4;
                }else{
                    o<<Device::casovi+2;
                }
            }
            o<<endl;
            return o;
        }
};

float Device::casovi = 1;


class MobileServis{
    protected:
        char adresa[100];
        Device ** niza;
        int n;
        void cpys(const MobileServis &o){
            strcpy(this->adresa, o.adresa);
            this->n=o.n;
            this->niza=new Device *[o.n];
            copy(o.niza, o.niza + o.n, this->niza);
        }
    public:
        MobileServis(const char * adresa=""){
            strcpy(this->adresa, adresa);
            this->n=0;
            this->niza=new Device *[n];
        }

        MobileServis(const MobileServis & o){
            cpys(o);
        }

        MobileServis & operator = (const MobileServis & o){
            if(this!=&o){
                delete [] niza;
                cpys(o);
            }
            return *this;
        }

        MobileServis & operator += ( Device & d){
            if(d.getYear()>2019 || d.getYear()<2000){
                throw InvalidProductionDate();
                return *this;
            }
    
            Device ** tmp= new Device * [n+1];
            copy(niza, niza+n, tmp);
            delete [] niza;
            tmp[n++]=new Device(d);
            niza = tmp;
            return *this;



        }

        void pecatiCasovi(){
            cout<<"Ime: "<<adresa<<endl;
            for(int i=0;i<n;i++){
                cout<<*niza[i];
            }
        }


};











int main()
{
	int testCase;
	cin >> testCase;
    char ime[100];
    int tipDevice;
    int godina;
    int n;
    Device devices[50];
	if (testCase == 1){
		cout << "===== Testiranje na klasite ======" << endl;
		cin >> ime;
		cin >> tipDevice;
		cin >> godina;
		Device ig(ime,(tip)tipDevice,godina);
        cin>>ime;
		MobileServis t(ime);
        cout<<ig;
		}
	if (testCase == 2){
		cout << "===== Testiranje na operatorot += ======" << endl;
        cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);
            t+=tmp;
        }
        t.pecatiCasovi();
	}
	if (testCase == 3){
		cout << "===== Testiranje na isklucoci ======" << endl;
        cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);
            try{
            t+=tmp;
            }
            catch (InvalidProductionDate e){
                e.message();
            }
        }
        t.pecatiCasovi();
	}
	if (testCase == 4){
		cout <<"===== Testiranje na konstruktori ======"<<endl;
		 cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);
            try{
            t+=tmp;
            }
            catch (InvalidProductionDate e){
                e.message();
            }
        }
        MobileServis t2 = t;
        t2.pecatiCasovi();
	}
	if (testCase == 5){
		cout << "===== Testiranje na static clenovi ======" << endl;
        cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime,(tip)tipDevice,godina);

            t+=tmp;
        }
        t.pecatiCasovi();
        cout << "===== Promena na static clenovi ======" << endl;
		Device::setPocetniCasovi(2);
        t.pecatiCasovi();
	}

		if (testCase == 6){
		cout << "===== Testiranje na kompletna funkcionalnost ======" << endl;
		cin>>ime;
        cin >> n;
		MobileServis t(ime);
		for(int i=0;i<n;i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device * tnn = new Device(ime,(tip)tipDevice,godina);
            try{
            t+=*tnn;
            }
            catch (InvalidProductionDate & e){
                e.message();
            }
        }
		Device::setPocetniCasovi(3);
        MobileServis t2 = t;
        t2.pecatiCasovi();
	}

	return 0;

}

