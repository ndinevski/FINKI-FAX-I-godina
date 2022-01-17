/*
Во датотеката podatoci.txt се запишани редови со низи од знаци (секој не подолг од 80 знаци).
Од стандарден влез се читаат два знака z1 и z2. Да се напише програма со која на стандарден излез ќе се испечатат поднизите од секој ред од датотеката составени 
од знаците што се наоѓаат меѓу z1 и z2 (без нив). Секоја подниза се печати во нов ред.
Се смета дека секој ред од датотеката точно еднаш ги содржи знаците z1 и z2, знакот z1 секогаш се наоѓа пред знакот z2, а меѓу z1 и z2 секогаш има барем еден знак.
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
    scanf("%c %c", &a, &b);
    char red[100];
    int i,indeks1=4,indeks2;
    while(fgets(red, 100, f)!=NULL){
        int n=strlen(red)-1;
        for(i=0;i<n;i++){
            if(red[i]==a){
                indeks1=i;
                break;
            }
        }
        //printf("%d", indeks1);
        for(i=n+1;i>0;i--){
            if(red[i]==b){
                indeks2=i;
                break;
            }
        }
        //printf("%d", indeks2);
        for(i=indeks2+1;i<n-indeks1;i++){
            printf("%c", red[i]);
        }
        printf("\n");
        /*for(i=0;i<n;i++){
            printf("%c", red[i]);
        }*/
    }
    fclose(f);
    return 0;
}