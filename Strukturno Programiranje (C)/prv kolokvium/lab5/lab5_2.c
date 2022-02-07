/*
Да се напише програма која ќе прочита два природни броја. Програмата треба да провери дали 
сите цифри од првиот број се појавуваат во вториот број. Ако овој услов е исполнет, програмата 
печати DA, во спротивно NE.
*/
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