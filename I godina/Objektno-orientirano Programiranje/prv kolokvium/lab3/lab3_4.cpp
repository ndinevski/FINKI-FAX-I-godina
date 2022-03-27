// Во оваа задача е потребно да уредите даден дом со маси. Креирајте класа Masa со следниве атрибути:
// должина (целобројна вредност)
// ширина (целобројна вредност)
// конструктор со и без параметри и метода pecati().
// Креирајте класа Soba која содржи:
// маса (објект од класата Маса)
// должина на собата (целобројна вредност)
// ширина на собата (целобројна вредност)
// конструктор со и без параметри и метода pecati() во која се повикува и pecati() за објектот Masa.
// Креирајте класа Kukja со атрибути:
// соба (објект од класата Soba)
// адреса (низа од 50 знаци), и соодветни методи.
// конструктор со и без параметри, деструктор и метода pecati() во која се повикува и pecati() за објектот Soba.

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

class Masa{
    int dolzina;
    int sirina;
public:
    Masa(){}
    Masa(int x,int y){
        dolzina=x;
        sirina=y;
    }
    Masa(const Masa &m){
        dolzina=m.dolzina;
        sirina=m.sirina;
    }
    ~Masa(){}
    void pecati(){
        cout<<"Masa: "<<dolzina<<" "<<sirina<<endl;
    }
};

class Soba{
    int dolzina;
    int sirina;
    Masa masa;
public:
    Soba(){}
        Soba(int x, int y,Masa m){
        masa=m;
        dolzina=x;
        sirina=y;
    }
    ~Soba(){}
    void pecati(){
        cout<<"Soba: "<< dolzina << " "<< sirina<<" ";
        masa.pecati();
    }
};

class Kukja{
    Soba soba;
    char a[50];
public:
    Kukja(){}
    Kukja(Soba s, char * _a){
        soba=s;
        strcpy(a,_a);
    }
    ~Kukja(){}
    void pecati(){
        cout<<"Adresa: "<<a<<" ";
        soba.pecati();
    }
};

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
    	int masaSirina,masaDolzina;
        cin>>masaSirina;
        cin>>masaDolzina;
    	Masa m(masaSirina,masaDolzina);
    	int sobaSirina,sobaDolzina;
        cin>>sobaSirina;
        cin>>sobaDolzina;
    	Soba s(sobaSirina,sobaDolzina,m);
    	char adresa[30];
        cin>>adresa;
    	Kukja k(s,adresa);
    	k.pecati();
	}
    
    return 0;
}