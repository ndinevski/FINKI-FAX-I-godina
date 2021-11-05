#include <stdio.h>

int main(){
    int embg, den, mesec, godina, username;
    scanf("%d", &embg);
    den=embg/100000;
    mesec=(embg/1000)%100;
    godina=(embg%1000) + 1000;
    username=den*100+mesec*1000+godina;
    if((username/10000)>0){
        printf("%d", username);
    }else{
        if(godina<=1960){
            printf("%d", 70000+username);
        }
        if(godina>1960&&godina<=1980){
            printf("%d", 80000+username);
        }
        if(godina>1980&&godina<=1999){
            printf("%d", 90000+username);
        }
    }
return 0;
}   