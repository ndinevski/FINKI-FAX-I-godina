/*

*/
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    while(n>0){
        int a,k,tmp;
        scanf("%d", &a);
        int Arr[a];
        for(int i=0;i<a;i++){
            scanf("%d", &Arr[i]);
        }
        scanf("%d", &k);
        for(int i=k-1;i<a;i=i+k){
            tmp=Arr[i];
            Arr[i]=Arr[i-1];
            Arr[i-1]=tmp;
        }
        for(int i=0;i<a;i++){
            printf("%d ", Arr[i]);
        }
        printf("\n");
        n--;
    }
    return 0;
}