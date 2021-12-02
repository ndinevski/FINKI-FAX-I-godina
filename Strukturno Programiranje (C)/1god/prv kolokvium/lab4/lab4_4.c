/*
Да се напише програма во која во даден опсег на природни броеви [a,b], 
ќе се најдат и отпечатат сите броеви чијшто збир на цифри кои се деливи со 2, 
но НЕ се деливи со 3, е поголем од 0 и е делив со 7. На крај да се отпечати и 
бројот на вакви броеви.
*/
#include <stdio.h>

int main(){
    int a,b,tmp,cnt=0;
    scanf("%d %d", &a, &b);
    for(int i=a;i<=b;i++){
        int sumDigits=0;
        tmp=i;
        while(tmp>0){
            if((tmp%10)%2==0&&(tmp%10)%3!=0){
                sumDigits+=tmp%10;
            }
            tmp/=10;
        }
        if(sumDigits>0 && sumDigits%7==0){
            printf("%d\n", i);
            cnt+=1;
        }
    }
    printf("Vkupno: %d", cnt);
    return 0;
}