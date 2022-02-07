/*
Да се напише програма која за петцифрен број прочитан од стандарден влез ќе проверува 
дали е палиндром. Ако бројот е палиндром, на екран треба да се испечати пораката 
"Palindrom", а во спротивно - "Ne e palindrom". Доколку внесениот број не е петцифрен 
треба да се испечати пораката "Nevaliden vlez".
*/
#include <stdio.h>

int main(){
    int number;
    scanf("%d", &number);
    if(number>9999&&number<=99999){
        if((number%10)==(number/10000)){
            if(((number/10)%10)==((number/1000)%10)){
                printf("Palindrom");
            }else{
                printf("Ne e palindrom");
            }
        }else{
            printf("Ne e palindrom");
        }
    }else{
        printf("Nevaliden vlez");
    }
    return 0;
}