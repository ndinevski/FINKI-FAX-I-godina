/*
Од датотека "input.txt" да се вчита квадратна матрица, така што прво ќе се прочита број n што означува колку редови и колони има матрица, а потоа да се вчитаат сите n x n елементи од матрицата.
Во датотеката "output.txt" да се запише матрицата така што ќе се запишат само елементите над главната дијагонала, но ќе имаат вредност колку сумата на елементите на главната дијагонала. Печатењето 
да се прави со три места за бројот за елементите над главната дијагонала, а за останатите да се испечатат три празни места, со цел да се добие посакуваниот излез како во тест примерите.
00 01 02 03
10 11 12 13
20 21 22 23
30 31 32 33

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>


void writeToFile() {
    FILE *f = fopen("input.txt", "w");
    char c;
    while((c = getchar()) != '#') {
        fputc(c, f);
    }
    fclose(f);
}

void printFile() {

    FILE *f=fopen("output.txt","r");
    char line[100];
    while(!feof(f)){
        fgets(line,100,f);
        if (feof(f))
            break;
        printf("%s",line);
    }
    fclose(f);
}

int main() {
    writeToFile();
    FILE *f = fopen("input.txt", "r");
    FILE *fo= fopen("output.txt", "w");
    int n,i,j,dijag=0;
    int a[100][100];
    fscanf(f, "%d", &n);
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            fscanf(f, "%d", &a[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j){
                dijag+=a[i][j];
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j>i){
                if(dijag>10){
                    fprintf(fo, "0%d ", dijag);
                }else{
                    fprintf(fo, "00%d ", dijag);
                }
            }else{
                fprintf(fo, "    ");
            }
        }
        fprintf(fo,"\n");
    }
    fclose(f);
    fclose(fo);
    printFile();
    return 0;
}