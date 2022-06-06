//https://i.imgur.com/NGmXXMW.png

//https://i.imgur.com/gvoG5LI.png
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

class SMS{
    protected:
        float osnovnacena;
        char broj[20];
    public:
        SMS(const char * broj ="",float osnovnacena = 0){
            this->osnovnacena = osnovnacena;
            strcpy(this->broj, broj);
        }
        SMS(const SMS& other){
            this->osnovnacena = other.osnovnacena;
            strcpy(this->broj, other.broj);
        }
        //apstract method
        virtual float SMS_cena() = 0;
        friend ostream & operator<<(ostream & o, SMS & s){
            o<<"Tel: "<<s.broj<<" - cena: "<<s.SMS_cena()<<"den."<<endl;
            return o;
        }
};

class RegularSMS : public SMS{
    protected:
        char msg[1000];
        int roaming;
        static int rProcent;
    public:
        RegularSMS(const char * broj ="",float osnovnacena = 0, const char * msg="", int roaming=0): SMS(broj, osnovnacena){
            strcpy(this->msg, msg);
            this->roaming = roaming;
        }
        float SMS_cena(){
            int smsporaki;
            if(strlen(msg)<160){
                smsporaki =1;
            }else if(strlen(msg)>=160 && strlen(msg)<320){
                smsporaki=2;
            }else{
                smsporaki =3;
            }
           
            if(roaming){
                return (smsporaki * ((RegularSMS::rProcent+100)/100.0) * osnovnacena);
            }else{
                return (1.18*smsporaki * osnovnacena);
            }
        }
        static void set_rProcent(int a){
            RegularSMS::rProcent = a;
        }
        friend ostream & operator<<(ostream & o, RegularSMS & s){
            o<<"Tel: "<<s.broj<<" - cena: "<<s.SMS_cena()<<"den."<<endl;
            return o;
        }
        
};

int RegularSMS::rProcent=300;


class SpecialSMS : public SMS{
    protected:
        bool humanitarna;
        static int sProcent;
    public:
        SpecialSMS(const char * broj ="",float osnovnacena = 0,bool humanitarna=false): SMS(broj, osnovnacena){
            this->humanitarna = humanitarna;
        }
        float SMS_cena(){
            if(!humanitarna){
                return osnovnacena * (SpecialSMS::sProcent+100)/100.0;
            }else{
                return osnovnacena;
            }
        }
        static void set_sProcent( int a){
            SpecialSMS::sProcent = a;
        }
        friend ostream & operator<<(ostream & o, SpecialSMS & s){
            o<<"Tel: "<<s.broj<<" - cena: "<<s.SMS_cena()<<"den."<<endl;
            return o;
        }
};
int SpecialSMS::sProcent=150;


void vkupno_SMS(SMS ** poraka, int n){
    int cnt=0, cntt=0;
    float  vkregularni=0, vkspecial=0;
    for(int i = 0; i<n; i++){
        RegularSMS * tmp = dynamic_cast<RegularSMS *>(poraka[i]);
        SpecialSMS * tmpp = dynamic_cast<SpecialSMS *>(poraka[i]);
        if(tmp){
            cnt++;
            vkregularni+= tmp->SMS_cena();
        }else{
            cntt++;
            vkspecial += tmpp->SMS_cena();
        }
    }
    cout<<"Vkupno ima "<<cnt<<" regularni SMS poraki i nivnata cena e: "<< vkregularni<<endl;
    cout<<"Vkupno ima "<<cntt<<" specijalni SMS poraki i nivnata cena e: "<< vkspecial<<endl;
}















int main(){

	char tel[20], msg[1000];
	float cena;
	float price;
    int p;
	bool  hum;
    int roam;
	SMS  **sms;
	int n;
	int tip;

	int testCase;
	cin >> testCase;

	if (testCase == 1){
		cout << "====== Testing RegularSMS class ======" << endl;
		cin >> n;
		sms = new SMS *[n];

		for (int i = 0; i < n; i++){
			cin >> tel;
			cin >> cena;
            cin.get();
			cin.getline(msg, 1000);
			cin >> roam;
			cout << "CONSTRUCTOR" << endl;
			sms[i] = new RegularSMS(tel, cena, msg, roam);
			cout << "OPERATOR <<" << endl;
			cout << *sms[i];
		}
        for (int i = 0; i<n; i++) delete sms[i];
		delete[] sms;
	}
	if (testCase == 2){
		cout << "====== Testing SpecialSMS class ======" << endl;
		cin >> n;
		sms = new SMS *[n];

		for (int i = 0; i < n; i++){
			cin >> tel;
			cin >> cena;
			cin >> hum;
			cout << "CONSTRUCTOR" << endl;
			sms[i] = new SpecialSMS(tel, cena, hum);
			cout << "OPERATOR <<" << endl;
			cout << *sms[i];
		}
        for (int i = 0; i<n; i++) delete sms[i];
		delete[] sms;
	}
	if (testCase == 3){
		cout << "====== Testing method vkupno_SMS() ======" << endl;
		cin >> n;
		sms = new SMS *[n];

		for (int i = 0; i<n; i++){

			cin >> tip;
			cin >> tel;
			cin >> cena;
			if (tip == 1) {

				cin.get();
				cin.getline(msg, 1000);
                cin >> roam;
				
				sms[i] = new RegularSMS(tel, cena, msg, roam);

			}
			else {
				cin >> hum;

				sms[i] = new SpecialSMS(tel, cena, hum);
			}
		}

		vkupno_SMS(sms, n);
        for (int i = 0; i<n; i++) delete sms[i];
		delete[] sms;
	}
    if (testCase == 4){
		cout << "====== Testing RegularSMS class with a changed percentage======" << endl;	
        SMS *sms1, *sms2;	
        	cin >> tel;
			cin >> cena;
            cin.get();
			cin.getline(msg, 1000);
			cin >> roam;
			sms1 = new RegularSMS(tel, cena, msg, roam);
			cout << *sms1;
        
            cin >> tel;
			cin >> cena;
            cin.get();
			cin.getline(msg, 1000);
			cin >> roam;	
        	cin >> p;
        	RegularSMS::set_rProcent(p);
        	sms2 = new RegularSMS(tel, cena, msg, roam);
        	cout << *sms2;
        
        delete sms1, sms2;
	}
    if (testCase == 5){
		cout << "====== Testing SpecialSMS class with a changed percentage======" << endl;	
        SMS *sms1, *sms2;	
        	cin >> tel;
			cin >> cena;
			cin >> hum;
			sms1 = new SpecialSMS(tel, cena, hum);
			cout << *sms1;
        
            cin >> tel;
			cin >> cena;
			cin >> hum;	
        	cin >> p;
        	SpecialSMS::set_sProcent(p);
        	sms2 = new SpecialSMS(tel, cena, hum);
        	cout << *sms2;
        
        delete sms1, sms2;
	}
	
	return 0;
}
