/*
Во дадена датотека “broevi.txt” се запишани повеќе редови со броеви така што секој ред започнува со еден цел број (N>=1) што означува колку броеви следуваат по него во тој ред. Да се напише програма која на СИ 
за секој ред ќе го испечати бројот со најголема најзначајна цифра. Читањето на броеви завршува кога ќе се прочита 0.

6 140640 411543 347059 273326 181484 280200
13 346319 89959 135903 214412 161282 461109 386021 192595 317100 387656 229309 406303 37392
13 360 415722 77898 190275 119626 291860 189500 172089 463497 290087 52170 186002 385509
8 142780 116977 57607 104731 499981 401529 265997 351853
12 458853 240755 336984 444638 123229 308468 91006 9148 64546 332588 102619 209680
0
*/
#include <stdio.h>
#include <string.h>
#define MAX 100

//ne menuvaj!
void wtf() {
    FILE *f = fopen("broevi.txt", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}

int stepen(int a, int b){
    int pow=1;
    for(int i=0;i<b;i++){
        pow*=a;
    }
    return pow;
}

int main()
{
    wtf();
    FILE *f = fopen("broevi.txt", "r");

    char c;
    int i,broj,cnt,max=0,number,digit;
    while((c=fgetc(f))!=EOF){
        if(isdigit(c)){
            number=number*10 + (int)c;
            cnt++;
        }else{
            if(cnt>1){
                digit=number/stepen(10, cnt-1);
            }
        }
        if(digit>max){
            max=digit;
            cnt=0;
            number=0;
        }
        if(c='\n'){
            printf("%d\n", max);
        }
    }

    fclose(f);
	return 0;
}