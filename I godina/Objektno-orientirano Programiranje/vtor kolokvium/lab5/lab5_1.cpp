//https://i.imgur.com/d4bT3wc.png

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

class Automobile{
    char * name;
    int * registration;
    int max;
    void copys(const Automobile & other){
        this->name=new char[strlen(other.name)+1];
        strcpy(this->name, other.name);
        this->registration=new int[5];
        copy(other.registration, other.registration + 5, this->registration);
        this->max=other.max;
    }
  public:
    Automobile(){
        this->registration= new int[5];
        this->max=0;
    }
    Automobile(char * name, int * registration, int max){
        this->name=new char[strlen(name)+1];
        strcpy(this->name, name);
        this->registration=new int[5];
        copy(registration, registration + 5, this->registration);
        this->max=max;
    }
    Automobile(const Automobile& other){
           copys(other);
    }
    Automobile & operator= (const Automobile & other){
        if(this!=&other){
            delete [] name;
            delete [] registration;
            copys(other);
        }
        return *this;
    }
    ~Automobile(){
        delete [] name;
        delete [] registration;
    }
    friend ostream &operator<<(ostream & out, const Automobile & a){
        out<<"Marka\t"<<a.name<<"\tRegistracija"<<"[ ";
        for(int i=0;i<5;i++){
            out<<a.registration[i]<<" ";
        }
        out<<"]"<<endl;
        return out;
    }
    bool operator==(const Automobile & other){
        for(int i=0;i<5;i++){
            if(this->registration[i]!=other.registration[i]){
                return false;
            }
        }
        return true;
    }
    int getMax(){
        return max;
    }
};

class RentACar{
    char name[100];
    Automobile * automobiles;
    int n;
    void copys(const RentACar & o){
        strcpy(this->name, o.name);
        this->n=o.n;
        this->automobiles= new Automobile[this->n];
        copy(o.automobiles,o.automobiles+o.n, this->automobiles);
    }
    public:
        RentACar(char * name=""){
            strcpy(this->name, name);
            this->n=0;
            this->automobiles=0;
        }
        RentACar(const RentACar &other){
            copys(other);
        }
        RentACar & operator +=(const Automobile & nov){
            Automobile * tmp;
            tmp = new Automobile[n+1];
            copy(this->automobiles,this->automobiles+n,tmp);
            delete [] automobiles;
            tmp[n++]=nov;
            automobiles=tmp;
            return *this;
        }
        RentACar & operator -=(const Automobile & nov){
            int j=0,flag=0;
            for(int i=0;i<n;i++){
                if(automobiles[i]==nov){
                    flag=1;
                    continue;
                }
                automobiles[j++]=automobiles[i];
            }
            if(flag){}
            return *this;
        }
        void pecatiNadBrzina(int m){
            cout<<name<<endl;
            for(int i=0;i<n;i++){
                if(automobiles[i].getMax()>m){
                    cout<<automobiles[i];
                    return;
                }
            }
        }
};

int main()
{
   RentACar agencija("FINKI-Car");
   int n;
   cin>>n;
    
   for (int i=0;i<n;i++)
   {
    	char marka[100];
    	int regisracija[5];
    	int maximumBrzina;
    
       	cin>>marka;
    
       	for (int i=0;i<5;i++)
    		cin>>regisracija[i];
    
    	cin>>maximumBrzina;
    
       	Automobile nov=Automobile(marka,regisracija,maximumBrzina);
       
    	//dodavanje na avtomobil
       	agencija+=nov;   
       
   }
    //se cita grehsniot avtmobil, za koj shto avtmobilot so ista registracija treba da se izbrishe
    char marka[100];
    int regisracija[5];
    int maximumBrzina;
    cin>>marka;
    for (int i=0;i<5;i++)
    cin>>regisracija[i];
    cin>>maximumBrzina;
    
    Automobile greshka=Automobile(marka,regisracija,maximumBrzina);
    
    //brishenje na avtomobil
    agencija-=greshka;
    
    agencija.pecatiNadBrzina(150);
    
    return 0;
}