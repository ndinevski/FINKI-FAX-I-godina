//https://i.imgur.com/yQkmkzV.png

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

class Transport{
    protected:
        char destinacija [20];
        int cena;
        int km;
    public:
        Transport(const char * destinacija = "", int cena=0, int km=0){
            strcpy(this->destinacija, destinacija);
            this->cena = cena;
            this->km = km;
        }
        Transport(const Transport & t){
            strcpy(this->destinacija, t.destinacija);
            this->cena = t.cena;
            this->km = t.km;
        }
        int getCena(){
            return cena;
        }
        int getKm(){
            return km;
        }
        char *getDest(){
            return destinacija;
        }
        virtual float cenaTransport() = 0;

        bool operator < ( Transport & t ){
            if(destinacija < t.destinacija){
                return true;
            }
            return false;
        }

};


class AvtomobilTransport: public Transport{
    protected:
        bool platensofer;
    public:
        AvtomobilTransport(const char * destinacija = "", int cena=0, int km=0, bool platensofer=false): Transport(destinacija, cena, km){
            this->platensofer= platensofer;
        }
        bool getSofer(){
            return platensofer;
        }
        float cenaTransport(){
            if(platensofer){
                return 1.2*cena;
            }
            return cena;
        }
};

class KombeTransport: public Transport{
    protected:
        int lugje;
    public:
        KombeTransport(const char * destinacija = "", int cena=0, int km=0, int lugje=0): Transport(destinacija, cena, km){
            this->lugje= lugje;
        }
        int getLugje(){
            return lugje;
        }

        float cenaTransport(){
            return cena - lugje*200;
        }



};

void pecatiPoloshiPonudi(Transport ** ponudi,int n,AvtomobilTransport &nov){
    //bubble sort
    Transport * tmp;
    for(int i=0;i<n;i++){

        for(int j=0;j<n-i-1;j++){
            if(ponudi[j]->cenaTransport()>ponudi[j+1]->cenaTransport()){
                tmp = ponudi[j];
                ponudi[j]= ponudi[j+1];
                ponudi[j+1]=tmp;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        if(ponudi[i]->cenaTransport()>nov.cenaTransport()){
            cout<<ponudi[i]->getDest()<<" "<<ponudi[i]->getKm()<<" "<<ponudi[i]->cenaTransport()<<endl;
        }
    }
}









// вашиот код треба да биде тука

int main(){

char destinacija[20];
int tip,cena,rastojanie,lugje;
bool shofer;
int n;
cin>>n;
Transport  **ponudi;
ponudi=new Transport *[n];

for (int i=0;i<n;i++){

    cin>>tip>>destinacija>>cena>>rastojanie;
    if (tip==1) {
        cin>>shofer;
        ponudi[i]=new AvtomobilTransport(destinacija,cena,rastojanie,shofer);

    }
    else {
        cin>>lugje;
        ponudi[i]=new KombeTransport(destinacija,cena,rastojanie,lugje);
    }


}

AvtomobilTransport nov("Ohrid",2000,600,false);
pecatiPoloshiPonudi(ponudi,n,nov);

for (int i=0;i<n;i++) delete ponudi[i];
delete [] ponudi;
return 0;
}
