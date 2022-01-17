/*
Да се имплементира рекурзивна функција која за низа од цели броеви $[a{0}, a{1}, ..., a_{n-1}]$ ќе ја пресмета вредноста на непрекинатата дропка дефинирана како:
v=a0+1a1+...1an−2+1an−1
*/

#include <stdio.h>

double resultRec (int * a, int n, int i){
    if(i-1==n){
        return 0;
    }else{
        return a[i] + (1.0/resultRec(a, n, i+1));
    }
}

int main(){
    int n,a[100],i;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    printf("%lf", resultRec(a, n, 0));
    return 0;
}