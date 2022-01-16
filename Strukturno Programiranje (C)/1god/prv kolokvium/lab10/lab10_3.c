/*
Да се напише програма која што од дадена влезна датотека "text.txt" ќе испечати колку зборови има во секој ред, како и ќе испечати просечен број на 
зборови во редовите во датотеката. Во рамките на секој ред, кои било два збора се разделени точно со едно празно место.
Дополнително да се испечати редот со најголем број на зборови во него, на начин што секоја мала буква ќе биде голема, а секоја голема ќе биде мала.

Therefore some one more some left alas much knew one held uninspiring jeez that other and overpaid straight that outrageously that liberal abandoned affably.
A some ouch considering far barring however ouch drew suave well glibly tapir ferret danced more chose as aboard much darn necessarily circa hey inconsiderate by.
Irefully flailed that a obliquely sober that much naked until fish comfortably less prissily jeez a much rid lobster some pounded less led droll opposite near.
#
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

int totalWords(char *niza){
    int i,cnt=1;
    for(i=0;i<strlen(niza);i++){
        if(niza[i]==' '){
            cnt++;
        }
    }
    return cnt;
}

int main() {
    writeToFile();
    FILE *f = fopen("text.txt", "r");
    char maxred[500],niza[500],c;
    int redovi=0,zborovi,max=0;
    float average=0;
    while(fgets(niza, 500, f)!=NULL){
        redovi++;
        zborovi=totalWords(niza);
        average+=zborovi;
        printf("%d\n",zborovi);
        if(zborovi>max){
            max=zborovi;
            strcpy(maxred,niza);
        }
    }

    printf("%.2f\n", (float)average/redovi);

    for(int i=0;i<strlen(maxred);i++){
        if(isalpha(maxred[i])){
            if(isupper(maxred[i])){
                printf("%c", tolower(maxred[i]));
            }else if(islower(maxred[i])){
                printf("%c", toupper(maxred[i]));
            }
        }else{
            printf("%c", maxred[i]);
        }
    }
    fclose(f);
    return 0;
}