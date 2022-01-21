#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int BrojPozitivni(int niza[], int n);
int BrojPozitivni(int *a, int n){
    int cnt=1;
    if(n==0){
        return 0;
    }else{
        if(a[n-1]>0){
            return cnt+BrojPozitivni(a,n-1); 
        }
        return BrojPozitivni(a,n-1);
    }
}

int main(){
    int n,i;
    scanf("%d", &n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    printf("%d", BrojPozitivni(a, n));
    return 0;
}