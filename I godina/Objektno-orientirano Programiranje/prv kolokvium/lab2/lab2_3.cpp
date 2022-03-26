// Да се дефинира класа Film, во која ќе се чуваат информации за:
// име низа од 100 знаци
// режисер низа од 50 знаци
// жанр низа од 50 знаци
// година цел број
// Сите променливи треба да бидат приватни. Соодветно во рамките на класата да се дефинираат:
// default конструктор и конструктор со аргументи
// метод за печатење на информациите за филмот
// Дополнително да се реализира надворешна функција:
// void pecati_po_godina(Film *f, int n, int godina) која ќе прима аргумент низа од филмови, вкупниот број на филмови и година, 
//а треба да ги отпечати само филмовите кои се направени во дадената година.

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

#include <iostream>
#include <cstring>
using namespace std;

class Film{
private:
    char name[100];
    char prod[50];
    char type[50];
    int year;
public:
    Film(){}
    Film(char * n, char * p, char * t, int y){
        strcpy(name,n);
        strcpy(prod,p);
        strcpy(type,t);
        year=y;
    }
    void show(){
        cout<<"Ime: "<<name<<endl;
        cout<<"Reziser: "<<prod<<endl;
        cout<<"Zanr: "<<type<<endl;
        cout<<"Godina: "<<year<<endl;
    }
    int getYear(){
        return year;
    }
};

void pecati_po_godina(Film *f, int n, int godina){
    for(int i=0;i<n;i++){
        if(godina==f[i].getYear()){
            f[i].show();
        }
    }
}

int main() {
 	int n;
 	cin >> n;
 	//da se inicijalizira niza od objekti od klasata Film
    Film filmovi[50];
 	for(int i = 0; i < n; ++i) {
 		char ime[100];
 		char reziser[50];
 		char zanr[50];
 		int godina;
 		cin >> ime;
 		cin >> reziser;
 		cin >> zanr;
 		cin >> godina;
 		//da se kreira soodveten objekt
        filmovi[i]=Film(ime,reziser,zanr,godina);
 	}
 	int godina;
 	cin >> godina;
 	//da se povika funkcijata pecati_po_godina
    pecati_po_godina(filmovi, n, godina);
 	return 0;
 }