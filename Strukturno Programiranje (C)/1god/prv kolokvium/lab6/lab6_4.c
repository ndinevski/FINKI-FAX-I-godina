/*
За дадена квадратна матрица со големина N, најдете ја разликата помеѓу главната и споредната дијагонала, 
а потоа разликата помеѓу првата колона и последната колона на матрицата.
*/
#include <stdio.h>

int main(){
    int N,razdij=0,razkol=0;
    scanf("%d", &N);
    int a[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j){
                razdij+=a[i][j];
            }
            if(i+j==N-1){
                razdij-=a[i][j];
            }
            if(j==0){
                razkol+=a[i][j];
            }
            if(j==N-1){
                razkol-=a[i][j];
            }
        }
    }
    printf("%d\n%d", razdij,razkol);
    return 0;
}