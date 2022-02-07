/*
Во датотеката podatoci.txt се запишани редови со низи од знаци (секој не подолг од 80 знаци).
Од стандарден влез се читаат два знака z1 и z2. Да се напише програма со која на стандарден излез ќе се испечатат поднизите од секој ред од датотеката составени 
од знаците што се наоѓаат меѓу z1 и z2 (без нив). Секоја подниза се печати во нов ред.
Се смета дека секој ред од датотеката точно еднаш ги содржи знаците z1 и z2, знакот z1 секогаш се наоѓа пред знакот z2, а меѓу z1 и z2 секогаш има барем еден знак.
1122,mleko:100       13     indeks1=4  indeks2=3
1312,leb:50
14567,kakao:20
#
,:
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void writeToFile() {
  FILE *f = fopen("podatoci.txt", "w");
  char c;
  while((c = getchar()) != '#') {
    fputc(c, f);
  }
  fclose(f);
}


int main(){
    writeToFile();
    FILE *f = fopen("podatoci.txt", "r");
    char a,b;
    getchar();
    a=getchar();
    b=getchar();
    char red[100];
    int i,indeks1,indeks2;
    while(fgets(red, 100, f)!=NULL){
        int flag=0;
        for(i=0;i<strlen(red)-1;i++){
            if(red[i]==a && flag==0){
                indeks1=i;
                flag=1;
            }
            if(red[i]==b){
                indeks2=i;
            }
        }
        for(i=indeks1+1;i<indeks2;i++){
            printf("%c", red[i]);
        }
        printf("\n");
    }
    fclose(f);
    return 0;
}