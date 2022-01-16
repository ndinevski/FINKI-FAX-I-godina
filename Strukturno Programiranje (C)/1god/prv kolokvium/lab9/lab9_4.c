/*
Да се напише функција revertString(char *a, char *b, char *comparator) која ќе ги преврти стринговите a и b и потоа ќе врати еден од нив во зависност од стрингот comparator, кој доколку има 
вредност pogolem се враќа лексикографски поголемиот или доколку има вредност pomal се враќа лексикографски помалиот. Доколку двата стрингови се еднакви, не е битно кој стринг ќе се врати.
Во главниот дел од програмата треба N пати да се прочитаат 3 стрингови и за нив да се испечати резулататот од revertString функцијата.
Забелешка: За стрингот comparator се смета дека не е case-sensitive. На пример за вредностите poGolEm и POGoleM функцијата треба да врати ист резултат. Доколку пак comparator има непозната вредност 
да се врати стрингот "Invalid comparator".
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void revertString(char *a, char *b, char *comparator){
    char tmp[100];
    int lena=strlen(a), lenb=strlen(b),cmp;
    for(int i=0;i<strlen(comparator);i++){
        comparator[i]=tolower(comparator[i]); 
    }
    if(strcmp(comparator,"pomal")==0){
        cmp=1;
    }else if(strcmp(comparator,"pogolem")==0){
        cmp=-1;
    }else{
        printf("Invalid input \n");
        return;
    }
    for(int i=0;i<lena/2;i++){
        tmp[i]=a[i];
        a[i]=a[lena-i-1];
        a[lena-i-1]=tmp[i];
    }
    for(int i=0;i<lenb/2;i++){
        tmp[i]=b[i];
        b[i]=b[lenb-i-1];
        b[lenb-i-1]=tmp[i];
    }

    if(strcmp(a,b)==0){
        if(cmp==-1){
            puts(a);
        }else{
            puts(b);
        }
    }else{
        if(cmp==1){
            puts(a);
        }else{
            puts(b);
        }
    }

}

int main(){
    int N;
    char a[100], b[100], comp[8];
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%s %s %s", a, b, comp);
        revertString(a,b,comp);
    }
    return 0;
}