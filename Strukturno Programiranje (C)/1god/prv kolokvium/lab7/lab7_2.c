/*
Да се имплементира функција elka(int n) што на стандарден излез ќе печати новогодишна елка од ѕвезди. 
n означува колку ѕведички има основата на елката и во сите тест примери n е непарен број.
*/
#include <stdio.h>

void elka(int n){
    int i=n/2, c=1;
    for(int j=0;j<(n/2)+1;j++){
        for(int tmpi=i;tmpi>0;tmpi--){
            printf(" ");
        }
        for(int tmpc=c;tmpc>0;tmpc--){
            printf("*");
        }
        printf("\n");
        i--;
        c+=2;
    }
}
int main(){
    int N;
    scanf("%d", &N);
    elka(N);
    return 0;
}
