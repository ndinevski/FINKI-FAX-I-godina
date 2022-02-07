#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main(){
    int n,min,max,a,b,c;
    scanf("%d", &n);
    while(n>0){
        scanf("%d %d %d", &a, &b, &c);//rez = 2*min – max/2 + |min - a|
        min=a;
        max=a;
        float rez=0.0;
        if(a>=b && a>=c){
            if(b>=c){
                max=a;
                min=c;
            }else{
                max=a;
                min=b;
            }
        }else if(b>=a && b>=c){
            if(a>=c){
                max=b;
                min=c;
            }else{
                max=b;
                min=a;
            }
        }else{
            if(a>=b){
                max=c;
                min=b;
            }else{
                max=c;
                min=a;
            }
        }
        rez=2*min - max/2.0 + abs(min-a);
        printf("%.2f\n", rez);
        n--;
    }

    return 0;
}

