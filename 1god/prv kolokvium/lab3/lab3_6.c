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