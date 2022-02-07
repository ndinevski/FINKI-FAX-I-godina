/*
Да се напише програма која што од датотека со име "text.txt" ќе ги одреди и ќе ги испечати на стандарден излез:
-релативната фреквенција на сите мали букви
-релативната фреквенција на сите големи букви
Релативната фреквенција на даден(и) карактер(и) се пресметува како количник на вкупното појавување на тој/тие карактер/и со вкупниот број на карактери во текстот (да се игнорираат празните места и специјалните знаци).


fgetc(f) / fputc(f) - sekoj karakter
fgets(niza, 100, f) / fputs()- sekoj red
fscanf(f,"", vo sho)/fprintf(f,"",od sho) - formatirano



*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void writeToFile() {
    FILE *f = fopen("text.txt", "w");
    char c;
    while((c = getchar()) != '#') {
        fputc(c, f);
    }
    fclose(f);
}

int main() {
    writeToFile(); 
    FILE *f = fopen("text.txt", "r");
    char c;
    int golemi=0,mali=0,vkupno=0;
    while((c=fgetc(f)) != EOF){
        if(isalpha(c)){
            if(isupper(c)){
                golemi++;
            }
            if(islower(c)){
                mali++;
            }
            vkupno++;
        }
    }
    printf("%.4f\n%.4f", (float) golemi/vkupno, (float) mali/vkupno);
    fclose(f);
    return 0;
}