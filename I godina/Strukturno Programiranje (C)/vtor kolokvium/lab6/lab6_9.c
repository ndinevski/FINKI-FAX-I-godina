/*
За дадена низа со големина N, прочитајте ги сите елементи од дадениот влез, а потоа сортирајте ја низата. 
Испечатете ја во растечки редослед.
*/
#include <stdio.h>

int main(){
    int N,i,j,tmp;
    scanf("%d", &N);
    int a[N];
    for(i=0;i<N;i++){
        scanf("%d", &a[i]);
    }
    for(i=0;i<N;i++){
        for(j=0;j<N-1;j++){
            if(a[j]>a[j+1]){
                tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }
        }
    }
    for(i=0;i<N;i++){
        printf("%d ", a[i]);
    }
    return 0;
}