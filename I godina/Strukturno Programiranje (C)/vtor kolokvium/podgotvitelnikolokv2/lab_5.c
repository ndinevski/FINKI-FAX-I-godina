/*
Дадена е текстуална датотека (livce.txt) која претставува ливче во спортска обложувалница.
На почетокот во датотеката, во посебен ред е запишана сумата на уплата (цел број).
Потоа во секој ред од датотеката е запишан по еден тип во следниот формат:
ab12 1 1.25
Првиот број е шифрата на типот (низа од знаци која не е подолга од 9 знаци), вториот број е типот (може да биде 1, 0 или 2) додека третиот број е коефициентот (реален број).
Ваша задача е да се испечати типот со најголем коефициент како и можната добивка на ливчето. Доколку има повеќе типови со ист максимален коефициент, да се испечати првиот.
Можната добивка се пресметува како производ на сите коефициенти со сумата на уплата.
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// ne menuvaj ovde
void wf() {
    FILE *f = fopen("livce.txt", "w");
    char c;
    while((c = getchar()) != '#') {
        fputc(c, f);
    }
    fclose(f);
}

int main() {
    wf();
	// vasiot kod pocnuva od ovde
    FILE * f = fopen("livce.txt", "r");
    int uplata,i;
    double vkupenkoef=1.0,koef,makskoef,maks=0;
    int maksk,k;
    char red[10],kod[10];
    fscanf(f, "%d", &uplata);
    while(fscanf(f, "%s %d %lf", red, &k, &koef)==3){
        vkupenkoef*=koef;
        if(koef>maks){
            maks=koef;
            strcpy(kod,red);
            maksk=k;
            makskoef=koef;
        }
    }
    printf("%s %d %.2lf\n", kod, maksk, makskoef);
    printf("%.2lf", vkupenkoef*uplata);
    fclose(f);
    return 0;    
}