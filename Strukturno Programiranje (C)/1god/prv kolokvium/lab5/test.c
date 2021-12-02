#include <stdio.h>

int main()
{
    int a,b; 
    scanf("%d %d", &a, &b);
    while(a>0)
    {
        int tmp=b;
        int digit=a%10; 
        int cnt=0;
        while(tmp>0){
            if(tmp%10 == digit) { 
                cnt=1; 
            } 
            tmp/=10;
        }  
        if(cnt==0){ 
            printf("NE");
            return 0; 
        } 
        a/=10;
    }
    printf("DA");
    return 0;
}