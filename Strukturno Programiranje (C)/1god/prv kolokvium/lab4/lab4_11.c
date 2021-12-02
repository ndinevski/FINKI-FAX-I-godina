/*
Од влез се внесува цел позитивен број n, така што n > 2. С
о помош на ѕвездички, да се исцрта полн правоаголен триаголник 
со висина и ширина n, како во примерот:
За n=5
*
**
* *
*  *
*****
*/
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    if(n==0){
        printf("Nevaliden vlez");
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==0||i==n-1||i==j){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}