//https://i.imgur.com/0BoOrHJ.png
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Pica{
    char name[15];
    int price;
    char * ingr;
    int discount;
    void copys(const Pica & p){
        strcpy(this->name,p.name);
        this->price=p.price;
        this->ingr=new char[strlen(p.ingr)+1];
        strcpy(this->ingr, p.ingr);
        this->discount=p.discount;
    }
public:
    Pica(char * name="", int price=0, char * ingr="", int discount=0 ){
        strcpy(this->name,name);
        this->price=price;
        this->ingr=new char[strlen(ingr)+1];
        strcpy(this->ingr, ingr);
        this->discount=discount;
    }
    Pica(const Pica & p){
        copys(p);
    }
    Pica & operator = (const Pica & p){
        if(&p!=this){
            delete [] ingr;
            copys(p);
        }
        return *this;
    }
    ~Pica(){
        delete [] ingr;
    }
    void pecati(){
        cout<<name<<" - "<<ingr<<", "<<price<<" "<<(0.01*(100-discount))*price<<endl;
    }
    bool istiSe(Pica p){
        return strcmp(this->ingr,p.ingr)==0;
    }
    int getDiscount(){
        return discount;
    }
};

class Picerija{
    char name[15];
    Pica * pici;
    int n;
    void copys(const Picerija & p ){
        strcpy(this->name, p.name);
        this->n=p.n;
        this->pici=new Pica[n];
        for(int i=0;i<n;i++){
            this->pici[i]=p.pici[i];
        }
    }
public:
    Picerija(char * name=nullptr){
        strcpy(this->name, name);
        this->n=0;
    }
    Picerija(const Picerija & p){
        copys(p);
    }
    Picerija & operator = (const Picerija & p){
        if(&p!=this){
            delete [] pici;
            copys(p);
        }
        return *this;
    }
    ~Picerija(){
        delete [] pici;
    }
    void dodadi(Pica p){
        for(int i=0;i<n;i++){
            if(this->pici[i].istiSe(p)){
                return;
            }
        }
        Pica * tmp;
        tmp = new Pica[n+1];
        copy(pici, pici + n, tmp);
        delete [] pici;
        this->pici = new Pica [n+1];
        tmp[n++]=p;
        pici=tmp;
    }
    void setIme(char * newname){
        strcpy(this->name, newname);
    }
    char * getIme(){
        return this->name;
    }
    void piciNaPromocija(){
        //име - состојки, цена, цена со попуст.
        for(int i=0;i<n;i++){
            if(pici[i].getDiscount()){
                pici[i].pecati();
            }
        }
    }


};



int main () {

    int n;
    char ime[15];
    cin >> ime;
    cin >> n;

    Picerija p1(ime);
    for(int i = 0; i < n; i++){
        char imp[100];
        cin.get();
        cin.getline(imp,100);
        int cena;
        cin >> cena;
        char sostojki[100];
        cin.get();
        cin.getline(sostojki,100);
        int popust;
        cin >> popust;
        Pica p(imp,cena,sostojki,popust);
        p1.dodadi(p);
    }

    Picerija p2 = p1;
    cin >> ime;
    p2.setIme(ime);
    char imp[100];
    cin.get();
    cin.getline(imp,100);
    int cena;
    cin >> cena;
    char sostojki[100];
    cin.get();
    cin.getline(sostojki,100);
    int popust;
    cin >> popust;
    Pica p(imp,cena,sostojki,popust);
    p2.dodadi(p);

    cout<<p1.getIme()<<endl;
    cout<<"Pici na promocija:"<<endl;
    p1.piciNaPromocija();

    cout<<p2.getIme()<<endl;
    cout<<"Pici na promocija:"<<endl;
    p2.piciNaPromocija();

	return 0;
}
