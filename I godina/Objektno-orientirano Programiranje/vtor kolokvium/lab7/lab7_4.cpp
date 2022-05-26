//https://i.imgur.com/Q61FKcu.png

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;


class Vozilo{
    protected:
        double mass;
        int width;
        int height;
    public:
        Vozilo(double mass=0, int width=0, int height=0){
            this->mass = mass;
            this->width = width;
            this->height = height;
        }
        ~Vozilo(){}
    virtual int vratiDnevnaCena() =0;
    double getMass(){
        return mass;
    }
    int getWidth(){
        return width;
    }
    int getVisina(){
        return height;
    }
};

class Avtomobil : public Vozilo{
    protected:
        int doors;
    public:
        Avtomobil(double mass=0, int width=0, int height=0, int doors=0): Vozilo(mass, width, height){
            this->doors = doors;
        }
        void setDoors(int d){
            this->doors = d;
        }
        int getDoors(){
            return doors;
        }
        int vratiDnevnaCena(){
            if(doors<5){
                return 100;
            }
            return 130;
        }

};

class Avtobus : public Vozilo{
    protected:
        int passeng;
    public:
        Avtobus(double mass=0, int width=0, int height=0, int passeng=0): Vozilo(mass, width, height){
            this->passeng = passeng;
        }
        void setPass(int p){
            this->passeng = p;
        }
        int getPass(){
            return passeng;
        }
        int vratiDnevnaCena(){
            return passeng*5;
        }

};

class Kamion : public Vozilo{
    protected:
        float max;
    public:
        Kamion(double mass=0, int width=0, int height=0, float max=0): Vozilo(mass, width, height){
            this->max = max;
        }
        void setMax(float m){
            this->max=m;
        }
        float getMax(){
            return max;
        }
        int vratiDnevnaCena(){
            return (mass+max)*0.02;
        }
};


class ParkingPlac{
    protected:
        Vozilo ** vozila;
        int n;
    public:
        ParkingPlac(){
            this->n=0;
            vozila = new Vozilo * [n];
        }
        ParkingPlac & operator +=(Vozilo * p){
            Vozilo ** tmp = new Vozilo * [n+1];
            copy(vozila, vozila + n, tmp);
            delete [] vozila;
            tmp[n++] = p;
            vozila = tmp;
            return *this;
        }

        ~ParkingPlac(){
            delete [] vozila;
        }
    
        double presmetajVkupnaMasa(){
            double vk=0;
            for(int i=0;i<n;i++){
                vk+=vozila[i]->getMass();
            }
            return vk;
        }
        int brojVozilaPoshirokiOd(int l){
            int cnt=0;
            for(int i=0;i<n;i++){
                if(vozila[i]->getWidth() > l){
                    cnt++;
                }
            }
            return cnt;
        }
        void pecati(){
            int avto=0, avtob=0, kami=0;
            for (int i=0; i<n; i++){
                Avtomobil *a=dynamic_cast<Avtomobil *>(vozila[i]);
                if (a!=0){
                 avto++;
                }
                Avtobus *av=dynamic_cast<Avtobus *>(vozila[i]);
                if (av!=0){
                avtob++;
                }
                Kamion *ka =dynamic_cast<Kamion *>(vozila[i]);
                if (ka!=0){ 
                kami++;
                }
            }
                cout<<"Brojot na avtomobili e "<<avto<<", brojot na avtobusi e "<<avtob;
                cout<<" i brojot na kamioni e "<<kami<<"."<<endl;
        
        }
        int vratiDnevnaZarabotka(){
            int vk=0;
            for (int i=0;i<n;i++){
                vk+=vozila[i]->vratiDnevnaCena();
            }
            return vk;
        }
        int pogolemaNosivostOd(Vozilo & v){
            int cnt=0;
            for(int i=0;i<n;i++){
                Kamion * ka=dynamic_cast<Kamion *>(vozila[i]);
                if(ka!=0){
                    if(vozila[i]->getMass()>v.getMass()){
                        cnt++;
                    }
                }
            }
            return cnt;
        }

};

#include<iostream>
using namespace std;
//вашиот код треба да биде тука

int main(){
ParkingPlac p;

int n;
cin>>n;
int shirina,visina, broj;
float masa,nosivost;
for (int i=0;i<n;i++){
    int type;
    cin>>type;
    if(type==1){
        cin>>masa>>shirina>>visina>>broj;
        Avtomobil *a=new Avtomobil(masa,shirina,visina,broj);
        p+=a;
    }
    if(type==2){
        cin>>masa>>shirina>>visina>>broj;
        p+=new Avtobus(masa,shirina,visina,broj);
    }
    if(type==3){
        cin>>masa>>shirina>>visina>>nosivost;
        p+=new Kamion(masa,shirina,visina,nosivost);
    }
}

p.pecati();

cout<<"\nZarabotkata e "<<p.vratiDnevnaZarabotka()<<endl;
cout<<"Vkupnata masa e "<<p.presmetajVkupnaMasa()<<endl;
cout<<"Brojot poshiroki od 5 e "<<p.brojVozilaPoshirokiOd(5)<<endl;
Avtomobil a(1200,4,3,5);
cout<<"Brojot na kamioni so nosivost pogolema od avtomobilot e "<<p.pogolemaNosivostOd(a)<<endl;


}