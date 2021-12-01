/*
Да се напише програма каде од тастатура се внесува еден седумцифрен број. 5689964
Програмата печати DA доколку бројот е специјален, а NE во спротивно. 
Еден број е специјален доколку за него важи дека е делив со својата прва 
цифра и не е делив со збирот на последните две или доколку не е делив со 
својата втора цифра и не е делив со збирот на последните две. Да се внимава 
на делење со 0, т.е. да се испечати порака Nevaliden broj во таков случај.
*/
#include <stdio.h>

int main(){
    int broj;
    scanf("%d", &broj);
    int cifri=((broj/10)%10+broj%10);
    if(cifri==0 || (broj/100000)%10==0){
        printf("Nevaliden broj");
    }else if(broj%cifri!=0){
        if(broj%(broj/1000000)==0){
            printf("DA");
        }else if(broj%((broj/100000)%10)!=0){
            printf("DA");
        }else{
            printf("NE");
        }
    }else{
        printf("NE");
    }
    return 0;
}
