/*
Од тастатура во низа се внесуваат N позитивни цели броеви (N <= 100), а потоа се внесува и цел број ind (ind >= 0).
Да се напише функција sum_pos која ја прима низата, бројот ind (кој претставува индекс во низата) и бројот на валидни елементи во низата.
Функцијата треба да врати сумата на сите елементи почнувајќи од дадениот индекс ind па се до крајот на низата. Ако индексот ind е поголем од Nфункцијата треба да врати 0.
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int sum_pos(int *a,int N, int ind){
    int sum=0;
    if(ind>N){
        return sum;
    }
    for(int i=ind;i<N;i++){
        sum+=*(a+i);
    }
    return sum;
}

int main(){
    int i,N,a[100],ind;
    scanf("%d", &N);
    for(i=0;i<N;i++){
        scanf("%d",a+i);
    }
    scanf("%d", &ind);
    printf("%d", sum_pos(a, N, ind));
    return 0;
}