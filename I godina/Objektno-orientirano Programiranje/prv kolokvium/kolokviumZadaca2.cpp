#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Flight{
    char gradPolet[50];
    char gradSlet[50];
    float traenje;
    float cena;
    void cpy(const Flight & f){
        strcpy(this->gradPolet, f.gradPolet);
        strcpy(this->gradSlet, f.gradSlet);
        this->traenje=f.traenje;
        this->cena = f.cena;
    }
public:
    Flight(char * gradPolet="", char * gradSlet="", float traenje=0, float cena=0){
        strcpy(this->gradPolet, gradPolet);
        strcpy(this->gradSlet, gradSlet);
        this->traenje=traenje;
        this->cena = cena;
    }
    Flight(const Flight & f){
        cpy(f);
    }
    Flight & operator = (const Flight & f){
        cpy(f);
        return *this;
    }
    ~Flight(){}
    void printDuration(){
        int hours;
        float minutes;
        hours=(int)traenje;
        minutes=(traenje-hours);
        cout<<hours<<"h:"<<60.0*minutes<<"min";
    }
    //град на полетување -> времетраење на лет -> град на слетување: цена
    void printFlight(){//pecati
        cout<<getDepartureCity()<<" -> ";
        printDuration();
        cout<<" -> "<<getArrivalCity()<<": "<<cena<<"EUR";
    }
    char * getDepartureCity(){//zemi polet
        return gradPolet;
    }
    char * getArrivalCity(){//zemi slet
        return gradSlet;
    }
};

class Airline{
    char ime[50];
    Flight * letovi;
    int n;
    void cpy(const Airline & a){
        strcpy(this->ime, a.ime);
        this->n=a.n;
        this->letovi=new Flight[a.n];
        copy(a.letovi, a.letovi + a.n, this->letovi);
    }
public:
    Airline(char * ime=""){
        strcpy(this->ime, ime);
        this->n=0;
        this->letovi=nullptr;
    }
    Airline(const Airline & a){
        cpy(a);
    }
    Airline & operator = (const Airline & a){
        if(&a!=this){
            delete [] letovi;
            cpy(a);
        }
        return *this;
    }
    ~Airline(){
        delete [] letovi;
    }
    void addFlight(Flight f){//dodadavanje let
        for(int i=0;i<n;i++){//ako postoi let izlezi
            if(strcmp(this->letovi[i].getDepartureCity(), f.getDepartureCity())==0 && strcmp(this->letovi[i].getArrivalCity(), f.getArrivalCity())==0){
                return;
            }
        }
        Flight * tmp;//dodavanje let
        tmp = new Flight[n+1];
        copy(letovi, letovi + n, tmp);
        delete [] letovi;
        letovi = new Flight[n+1];
        tmp[n++]=f;
        letovi=tmp;
    }
    int getN(){//zemi broj letovi
        return n;
    }
    Flight getFlights(int i){//zemi letovi
        return letovi[i];
    }

};

void searchFlights(Airline a, char departureCity[], char arrivalCity[]){//baranje letovi
    for(int i=0;i<a.getN();i++){//direkten let
        if(strcmp(a.getFlights(i).getDepartureCity(), departureCity)==0 && strcmp(a.getFlights(i).getArrivalCity(), arrivalCity)==0){
            a.getFlights(i).printFlight();
            return;
        }
    }
    int flag=0;
    for(int i=0;i<a.getN();i++){//preku eden let
        if(strcmp(a.getFlights(i).getDepartureCity(), departureCity)==0){
            for(int j=0;j<a.getN();j++){
                if(strcmp(a.getFlights(i).getArrivalCity(),a.getFlights(j).getDepartureCity())==0 && strcmp(a.getFlights(j).getArrivalCity(), arrivalCity)==0){
                    a.getFlights(i).printFlight();
                    cout<<" 1 stop ";
                    a.getFlights(j).printFlight();
                    cout<<endl;
                    flag=1;
                }
            }
        }
    }
    if(flag){//ako postoi preku eden let
        return;
    }
    cout<<"Nema konekcija pomegju baranite gradovi"<<endl;

}



int main(){

    int testCase;
    cin >> testCase;

    if(testCase == 1){
        cout << "====Testing class Flight constructors and additional methods====" << endl;
        Flight f1;
        char dep[50], arr[50];
        float dur, pr;
        cin >> dep >> arr >> dur >> pr;
        Flight f2(dep, arr, dur, pr);
        cout << f2.getDepartureCity() << " " << f2.getArrivalCity() << endl;
        cout << "Testing OK" << endl;
    }
    else if(testCase == 2){
        cout << "====Testing class Flight methods printDuration() and printFlight()====" << endl;
        char dep[50], arr[50];
        float dur, pr;
        cin >> dep >> arr >> dur >> pr;
        Flight f2(dep, arr, dur, pr);
        f2.printFlight();
        cout << endl;
    }
    else if(testCase == 3){
        cout << "====Testing class Airplane constructors and methods====" << endl;
        Airline a("Wizzair");
        char dep[50], arr[50];
        float dur, pr;
        cin >> dep >> arr >> dur >> pr;
        Flight f1(dep, arr, dur, pr);
        a.addFlight(f1);
        Flight f3 = f1;
        a.addFlight(f3);
        a.getFlights(0).printFlight();
        cout << endl;
        cout << a.getN() << endl;
        Airline b = a;
        b.getFlights(0).printFlight();
        cout << endl;
        cin >> dep >> arr >> dur >> pr;
        Flight f2(dep, arr, dur, pr);
        b.addFlight(f2);
        b.getFlights(1).printFlight();
        cout << endl;
        cout << "Testing OK" << endl;
    }
    else if(testCase == 4){
        cout << "====Testing global function====" << endl;
        Airline a("Wizzair");
        char dep[50], arr[50];
        float dur, pr;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> dep >> arr >> dur >> pr;
            Flight f(dep, arr, dur, pr);
            a.addFlight(f);
        }
        cin >> dep >> arr;
        searchFlights(a, dep, arr);
        cout << endl << "Testing OK" << endl;
    }

    return 0;
}
