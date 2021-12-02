/*
Од стандарден влез се внесуваат два цели броеви A и P.
Да се испечатат во опаѓачки редослед првите 5 броеви во интервалот 
(0,A] за коишто важи дека сумата на нивните цифри изнесува P проценти 
од самиот број.
Ако нема такви броеви во интервалот, да се испечати порака NEMA.
*/
#include <stdio.h>

int main(){
    int i,tmp,A,P,cnt=0,sumDigits=0;
    scanf("%d %d", &A, &P);
    for(i=1;i<=A;i++){
        tmp=i;
        while(tmp>0){
            sumDigits+=tmp%10;
            tmp/=10;
        }
        printf("%d", sumDigits);
        if((i/100.0)*P==sumDigits){
            printf("%d",i);
            cnt+=1;
        }
        if(cnt==5){
            break;
        }
    }
    return 0;
}