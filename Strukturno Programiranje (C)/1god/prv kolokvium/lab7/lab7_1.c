/*
СО Функција:
За дадена низа од N големина, исчитајте ја истата и потоа:
Испечатете ја во нејзината оригинална форма
Сменете го распоредот на низата во обратна насока
Отстранете го секој втор член
Повторно сменете го распоредот на низата во обратна насока
За секоја од овие промени испечатете ја низата. За целосни поени работете само со една низа.
*/
#include <stdio.h>

void printArray(int array[],int N){
    for(int i=0;i<N;i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}
void flipArray(int array[],int N){
    for(int i=0;i<N/2;i++){
        int tmp=array[i];
        array[i]=array[N-i-1];
        array[N-i-1]=tmp;
    }
    printArray(array, N);
}
int main(){
    int N,c=0;
    scanf("%d", &N);
    int a[100],A[100];
    for(int i=0;i<N;i++){
        scanf("%d", &a[i]);
    }
    printArray(a, N);
    flipArray(a, N);
    for(int i=0;i<N;i+=2){
        A[c]=a[i];
        c++;
    }
    printArray(A, c);
    flipArray(A, c);
    return 0;
}
