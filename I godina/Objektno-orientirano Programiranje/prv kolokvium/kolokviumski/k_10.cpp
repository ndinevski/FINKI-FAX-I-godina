//https://i.imgur.com/my7umDu.png

#include <iostream>
#include <cstring>
using namespace std;

struct Igrac{
    char name[15];
    int level;
    int points;
};
typedef struct Igrac Igrac;

struct KompjuterskaIgra{
    char name[20];
    Igrac igraci[30];
    int n;
};
typedef struct KompjuterskaIgra KompjuterskaIgra;

void najdobarIgrac(KompjuterskaIgra * k, int n){
    int maxigraci=0;
    int maxpoints,maxi,maxj;
    for(int i=0;i<n;i++){
        if(k[i].n>maxigraci){
            maxigraci=k[i].n;
            maxi=i;
            maxpoints=0;
        for(int j=0;j<k[i].n;j++){
                if(k[i].igraci[j].points>maxpoints){
                    maxpoints=k[i].igraci[j].points;
                    maxj=j;
                }
                if(k[i].igraci[j].points==maxpoints && k[i].igraci[j].level>k[maxi].igraci[maxj].level){
                    maxpoints=k[i].igraci[j].points;
                    maxj=j;
                    maxi=i;
                }
            }
        }
    }
    cout<<"Najdobar igrac e igracot so korisnicko ime "<<k[maxi].igraci[maxj].name<<" koj ja igra igrata "<<k[maxi].name<<endl;
}

int main(){
    int n;
    cin>>n;
    KompjuterskaIgra igri[20];
    for(int i=0;i<n;i++){
        cin>>igri[i].name>>igri[i].n;
        for(int j=0;j<igri[i].n;j++){
            cin>>igri[i].igraci[j].name>>igri[i].igraci[j].level>>igri[i].igraci[j].points;
        }
    }
    najdobarIgrac(igri, n);
    return 0;
}
