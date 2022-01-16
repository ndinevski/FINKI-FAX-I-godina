/*
Да се напишат следните функции за работа со низи од децимални броеви:

Функцијата double max (double * niza, int n), што како резултат ќе го врати максимумот во низата niza со n елементи.
Функцијата double min (double * niza, int n), што како резултат ќе го врати минимумот во низата niza со n елементи.
Функцијата void normalize (double * niza, int n), што ќе го нормализира секој елемент од низата по следната формула:

x = (x-min(niza)) / (max(niza) - min(niza))

Функција void sort (double * niza, int n) што ќе ја сортира низата во опаѓачки редослед!

Да не се менува main функцијата и да не се користи операторот за пристап до елемент на низа [ ]!
*/
#include<stdio.h>

double max (double * niza, int n){
    double maks=0;
    for(int i=0;i<n;i++){
        if(niza[i]>maks){
            maks=niza[i];
        }
    }
    return maks;
}

double  min (double * niza, int n){
    double mini=1000000;
    for(int i=0;i<n;i++){
        if(niza[i]<mini){
            mini=niza[i];
        }
    }
    return mini;
}

void normalize(double *niza, int n){
    double m1=min(niza,n), m2=max(niza,n);
    for(int i=0;i<n;i++){
        double x=niza[i];
        x = (x-m1) / (m2 - m1);
        niza[i]=x;
    }
}

void sort(double * niza, int n){
    double tmp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(niza[j]<niza[j+1]){
                tmp=niza[j];
                niza[j]=niza[j+1];
                niza[j+1]=tmp;
            }
        }
    }
}

int main () {
    
    double niza [200];
    int i,n;
    
    scanf("%d", &n);
    
    for (i=0;i<n;i++) {
        scanf("%lf", &niza[i]);
        
    }
    
    printf("MAX -> %.3lf\n", max(niza,n));
    printf("MIN -> %.3lf\n", min(niza,n));
    
    normalize(niza,n);
    sort(niza,n);
    
     for (i=0;i<n;i++) {
        printf("%.3lf ", niza[i]);
        
    }
    
    return 0;

}