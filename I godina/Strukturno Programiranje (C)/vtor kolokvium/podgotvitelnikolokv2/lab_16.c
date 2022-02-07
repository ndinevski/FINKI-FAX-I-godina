/*
Да се напише рекурзивна функција за наоѓање на максималната цифра од даден цел број.
Од стандарден влез се внесуваат непознат број цели броеви се додека не се внесе нешто што не е број.
За секој од нив да се испечати максималната цифра во посебен ред.
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int recursiveFunction(int n){
    if(n==0){
        return 0;
    }else{
        int broj=n%10;
        if(broj>recursiveFunction(n/10)){
            return broj;
        }else{
            return recursiveFunction(n/10);
        }
    }
}

int main(){
    int n;
    while(scanf("%d", &n)){
        printf("%d\n",recursiveFunction(n));
    }
    return 0;
}
