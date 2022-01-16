/*
Од стандарден влез се чита цел број К, по што се читаат N цели броеви. Да се напише програма која за секој прочитан број на стандарден излез ќе ги отпечати неговите цифри кои се поголеми од К, 
како и збирот на цифрите кои се отпечатени. Печатењето на цифрите поголеми од K да се реализира со посебна рекурзивна функција.

Пример: Доколку К = 5, за бројот 8423871 треба да се отпечати 887 : 23
*/

#include <stdio.h>
#include <math.h>
#include <ctype.h>

int digitsBiggerThanK(int,int);
int sumOfDigits(int, int);

int sumOfDigits(int n,int K){
    int sum=0;
    if(n/10==0){
        return sum;
    }
    if(n%10>K){
        sum += n%10;
    }
    sumOfDigits(n/10, K);
}
int digitsBiggerThanK(int n, int K, int num){
    int static numm=num;
    if(n/10==0){
        return numm;
    }
    if(n%10>K){
        numm = numm*10 + n%10;
    }
    digitsBiggerThanK(n/10, K);
}

int main(){
    int N,K,n;
    scanf("%d %d", &K, &N);
    while(N>0){
        scanf("%d", &n);
        int reset=0;
        printf("%d : %d", digitsBiggerThanK(n, K, reset), sumOfDigits(n, K));
        N--;
    }
    return 0;
}