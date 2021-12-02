/*
Да се напише програма која ќе прочита два природни броја. Програмата треба да провери дали 
сите цифри од првиот број се појавуваат во вториот број. Ако овој услов е исполнет, програмата 
печати DA, во спротивно NE.
*/
#include <stdio.h>

int main(){
    int a,b,i,j,arrA[100],arrB[100],cnt1=0,cnt2=0,cnt=0,cntt=0;
    scanf("%d %d", &a, &b);
    for(i=0;a>0;i++){
        arrA[i]=a%10;
        cnt1++;
        a/=10;
    }
    for(i=0;b>0;i++){
        arrB[i]=b%10;
        cnt2++;
        b/=10;
    }
    for(i=0;i<cnt1;i++){
        for(j=0;j<cnt2;j++){
            if(arrA[i]==arrB[j]){
                cnt+=1;
                break;
            }else{
                continue;
            }
        }
    }
    if(cnt==cnt1){
        printf("DA");
    }else{
        printf("NE");
    }
    return 0;
}