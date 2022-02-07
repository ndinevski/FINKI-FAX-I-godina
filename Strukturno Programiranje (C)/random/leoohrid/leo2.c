#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int checkNumber(int k)
{
    int sum=0,tmp=k;
    while(k){
       sum=sum + ((k%10)*(k%10)*(k%10));
       k/=10;
    }
    if(sum==tmp){
        return 1;
    }
    return 0;
}
int main()
{
    int n,k,a[100][100],i,j,cnt=0;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if ((i+j)>=n){
                k=a[i][j];
                if(checkNumber(k)){
                    printf("%d\n", a[i][j]);
                    cnt++;
                }
            }
        }
    }
    printf("There are %d numbers that satisfy the condition.", cnt);
    return 0;
}