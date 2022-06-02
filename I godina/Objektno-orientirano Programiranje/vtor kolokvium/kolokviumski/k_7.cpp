//https://i.imgur.com/bHVHZE3.png

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;


class OutOfBoundsException{
    public:
        OutOfBoundsException(){}
        void message(){
            cout<<"Brojot na pin kodovi ne moze da go nadmine dozvolenoto"<<endl;
        }
};

class Karticka{
   protected:
       char smetka[16];
       int pin;
       bool povekjePin;
   public:
    Karticka(const char* smetka="",int pin=0){
       strcpy(this->smetka,smetka);
       this->pin=pin;
       this->povekjePin=false;
     }
     // дополниете ја класата
     virtual int tezina(){
        int n=pin,cnt=0;
        while(n!=0){
            n/=10;
            cnt++;
        }
        return cnt;
     }
    //  bool mozeDaSeProbie(){
    //      if(tezina()<=7){
    //          return true;
    //      }
    //      return false;
    // }
    char * getSmetka(){
        return smetka;
    }
    bool getDopolnitelenPin(){
        return povekjePin;
    }
    int getM(){ 
        return 0;
    }

    friend ostream & operator <<( ostream & o , Karticka & k){
        return o<<k.smetka<<": "<<k.tezina()<<endl;
    }

};

class SpecijalnaKarticka: public Karticka{
    protected:
        int * niza;
        int m;
        static int P;
        void cpys(const SpecijalnaKarticka& o){
            this->m=o.m;
            copy(o.niza, o.niza + o.m, this->niza);
        }
    public:
        SpecijalnaKarticka(const char* smetka="",int pin=0):Karticka(smetka, pin){
            povekjePin = true;
            m=0;
            niza = new int[m];
        }  
        
        SpecijalnaKarticka & operator += (int pin){
            if(m>=P){
                throw OutOfBoundsException();
            }

            int * tmp = new int[m+1];
            copy(niza, niza+m, tmp);
            delete [] niza;
            tmp[m++] = pin;
            niza = tmp;
            return *this;
        }
        
        int tezina(){
            return Karticka::tezina() + m;
        }
        // bool mozeDaSeProbie(){
        //     if(tezina() <= 7){
        //         return true;
        //     }
        //     return false;
        // }
        // char * getSmetka(){
        //     return smetka;
        // }
        // bool getDopolnitelenPin(){
        //     return povekjePin;
        // }
        // int getM(){
        //     return m;
        // }

        // friend ostream & operator <<( ostream & o , SpecijalnaKarticka & k){
        // return o<<k.smetka<<": "<<k.tezina()<<endl;
        // }
        ~SpecijalnaKarticka(){
            delete [] niza;
        }
    

};
int SpecijalnaKarticka::P=4;

//вметнете го кодот за SpecijalnaKarticka 



class Banka {
private:
    char naziv[30];
    Karticka *karticki[20];
    int broj;
    static int LIMIT;
public:
    Banka(char *naziv, Karticka** karticki,int broj ){
      strcpy(this->naziv,naziv);
      for (int i=0;i<broj;i++){
        //ako kartickata ima dopolnitelni pin kodovi
        if (karticki[i]->getDopolnitelenPin()){
            this->karticki[i]=new SpecijalnaKarticka(*dynamic_cast<SpecijalnaKarticka*>(karticki[i]));
        }
        else this->karticki[i]=new Karticka(*karticki[i]);
      }
      this->broj=broj;
    }
    ~Banka(){
    for (int i=0;i<broj;i++) delete karticki[i];
    }
    static void setLimit(int a){
        Banka::LIMIT = a;
    }

    static int getLimit(){
        return Banka::LIMIT;
    }

    //да се дополни класата
    void pecatiKarticki(){
        cout<<"Vo bankata "<<naziv<<" moze da se probijat kartickite: "<<endl;
        for(int i=0;i<broj;i++){
            if(karticki[i]->tezina()<=Banka::LIMIT){
                cout<<*karticki[i];
            }
        }
    }


    void dodadiDopolnitelenPin(char * smetka, int novPin){
        for(int i=0;i<broj;i++){
            if(strcmp(karticki[i]->getSmetka(), smetka)==0){
                SpecijalnaKarticka * casted= dynamic_cast<SpecijalnaKarticka *>(karticki[i]);
                if(casted){
                    try{
                        *casted+=novPin;
                    }catch(OutOfBoundsException e){
                        e.message();
                    }
                }
            }
            
        }
    }
};

int Banka::LIMIT = 7;




int main(){

Karticka **niza;
int n,m,pin;
char smetka[16];
bool daliDopolnitelniPin;
cin>>n;
niza=new Karticka*[n];
for (int i=0;i<n;i++){
   cin>>smetka;
   cin>>pin;
   cin>>daliDopolnitelniPin;
   if (!daliDopolnitelniPin)
    niza[i]=new Karticka(smetka,pin);
   else
    niza[i]=new SpecijalnaKarticka(smetka,pin);
}

Banka komercijalna("Komercijalna",niza,n);
for (int i=0;i<n;i++) delete niza[i];
delete [] niza;
cin>>m;
for (int i=0;i<m;i++){
   cin>>smetka>>pin;
   try{
   komercijalna.dodadiDopolnitelenPin(smetka,pin);
   }
   catch(OutOfBoundsException & e){
       e.message();
   }
}

Banka::setLimit(5);

komercijalna.pecatiKarticki();
return 0;

}
