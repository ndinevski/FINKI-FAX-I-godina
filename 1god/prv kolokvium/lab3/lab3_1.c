/*
За даден број, проверете дали е 7-цифрен и ако е, испечате ги во посебен 
ред секој од неговите цифри почнувајќи од првата, а потоа повторно во посебен 
ред нивната сума и производ.

Ако бројот не е 7 цифрен само испечатете "Vneseniot broj ne e 7 cifren!".
*/
#include <stdio.h>
#include <math.h>

int main(){
    int a,b, product=1, sum=0;
    scanf("%d", &a);
    if((a/1000000)!=0 && (a/1000000)<=9){
        for(int i=6;i>=0;i--){
            b = a / pow(10,i);
            printf("%d\n", b%10);
            sum+=b%10;
            product*=b%10;
        }
        printf("%d\n%d", sum, product);
    }else{
        printf("Vneseniot broj ne e 7 cifren!");
    }
    return 0;
}

