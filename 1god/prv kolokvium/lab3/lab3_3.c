/*
Од тастатура се внесува четирицифрен број n што во себе содржи барем 2 цифри со вредност 5.
КОЛЕГА на тој број е бројот кој на позициите на кои има петки во првиот број ќе има шестка во
бројот КОЛЕГА. (Пр. колега на 5551 е 6661).
На екран да се испечати за колку проценти едниот број е поголем/помал од другиот број. Да се 
има во предвид дека некогаш може да биде поголем бројот n , а некогаш неговиот колега.
Доколку бројот n не содржи најмалку 2 цифри петки, да се испечати порака за грешка како во 
тест примерите.
*/
#include <stdio.h>
#include <math.h>

int main(){
    int broj, pocetenbroj, cifra, cifra2, kolega=0, cnt=0;
    float procent;
    scanf("%d", &broj);
    pocetenbroj=broj;
    for(int i=0;i<3;i+=2){
        cifra=broj%10;
        cifra2=(broj/10)%10;
        if(cifra==5 || cifra2==5){
            if(cifra2==5 && cifra==5){
                kolega+=(6*pow(10,i)+6*pow(10,i+1));
                cnt+=2;
            }else if(cifra2==5){
                kolega+=(cifra*pow(10,i) + 6*pow(10,i+1));
                cnt++;
            }else if(cifra==5){
                kolega+=(6*pow(10,i) + cifra2*pow(10,i+1));
                cnt++;
            }
        }else{
            kolega+=(cifra*pow(10,i) + cifra2*pow(10,i+1));
        }
        broj/=100;
    }
    if(cnt < 2){
        printf("Error");
    }else if(kolega > pocetenbroj){
        procent = ((kolega - pocetenbroj)/(float)pocetenbroj)*100;
        printf("%.4f%%", procent);
    }else if(pocetenbroj > kolega){
        procent = 100*((kolega - pocetenbroj)/(float)pocetenbroj);
        printf("%.4f%%", procent);
    }
    return 0;
}