/*
Од стандарден влез се читаат непознат број на хексадецимални цифри се додека не се внесе точка (.). 
Ваша задача е да го пресметате декадниот збир на внесените хексадецимални цифри. Доколку добиениот декаден 
збир е делив со 16 се печати Pogodok. Доколку истиот тој збир покрај што е делив со 16 плус завршува на 16 
(последните цифри му се 1 и 6), се печати Poln pogodok инаку се печати самиот збир.
Пример:
влез: A 7 F 2 0 c A 5
излез: 61
(61 = 10 + 7 + 15 + 2 + 0 + 12 + 10 + 5, бројот не е делив со 16, ниту пак последните цифри му се 1,6)
*/
#include <stdio.h>
#include <ctype.h>

int main(){
    char a=0;
    int sum=0;
    while(a!='.'){
        scanf("%c", &a);
        if(a=='.'){
            break;
        }
        if(isdigit(a)){
            sum+=(a-'0');
        }else{
        switch(a){
            case 'A':
            case 'a':
                sum+=10;
                break;
            case 'B':
            case 'b':
                sum+=11;
                break;
            case 'C':
            case 'c':
                sum+=12;
                break;
            case 'D':
            case 'd':
                sum+=13;
                break;
            case 'E':
            case 'e':
                sum+=14;
                break;
            case 'F':
            case 'f':
                sum+=15;
                break;
        }
        }
    }
    if(sum%16==0){
        if(sum%100==16){
            printf("Poln pogodok");
        }else{
            printf("Pogodok");
        }
    }else{
        printf("%d", sum);
    }
    return 0;
}