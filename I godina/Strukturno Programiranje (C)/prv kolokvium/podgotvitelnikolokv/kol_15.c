/*
Од тастатура се внесува колку студенти полагале колоквиум и потоа се внесуваат поените на сите кои полагале. Програмата треба да отпечати средна вредност на поените на сите студенти кои имале помалку од 
50 поени, како и список на студентите со повеќе од 50 поени. Исто така програмата да отпечати средна вредност на поените на сите кои положиле со најмалку 50 поени и нивните освоени поени (редоследот на 
печатење во двата случаеви треба да биде ист како и редоследот на внесување). Максималниот број на студенти што може да се внесат е 1000.
Влез:
10 //Kolku studenti?
20 10 50 60 70 90 40 20 70 90 //Poeni?
Излез
Sredna vrednost na padnati 22.50
20 10 40 20 
Sredna vrednost na polozeni 71.67
50 60 70 90 70 90
*/
#include <stdio.h>

int main(){
    int n,sumF=0,sumP=0,cntF=0,cntP=0;
    scanf("%d", &n);
    int points[n];
    for(int i=0;i<n;i++){
        scanf("%d", &points[i]);
    }
    printf("Sredna vrednost na padnati ");
    for(int i=0;i<n;i++){
        if(points[i]<50){
            sumF+=points[i];
            cntF++;
        }
    }
    printf("%.2f\n", (float)sumF/cntF);
    for(int i=0;i<n;i++){
        if(points[i]<50){
            printf("%d ", points[i]);
        }
    }
    printf("\n");
    printf("Sredna vrednost na polozeni ");
    for(int i=0;i<n;i++){
        if(points[i]>=50){
            sumP+=points[i];
            cntP++;
        }
    }
    printf("%.2f\n", (float)sumP/cntP);
    for(int i=0;i<n;i++){
        if(points[i]>=50){
            printf("%d ", points[i]);
        }
    }
    return 0;
}
