/*
Во дадена датотека dat.txt да се најде најдолгиот ред во кој има барем 2 цифри. На стандарден излез да се испечатат знаците од најдолгиот ред кои се наоѓаат помеѓу првата и последната цифра 
(заедно со тие 2 цифри) во истиот редослед. Доколку има повеќе такви редови се печати последниот. Се претпоставува дека ниту еден ред на датотеката не е подолг од 100 знаци.
aaa123aa222aa2aaa21aa11122 11112 aaaa11111
0123456789
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
// ne menuvaj ovde
void wtf() {
    FILE *f = fopen("dat.txt", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}

int main() {
    wtf();
	// vasiot kod ovde
    FILE *f = fopen("dat.txt", "r");
    char niza[100],najdolgred[100],maks[100];
    int indeks1,indeks2,flag=1;
    while(fgets(niza, 100, f)!=NULL){
        int i,cnt=0;
        for(i=0;i<strlen(niza);i++){
            if(isdigit(niza[i])){
                indeks1=i;
                break;
            }
        }
        for(i=strlen(niza)-2;i>0;i--){
            if(isdigit(niza[i])){
                indeks2=i;
                break;
            }
        }
        for(i=indeks1;i<indeks2;i++){
            if(isdigit(niza[i])){
                cnt++;
                indeks1=i;
            }
            if(flag && cnt==2){
                int j;
                for(i=indeks1-1, j=0;i<indeks2+1;i++,j++){
                    najdolgred[j]=niza[i];
                }   
                strcpy(maks,niza);
                flag=0;
            }
            if(cnt==2 && strlen(niza)>=strlen(maks)){
                strcpy(maks,niza);
                int j;
                for(i=indeks1-1, j=0;i<indeks2+1;i++,j++){
                    najdolgred[j]=niza[i];
                }
                break;
            }
        }
        
    }
    printf("%s", najdolgred);
    fclose(f);
    return 0;
}