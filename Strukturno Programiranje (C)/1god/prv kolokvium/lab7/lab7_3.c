/*
Да се напише програма во која од тастатура се читаат број на редици и колони (не поголеми од 100) и 
елементи на матрица (цели броеви).
Да се испечати редниот број на колоната (индексот) којашто има најмала сума на елементите. Ако има 
повеќе колони со иста најмала сума, да се испечати индексот на првата таква колона.
Читањето на елементи во матрицата да се направи преку функција void readMatrix(int a[100][100], int n, int m)
*/
#include <stdio.h>

void readMatrix(int a[100][100], int n, int m){
    int min,indeks;
    for(int j=0;j<m;j++){
        int suma=0;
        for(int i=0;i<n;i++){
            suma+=a[i][j];
        }
        if(j==0){
            min=suma;
            indeks=j;
        }
        if(suma<min){
            min=suma;
            indeks=j;
        }
    }
    printf("%d", indeks);
}

int main(){
    int a,b,i,j,min,suma=0,indeks,A[100][100];
    scanf("%d %d", &a, &b);
    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            scanf("%d", &A[i][j]);
        }
    }
    readMatrix(A, a, b);
    return 0;
}
