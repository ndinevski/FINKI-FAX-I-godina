//https://i.imgur.com/zrs9gGr.png

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Avtomobil{
    char boja[20];
    char brend[20];
    char model[20];
    void copy(const Avtomobil & a){
        strcpy(this->boja, a.boja);
        strcpy(this->brend, a.brend);
        strcpy(this->model, a.model);
    }
public:
    Avtomobil(char * boja="", char * brend="", char * model=""){
        strcpy(this->boja, boja);
        strcpy(this->brend, brend);
        strcpy(this->model, model);
    }
    Avtomobil(const Avtomobil & a){
        copy(a);
    }
    Avtomobil & operator = (const Avtomobil & a){
        if(&a!=this){
            char boja='\0';
            char brend='\0';
            char model='\0';
            copy(a);
        }
        return *this;
    }
    ~Avtomobil(){}
    char * getboja(){
        return this->boja;
    }
    char * getbrend(){
        return this->brend;
    }
    char * getmodel(){
        return this->model;
    }
};




class ParkingPlac{
    char adress[20];
    char * id;
    int pph;
    int profit;
    Avtomobil * arr;
    int brojvozila;
    void copys(const ParkingPlac & p){
        strcpy(this->adress,p.adress);
        this->id=new char[strlen(p.id)+1];
        strcpy(this->id, p.id);
        this->pph=p.pph;
        this->profit=p.profit;
        this->brojvozila=p.brojvozila;
    }
public:
    ParkingPlac(char * adress="", char * id="", int pph=0){
        strcpy(this->adress,adress);
        this->id=new char[strlen(id)+1];
        strcpy(this->id, id);
        this->pph=pph;
        this->profit=0;
        this->brojvozila=0;
    }
    ParkingPlac(const ParkingPlac & p){
        copys(p);
    }
    ParkingPlac & operator = (const ParkingPlac & p){
        if(&p!=this){
            delete [] id;
            copys(p);
        }
        return *this;
    }
    ~ParkingPlac(){
        delete [] id;
    }
    void pecati(){
        if(profit==0){
            cout<<id<<" "<<adress<<endl;
        }else{
            cout<<id<<" "<<adress<<" - "<<profit<<" denari"<<endl;
        }
    }
    void platiCasovi(int casovi){
        this->profit+=(this->pph * casovi);
    }
    bool daliIstaAdresa(const ParkingPlac &p){
        if(strcmp(this->adress, p.adress)==0){
            return true;
        }
        return false;
    }
    char * getId(){
        return this->id;
    }
    void parkirajVozilo(Avtomobil novoVozilo){
        Avtomobil *tmp = new Avtomobil [brojvozila+1];
        copy(arr,arr+brojvozila, tmp);
        delete [] arr;
        this->arr=new Avtomobil[brojvozila+1];
        tmp[brojvozila++]=novoVozilo;
        arr=tmp;
    }
    void pecatiParkiraniVozila(){
        cout<<"Vo parkingot se parkirani slednite vozila: "<<endl;
        for(int i=0;i<brojvozila;i++){
            cout<<i+1<<"."<<arr[i].getboja()<<" "<<arr[i].getbrend()<<" "<<arr[i].getmodel()<<endl;
        }
    }
};







int main(){

	ParkingPlac p[100];
	int n,m;
	char adresa[50],id[50];
	int brojcasovi,cenacas;
	cin>>n;
	if(n > 0){


		for (int i=0;i<n;i++){
	        cin.get();
			cin.getline(adresa,50);
			cin>>id>>cenacas;
			
			ParkingPlac edna(adresa,id,cenacas);
	        
	        p[i]=edna;
		}
	    
		//plakjanje
		cin>>m;
		for (int i=0;i<m;i++){

			cin>>id>>brojcasovi;
	        
	        int findId=false;
	        for (int j=0;j<m;j++){
	            if (strcmp(p[j].getId(),id)==0){
	                p[j].platiCasovi(brojcasovi);
	                findId=true;
	            }
	        }
			if (!findId)
	        cout<<"Ne e platen parking. Greshen ID."<<endl;
		}

	    cout<<"========="<<endl;
	    ParkingPlac pCentar("Cvetan Dimov","C10",80);
		for (int i=0;i<n;i++)
	        if (p[i].daliIstaAdresa(pCentar))
	            p[i].pecati();
	} else {

		ParkingPlac najdobarPlac("Mars", "1337", 1);
	    int brVozila;
	    cin >> brVozila;
	    for(int i = 0; i < brVozila; ++i){

	    	char boja[20];
	    	char brend[20];
	    	char model[20];

	    	cin >> boja >> brend >> model;
	    	Avtomobil novAvtomobil(boja, brend, model);
	    	najdobarPlac.parkirajVozilo(novAvtomobil);
	    }
	    if(brVozila != 0)
	    najdobarPlac.pecatiParkiraniVozila();

	}  
}