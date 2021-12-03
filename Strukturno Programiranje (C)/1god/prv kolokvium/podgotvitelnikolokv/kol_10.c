/*
Цик-цак е број за кој што важи дека за секој пар соседни цифри, тие се наизменично поголеми односно помали една во 
однос на друга. На пример, ако бројот x е составен од цифрите a, b, c, d и е, тогаш за нив важи:
a>b, b<c, c>d, d<e или a<b, b>c, c<d, d>e
Пр. 343, 4624, 6231209
Од тастатура се читаат непознат број цели броеви поголеми од или еднакви на 10 (броевите помали од 10 се игнорираат). 
Читањето завршува во моментот кога ќе се прочита знак што не е цифра. Да се испечатат сите цик-цак броеви.
*/
#include <stdio.h>

int main(){
    int a;
    while(scanf("%d", &a)){
        if(a<10){
            continue;
        }
        int broj=a,cifra1,cifra2,checker=0,flag=1;
        if(a/100==0 && a%10!=(a/10)%10){
            printf("%d\n", a);
            continue;
        }
        while(broj>0){
            if((checker%10==1 && broj<cifra1)||(checker%10==0 && broj>cifra1 && broj<=9)){
                break;
            }else if((checker%10==1 && broj>=cifra1&&broj<=9)||(checker%10==0 && broj<=cifra1)){ 
                checker=0;
                break;
            }
            cifra1=broj%10;
            cifra2=(broj/10)%10;
            if(cifra1>cifra2){
                checker=checker*10+1;
            }else if(cifra1<cifra2){
                checker=checker*10+0;
            }else{
                checker=0;
                break;
            }
            broj/=10;
        }
        if(checker==0){
            continue;
        }
        while(checker>0){
            if(checker==1 && cifra1==0){
                break;
            }
            cifra1=checker%10;
            cifra2=(checker/10)%10;
            if(cifra1==cifra2){
                flag=0;
                break;
            }
            checker/=10;
        }
        if(flag==0){
            continue;
        }else{
            printf("%d\n",a);
        }
    }
    return 0;
}