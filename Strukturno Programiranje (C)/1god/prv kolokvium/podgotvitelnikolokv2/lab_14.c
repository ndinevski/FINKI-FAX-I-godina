/*
Да се напише програма во која се вчитува матрица од цели броеви A со N редици и N * 2 колони (N не е поголемо од 50). Програмата треба да ја трансформира вчитаната матрица во нова матрица B, 
така што сите елементи десно од N-тата колона ќе ги префрли под N-тата редица, односно од матрица со димензија N редици и 2 * N колони ќе се добие матрица со 2 * N редици x N колони.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(){
    int n,i,j;
    scanf("%d", &n);
    int m=2*n;
    int a[100][100];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(j<n){
                scanf("%d", &a[i][j]);
            }
            if(j>n-1){
                scanf("%d", &a[i+n][j-n]);
            }
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}