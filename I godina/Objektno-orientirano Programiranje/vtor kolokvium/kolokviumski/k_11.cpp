//https://i.imgur.com/mMEUp9H.png
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

//место за вашиот код
class Delo{
    protected:
        char ime[50];
        int god;
        char zemja[50];
        void cpys(const Delo & d){
            strcpy(this->ime,d.ime);
            this->god = d.god;
            strcpy(this->zemja,d.zemja);
        }
    public:
        Delo(const char * ime="", int god=0, const char * zemja=""){
            strcpy(this->ime,ime);
            this->god = god;
            strcpy(this->zemja,zemja);
        }
        Delo(const Delo & d){
            cpys(d);
        }
        Delo & operator =(const Delo & d){
            if(this!=&d){
                cpys(d);
            }
            return *this;
        }
        char * getIme(){
            return ime;
        }
        char* getZemja(){
            return zemja;

        }
        int getGod(){
            return god;
        }
        bool operator == (Delo & b){
            if(strcmp(this->ime, b.ime)==0){
                return true;
            }
            return false;
        }
};



class Pretstava{
    protected:
        Delo d;
        int karti;
        char data[15];
    public:
        Pretstava(Delo d, int karti, char * data){
            this->d = d;
            this->karti=karti;
            strcpy(this->data, data);
        }
        Delo getDelo(){
            return d;
        }
        int getKarti(){
            return karti;
        }
        char * getData(){
            return data;
        }
        virtual int cena(){
            int N,M;
            if(data[6]=='2' || data[7]=='9'){
                M=50;
            }else if(data[7]=='8'){
                M=75;
            }else{
                M=100;
            }
            if(!strcmp(d.getZemja(), "Italija")){
                N=125;
            }else if(!strcmp(d.getZemja(), "Rusija")){
                N=150;
            }else{
                N=130;
            }
            return N+M;
        }

};

class Balet: public Pretstava{
    protected:
        static int novacena;
    public:
        Balet(Delo d, int karti, char * data):Pretstava(d,karti,data){}
        static int getCenaBalet(){
            return Balet::novacena;
        }
        static void setCenaBalet(int a){
            Balet::novacena = a;
        }
        int cena(){
            return Pretstava::cena() + Balet::novacena;
        }


};

int Balet::novacena = 150;

class Opera: public Pretstava{  
    public:
        Opera(Delo d, int karti, char * data):Pretstava(d,karti,data){}
        int cena(){
            return Pretstava::cena();
        }
};  

int prihod(Pretstava ** niza, int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=(niza[i]->cena() * niza[i]->getKarti());
    }
    return sum;
}

int brojPretstaviNaDelo(Pretstava ** niza, int n, Delo & d){
    int cnt=0;
    for(int i=0;i<n;i++){
        if(niza[i]->getDelo() == d){
            cnt++;
        }
    }
    return cnt;
}

//citanje na delo
Delo readDelo(){
    char ime[50];
    int godina;
    char zemja[50];
    cin>>ime>>godina>>zemja;
    return Delo(ime,godina,zemja);
}


//citanje na pretstava
Pretstava* readPretstava(){
    int tip; //0 za Balet , 1 za Opera
    cin>>tip;
    Delo d=readDelo();
    int brojProdadeni;
    char data[15];
    cin>>brojProdadeni>>data;
    if (tip==0)  return new Balet(d,brojProdadeni,data);
    else return new Opera(d,brojProdadeni,data);
}

int main(){
    int test_case;
    cin>>test_case;
    
    switch(test_case){
    case 1:
    //Testiranje na klasite Opera i Balet
    {
        cout<<"======TEST CASE 1======="<<endl;
        Pretstava* p1=readPretstava();
        cout<<p1->getDelo().getIme()<<endl;
        Pretstava* p2=readPretstava();
        cout<<p2->getDelo().getIme()<<endl;
    }break;
        
    case 2:
    //Testiranje na  klasite Opera i Balet so cena
    {
        cout<<"======TEST CASE 2======="<<endl;
        Pretstava* p1=readPretstava();
        cout<<p1->cena()<<endl;
        Pretstava* p2=readPretstava();
        cout<<p2->cena()<<endl;
    }break;
    
    case 3:
    //Testiranje na operator ==
    {
        cout<<"======TEST CASE 3======="<<endl;
        Delo f1=readDelo();
        Delo f2=readDelo();
        Delo f3=readDelo();
        
        if (f1==f2) cout<<"Isti se"<<endl; else cout<<"Ne se isti"<<endl;
        if (f1==f3) cout<<"Isti se"<<endl; else cout<<"Ne se isti"<<endl;
    
    }break;
    
    case 4:
    //testiranje na funkcijata prihod
    {
        cout<<"======TEST CASE 4======="<<endl;
        int n;
        cin>>n;
        Pretstava **pole=new Pretstava*[n];
        for (int i=0;i<n;i++){
            pole[i]=readPretstava();
        
        }
        cout<<prihod(pole,n);
    }break;
    
    case 5:
    //testiranje na prihod so izmena na cena za 3d proekcii
    {
        cout<<"======TEST CASE 5======="<<endl;
        int cenaBalet;
        cin>>cenaBalet;
        Balet::setCenaBalet(cenaBalet);
        int n;
        cin>>n;
        Pretstava **pole=new Pretstava*[n];
        for (int i=0;i<n;i++){
            pole[i]=readPretstava();
        }
        cout<<prihod(pole,n);
        }break;
        
    case 6:
    //testiranje na brojPretstaviNaDelo
    {
        cout<<"======TEST CASE 6======="<<endl;
        int n;
        cin>>n;
        Pretstava **pole=new Pretstava*[n];
        for (int i=0;i<n;i++){
            pole[i]=readPretstava();
        }
        
        Delo f=readDelo();
        cout<<brojPretstaviNaDelo(pole,n,f);
    }break;
    
    };


return 0;
}
