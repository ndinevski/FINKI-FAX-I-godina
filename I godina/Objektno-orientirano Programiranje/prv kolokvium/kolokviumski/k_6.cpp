//https://i.imgur.com/ZIxRz3m.png

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

struct Train{
    char pateka[50];
    float km;
    int patnici;
};
typedef struct Train Train;

struct ZeleznickaStanica{
    char city[20];
    Train vozovi[30];
    int n;
};
typedef struct ZeleznickaStanica ZeleznickaStanica;

void najkratkaRelacija(ZeleznickaStanica* zs, int n, char* grad){
    char maxi[50];
    int max;
    for(int i=0;i<n;i++){
        if(strcmp(grad,zs[i].city)==0){
            max=500;
            for(int j=0;j<zs[i].n;j++){
                if(zs[i].vozovi[j].km<=max){
                    max=zs[i].vozovi[j].km;
                    strcpy(maxi, zs[i].vozovi[j].pateka);
                }
            }
        }
    }
    cout<<"Najkratka relacija: "<<maxi<<" ("<<max<<" km)"<<endl;
}

int main(){
	
    int n;
	cin>>n; //se cita brojot na zelezlnichki stanici

    ZeleznickaStanica zStanica[100];
    for (int i=0;i<n;i++){
        char pateka[50];
        float km;
        int patnici;
        cin>>zStanica[i].city;
        cin>>zStanica[i].n;
        for(int j=0;j<zStanica[i].n;j++){
            cin>>zStanica[i].vozovi[j].pateka>>zStanica[i].vozovi[j].km>>zStanica[i].vozovi[j].patnici;
        }
        //se citaat infomracii za n zelezlnichkite stanici i se zacuvuvaat vo poleto zStanica
    }
    
    char grad[25];
    cin>>grad;

	najkratkaRelacija(zStanica,n,grad);
	return 0;
}
