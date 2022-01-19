#include <stdio.h>
#include <string.h>
#include <ctype.h>
/*
a b c d e        a e
e X g h i        t x
j k l X n  ===> 
o p X r s
t u v w x



*/

int main(){
    int n,m,i,j;
    char a[100][100],nova[100][100];
    scanf("%d %d", &n , &m);
    for(i=0;i<n;i++){//VNESI MATRICA
        for(j=0;j<m;j++){
            scanf("%c", &a[i][j]);
        }
    }
    for(i=0;i<n;i++){
        sleden:
            for(j=0;j<m;j++){ 
                for(int k=0;k<m;k++){ //ZA BROJ PROVERI DALI DESNO OD NEGO IMA X
                    if(a[i][j+k]=='X'){//I PROVERI DALI POD NEGO IMA X
                        goto sleden;
                    }
                    for(int s=0;s<n;s++){
                        if(a[i+s][j]=='X'){
                            goto sleden;//ako ima X vrati se na sleden
                        }
                    }
                    //AKO NEMA NI DESNO NI DOLU X STAVI GO VO NOVA MATRICA
                    nova[][];//neznam kako da se odredi golemina na novata
                }
            }
    }
    //pecati nova matrica
    return 0;
}