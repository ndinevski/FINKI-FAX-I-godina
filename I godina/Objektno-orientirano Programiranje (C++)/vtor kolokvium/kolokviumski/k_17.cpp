//https://i.imgur.com/5RmW32X.png

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

class FudbalskaEkipa{
    protected:
        char trener[100];
        int golovi[10];
    public:
        FudbalskaEkipa(const char * trener="", int * golovi=nullptr){
            strcpy(this->trener, trener);
            copy(golovi, golovi + 10, this->golovi);
        }
        virtual int uspeh() = 0;
        virtual char * getchar() = 0;
        
        
        FudbalskaEkipa & operator +=(int gola){
            int novigolovi[11];
            copy(golovi, golovi +10, novigolovi);
            novigolovi[10] = gola;
            for(int i = 0; i < 10; i++){
                golovi[i]=novigolovi[i+1];
            }
            return *this;
        }
        friend ostream & operator<<(ostream & o, FudbalskaEkipa & f){
            o<<f.getchar()<<endl<<f.trener<<endl<<f.uspeh()<<endl;
            return o;
        }
       

};

class Klub: public FudbalskaEkipa{
    protected:
        char ime[100];
        int tituli;
    public: 
        Klub(const char * trener="" , int *golovi=nullptr, const char * ime="", int tituli=0): FudbalskaEkipa(trener, golovi){
            strcpy(this->ime, ime);
            this->tituli = tituli;
        }
        
        int uspeh(){
            int sumgola=0;
            for(int i=0; i< 10; i++){
                sumgola+=golovi[i];
            }
            return sumgola*3 + tituli*1000;

        }
        char * getchar(){
            return ime;
        }
        friend ostream & operator<<(ostream & o, Klub & f){
            o<<f.getchar()<<endl<<f.trener<<endl<<f.uspeh()<<endl;
            return o;
        }

};

class Reprezentacija: public FudbalskaEkipa{
    protected:
        char drzava[100];
        int nastapi;
    public:
        Reprezentacija(const char * trener="", int *golovi=nullptr, const char * drzava="", int nastapi=0): FudbalskaEkipa(trener, golovi){
            strcpy(this->drzava, drzava);
            this->nastapi = nastapi;
        }
        
        int uspeh(){
            int sumgola=0;
            for(int i=0; i< 10; i++){
                sumgola+=golovi[i];
            }
            return sumgola*3 + nastapi*50;

        }
        char * getchar(){
            return drzava;
        }
        friend ostream & operator<<(ostream & o, Reprezentacija & f){
            o<<f.getchar()<<endl<<f.trener<<endl<<f.uspeh()<<endl;
            return o;
        }

};

 bool operator > (FudbalskaEkipa & a, FudbalskaEkipa & b){
            if(a.uspeh()>b.uspeh()){
                return true;
            }
            return false;
    }

void najdobarTrener(FudbalskaEkipa ** niza, int n){
    int max=0, indeks;
    for(int i=0;i<n;i++){
        if(niza[i]->uspeh()>max){
            max=niza[i]->uspeh();
            indeks=i;
        }
    }
    cout<<*niza[indeks]<<endl;
}




int main() {
    int n;
    cin >> n;
    FudbalskaEkipa **ekipi = new FudbalskaEkipa*[n];
    char coach[100];
    int goals[10];
    char x[100];
    int tg;
    for (int i = 0; i < n; ++i) {
        int type;
        cin >> type;
        cin.getline(coach, 100);
        cin.getline(coach, 100);
        for (int j = 0; j < 10; ++j) {
            cin >> goals[j];
        }
        cin.getline(x, 100);
        cin.getline(x, 100);
        cin >> tg;
        if (type == 0) {
            ekipi[i] = new Klub(coach, goals, x, tg);
        } else if (type == 1) {
            ekipi[i] = new Reprezentacija(coach, goals, x, tg);
        }
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *ekipi[i];
    }
    cout << "===== DODADI GOLOVI =====" << endl;
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        cout << "dodavam golovi: " << p << endl;
        *ekipi[i] += p;
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *ekipi[i];
    }
    cout << "===== NAJDOBAR TRENER =====" << endl;
    najdobarTrener(ekipi, n);
    for (int i = 0; i < n; ++i) {
        delete ekipi[i];
    }
    delete [] ekipi;
    return 0;
}