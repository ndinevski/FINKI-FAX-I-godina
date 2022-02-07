/*
Од стандарден влез се внесуваат два цели броеви A и P.
Да се испечатат во опаѓачки редослед првите 5 броеви во интервалот 
(0,A] за коишто важи дека сумата на нивните цифри изнесува P проценти 
од самиот број.
Ако нема такви броеви во интервалот, да се испечати порака NEMA.
*/
#include <stdio.h>

int main(){
    int i,tmp,A,P,cnt=0;
    scanf("%d %d", &A, &P);
    for(i=A;i>=1;i--){
        tmp=i;
        int sumDigits=0;
        while(tmp>0){
            sumDigits+=tmp%10;
            tmp/=10;
        }
        if(((i/100.0)*P)==sumDigits){
            printf("%d\n",i);
            cnt++;
        }
        if(cnt==5){
            break;
        }   
    }
    if(cnt==0){
        printf("NEMA");
    }
    return 0;
}