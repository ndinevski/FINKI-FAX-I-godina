/*
Да се напише програма во која од дадена датотека со име "input.txt" за секој ред ќе се отпечати бројот на цифри во тој ред, знакот :, па самите цифри подредени според 
ASCII кодот во растечки редослед. Редовите во датотеката не се подолги од 100 знаци.
74I9BjpbhbsfX6Ai0xtnmv4csz2gNv = 7:0244679
*/

#include <ctype.h>
#include <string.h>
#include <stdio.h>

void wtf() {
    FILE *f = fopen("input.txt", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}

int main() {
    wtf();
    FILE *f = fopen("input.txt", "r");
    char niza[100],novaniza[100];
    while(fgets(niza, 100, f)!=NULL){
        int i,j=0,k,cnt=0,n=strlen(niza)-1;
        char tmp;
        for(i=0;i<n;i++){
            if(isdigit(niza[i])){
                cnt++;
                novaniza[j]=niza[i];
                j++;
            }
        }
        printf("%d:", cnt);
        for(i=0;i<cnt-1;i++){
            for(j=0;j<cnt-i-1;j++){
                if((novaniza[j])>(novaniza[j+1])){
                    tmp=novaniza[j];
                    novaniza[j]=novaniza[j+1];
                    novaniza[j+1]=tmp;
                }
            }
        }
        for(i=0;i<cnt;i++){
            printf("%c", novaniza[i]);
        }
        printf("\n");
    }
    fclose(f);
    return 0;
}
