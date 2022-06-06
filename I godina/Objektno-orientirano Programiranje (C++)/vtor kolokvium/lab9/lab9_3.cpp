//https://i.imgur.com/ZULQaV7.png

#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <cmath>
using namespace std;

class RegistrationException{
    public:
        void message(){
            cout<<"Pogresno vnesena registracija"<<endl;
        }
};

bool okRegistracija(char * reg){
    if(strlen(reg)==8){
        if(!isdigit(reg[0]) && !isdigit(reg[1]) && !isdigit(reg[7]) && !isdigit(reg[6])){
            return true;
        }
    }
    return false;
}

class ImaMasa{
    public:
        virtual double vratiMasa() = 0;
        virtual void pecati() = 0;
};

class PaketPijalok{
    protected:
        double volumenEden;
        int kolicina;
        static double PACKET;
        static double DENSE;
    public:
        PaketPijalok(double volumenEden=0,int kolicina=0){
            this->volumenEden = volumenEden;
            this->kolicina = kolicina;
        }
        double vratiMasa(){
            return ((double)volumenEden*DENSE + PACKET)*kolicina;
        }
        // void pecati()
        int getKolicina(){
            return kolicina;
        }
};

double PaketPijalok::PACKET = 0.2;
double PaketPijalok::DENSE =0.8;


class PaketSok : public ImaMasa, public PaketPijalok{
    private:
        bool daliGaziran;
    public:
        PaketSok(double volumenEden=0,int kolicina=0, bool daliGaziran=false):PaketPijalok(volumenEden,kolicina){
            this->daliGaziran=daliGaziran;
        }
        double vratiMasa(){
            if(daliGaziran){
                return (double) PaketPijalok::vratiMasa();
            }else{
                return (double) PaketPijalok::vratiMasa() + kolicina*0.1;
            }
        }
        void pecati(){
            cout<<"Paket sok"<<endl;
            cout<<"kolicina "<<kolicina;
            cout<<", so po "<<volumenEden*PaketPijalok::DENSE<<" l(dm3)"<<endl;
        }
};


class PaketVino : public ImaMasa, public PaketPijalok{
    private:
        double procentAlkohol;
    public:
        PaketVino(double volumenEden=0,int kolicina=0, double procentAlkohol=0):PaketPijalok(volumenEden,kolicina){
            this->procentAlkohol= procentAlkohol;
        }
        double vratiMasa(){
            return (double) PaketPijalok::vratiMasa()*(0.9+procentAlkohol);
        }
        void pecati(){
            cout<<"Paket vino"<<endl;
            cout<<"kolicina "<<kolicina<<", "<<getProcentAlkohol()*100.0;
            cout<<"% alkohol od po "<<volumenEden*PaketPijalok::DENSE<<" l(dm3)"<<endl;
        }
        double getProcentAlkohol(){
            return procentAlkohol;
        }
};


class Kamion{
    char registration[50];
    char vozac[50];
    ImaMasa ** elementi;
    int n;
    public:
        Kamion(char * vozac=""){
            strcpy(this->vozac, vozac);
            this->n=0;
            elementi = new ImaMasa * [n];
        }
        Kamion(char * registration="", char * vozac=""){
            if(!okRegistracija(registration)){
                throw RegistrationException();
            }
            strcpy(this->vozac, vozac);
            strcpy(this->registration, registration);
            this->n=0;
            elementi = new ImaMasa * [n];
        }
        void registriraj(char * registration){
            if(!okRegistracija(registration)){
                throw RegistrationException();
            }
            strcpy(this->registration, registration);
        }
        void dodadiElement(ImaMasa * m){
            ImaMasa ** tmp = new ImaMasa * [n+1];
            copy(elementi, elementi+n, tmp);
            delete [] elementi;
            tmp[n++] = m;
            elementi = tmp;
        }
        double vratiVkupnaMasa(){
            double vk=0;
            for(int i=0; i<n; i++){
                vk+=elementi[i]->vratiMasa();
            }
            return vk;
        }
        void pecati(){
            cout<<"Kamion so registracija "<<this->registration;
            cout<<" i vozac "<<vozac<<" prenesuva:"<<endl;
            for(int i=0; i<n; i++){
                elementi[i]->pecati();
            }
        }
        Kamion pretovar(char * registration,char * vozac){
            Kamion t(registration, vozac);
            double max=0, index=0;
             for (int i=0; i<n; i++)
                if (elementi[i]->vratiMasa()>max){
                    max=elementi[i]->vratiMasa();
                    index=i;
                }
            for (int i=0; i<n; i++)
                if (i!=index)
                    t.dodadiElement(elementi[i]);
            return t;
        }
    
};


int main(){
    try{
    char ime[20], reg[9];
    double vol;
    int kol;
    bool g;
    double proc;
    cin>>reg;
    cin>>ime;
    // try{
        Kamion A(reg, ime);
    // }
    // catch(RegistrationException & e){
    //     e.message();
    // }
    ImaMasa **d = new ImaMasa*[5];
    cin>>vol>>kol;
    cin>>g;
    d[0] = new PaketSok(vol, kol, g);
    cin>>vol>>kol;
    cin>>proc;
    d[1] = new PaketVino(vol, kol, proc);
    cin>>vol>>kol;
    cin>>proc;
    d[2] = new PaketVino(vol, kol, proc);
    cin>>vol>>kol;
    cin>>g;
    d[3] = new PaketSok(vol, kol, g);
    cin>>vol>>kol;
    cin>>proc;
    d[4] = new PaketVino(vol, kol, proc);

    A.dodadiElement(d[0]);
    A.dodadiElement(d[1]);
    A.dodadiElement(d[2]);
    A.dodadiElement(d[3]);
    A.dodadiElement(d[4]);
    A.pecati();
    cout<<"Vkupna masa: "<<A.vratiVkupnaMasa()<<endl;
    cin>>reg;
    cin>>ime;
    // try{
        Kamion B = A.pretovar(reg, ime);
    // }
    // catch(RegistrationException & e){
    //     e.message();
    // }
    B.pecati();
    cout<<"Vkupna masa: "<<B.vratiVkupnaMasa()<<endl;
    return 0;
    }
    catch(RegistrationException & e){
        e.message();
    }
}
