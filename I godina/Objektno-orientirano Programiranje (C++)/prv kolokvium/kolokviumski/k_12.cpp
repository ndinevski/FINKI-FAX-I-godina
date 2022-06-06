//https://i.imgur.com/F3Yukuz.png

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Pica{
    char name[15];
    int price;
    char * ingr;
    int discount;
    void cpy(const Pica & p){
        strcpy(this->name,p.name);
        this->price=p.price;
        this->ingr = new char[strlen(p.ingr)+1];
        strcpy(this->ingr, p.ingr);
        this->discount=p.discount;
    }
public:
    Pica(char * name="", int price=0, char * ingr="", int discount=0){
        strcpy(this->name,name);
        this->price=price;
        this->ingr = new char[strlen(ingr)+1];
        strcpy(this->ingr, ingr);
        this->discount=discount;
    }
    Pica(const Pica & p){
        cpy(p);
    }
    Pica & operator = (const Pica & p){
        if(&p!=this){
            delete [] ingr;
            cpy(p);
        }
    }
    ~Pica(){
        delete [] ingr;
    }
    void pecati(){
        cout<<name<<" - "<<ingr<<", "<<price<<" "<<price - price*discount/100<<endl;
    }
    int istiSe(Pica p){
        if(strcmp(this->ingr, p.ingr)==0){
            return 1;
        }
        return 0;
    }
    int getDiscount(){
        return discount;
    }
};

class Picerija{
    char name[15];
    Pica *pici;
    int n;
    void cpy(const Picerija & p){
        strcpy(this->name,p.name);
        this->n=p.n;
        this->pici=new Pica[this->n];
        for(int i=0;i<this->n;i++){
            this->pici[i]=p.pici[i];
        }
    }
public:
    Picerija(char * name=""){
        strcpy(this->name,name);
        this->pici=nullptr;
        this->n=0;
    }
    Picerija(const Picerija & p){
        cpy(p);
    }
    Picerija & operator = (const Picerija & p){
        if(&p!=this){
            delete [] pici;
            cpy(p);
        }
        return *this;
    }
    ~Picerija(){
        delete [] pici;
    }
    void dodadi(Pica p){
        for(int i=0;i<n;i++){
            if(pici[i].istiSe(p)){
                return;
            }
        }
        Pica * tmp;
        tmp=new Pica[n+1];
        copy(pici,pici+n,tmp);
        tmp[n++]=p;
        delete [] pici;
        pici=tmp;
    }
    void piciNaPromocija(){
        for(int i=0;i<n;i++){
            if(pici[i].getDiscount()){
                pici[i].pecati();
            }
        }
    }
    void setIme(char * ime){
        strcpy(this->name,ime);
    }
    char * getIme(){
        return this->name;
    }
};

int main() {

	int n;
	char ime[15];
	cin >> ime;
	cin >> n;

	Picerija p1(ime);
	for (int i = 0; i < n; i++){
		char imp[100];
		cin.get();
		cin.getline(imp, 100);
		int cena;
		cin >> cena;
		char sostojki[100];
		cin.get();
		cin.getline(sostojki, 100);
		int popust;
		cin >> popust;
		Pica p(imp, cena, sostojki, popust);
		p1.dodadi(p);
	}

	Picerija p2 = p1;
	cin >> ime;
	p2.setIme(ime);
	char imp[100];
	cin.get();
	cin.getline(imp, 100);
	int cena;
	cin >> cena;
	char sostojki[100];
	cin.get();
	cin.getline(sostojki, 100);
	int popust;
	cin >> popust;
	Pica p(imp, cena, sostojki, popust);
	p2.dodadi(p);

	cout << p1.getIme() << endl;
	cout << "Pici na promocija:" << endl;
	p1.piciNaPromocija();

	cout << p2.getIme() << endl;
	cout << "Pici na promocija:" << endl;
	p2.piciNaPromocija();

	return 0;
}

