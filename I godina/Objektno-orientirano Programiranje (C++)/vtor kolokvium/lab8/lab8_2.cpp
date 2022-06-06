//https://i.imgur.com/k4zQSEt.png

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

class Igrachka {
public:
    virtual float getVolumen() = 0;
    virtual float getMasa() = 0;
    virtual float getPlostina() = 0;
};

class Forma {
protected:
    char boja[100];
    int gustina;
public:
    Forma(char * boja="", int gustina=0){
        strcpy(this->boja, boja);
        this->gustina = gustina;
    }
};


class Topka : public Igrachka, public Forma {
    int radius;
    public:
        Topka(char * boja="", int gustina=0, int radius=0):Forma(boja, gustina){
            this->radius = radius;
        }
        // Topka(const Topka & other){
        //     strcpy(this->boja, other.boja);
        //     this->gustina = other.gustina;
        //     this->radius = other.radius;
        // }
        float getVolumen(){
            return radius*radius*radius*3.14*4/3;
        }
        float getMasa(){
            return getVolumen()*gustina;
        }
        float getPlostina(){
            return 4*3.14*radius*radius;
        }

};

class Kocka : public Igrachka, public Forma {
    int a;
    int b;
    int c;
    public:
        Kocka(char * boja="", int gustina=0, int a=0, int b=0, int c=0):Forma(boja,gustina){
            this->a = a;
            this->b=b;
            this->c=c;
        }
        // Kocka(const Kocka & other) : Forma(other){
        //     this->a = other.a;
        //     this->b = other.b;
        //     this->c = other.c;
        // }
        float getVolumen(){
            return a*b*c;
        }
        float getMasa(){
            return getVolumen()*gustina;
        }
        float getPlostina(){
            return 2.0*(a*b + b*c + a*c);
        }

};
void baranja(Kocka & petra, Igrachka ** kupche, int n){
    int vk=0;
    float maxvol=0,minplos=100000;
    for(int i=0;i<n;i++){
        vk+=kupche[i]->getMasa();
        if(kupche[i]->getVolumen()>maxvol){
            maxvol=kupche[i]->getVolumen();
        }
        if(kupche[i]->getPlostina()<minplos){
            minplos=kupche[i]->getPlostina();
        }
    }
    if(vk>petra.getMasa()){
        cout<<"DA"<<endl;
    }else{
        cout<<"NE"<<endl;
    }
    cout<<"Razlikata e: "<<abs(maxvol-petra.getVolumen())<<endl;
    cout<<"Razlikata e: "<<abs(minplos - petra.getPlostina())<<endl;
}

int main(){

    int n;
    cin>>n;
	Igrachka ** kupche=new Igrachka * [n];

    for(int i=0; i<n; i++){
        int type;
        cin>>type;
        char boja[100];
        int gustina;
        int a,b,c,radius;
        cin>>boja>>gustina;
        if(type==1){
            cin>>radius;
            kupche[i] = new Topka(boja, gustina, radius);
        }else{
            cin>>a>>b>>c;
            kupche[i] = new Kocka(boja, gustina, a, b ,c);
        }
    }

    char boja[100];
    int gustina;
    int a,b,c;
    cin>>boja>>gustina>>a>>b>>c;
    Kocka petra(boja,gustina,a,b,c);
    
    baranja(petra, kupche, n);
	

	return 0;
}