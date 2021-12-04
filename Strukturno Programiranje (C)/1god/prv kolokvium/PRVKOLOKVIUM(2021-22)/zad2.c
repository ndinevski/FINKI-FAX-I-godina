#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main(){
    int X,N,a;
    scanf("%d %d", &X, &N);
    while(N>0){
        scanf("%d", &a);
        /*if(a<=9){
            N--;
            continue;
        }*/
        int tmp=a,cnt=0,nov,stepen=1;
        while(tmp>0){
            cnt++;
            tmp/=10;
        }
        for(int i=1; i<cnt;i++){
            stepen*=10;
        }
        nov=(a%(stepen))*10 + a/stepen;
        if(X!=0 && nov%X==0){
            printf("DA\n");
        }else{
            printf("NE\n");
        }
        N--;
    }
    return 0;
}

