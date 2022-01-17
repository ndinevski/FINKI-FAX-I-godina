/*
Дадена е текстуална датотека text.txt.
Да се избројат и испечатат сите последнователни појавувања на соседни самогласки во датотеката. Појавата на големи и мали букви да се игнорира. Пронајдените парови самогласки да се испечатат на екран, 
секој во нов ред со мали букви. Потоа во нов ред се печати бројот на појавувања на паровите самогласки.
Пример: за датотеката:
IO is short for Input Output
medioio medIo song
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void writeToFile() {
  FILE *f = fopen("text.txt", "w");
  char c;
  while((c = getchar()) != '#') {
    fputc(c, f);
  }
  fclose(f);
}

int isVowel(char c){
    if(c=='a' || c=='e' || c=='o' || c=='i' || c=='u'){
        return 1;
    }else{
        return 0;
    }
}

int main() {  
    writeToFile();
    FILE *f = fopen("text.txt", "r");
    char c[100];
    int cnt=0;
    while(fgets(c, 100, f)!=NULL){
        for(int i=0;i<strlen(c)-1;i++){
            c[i]=tolower(c[i]);
            c[i+1]=tolower(c[i+1]);
            if(isVowel(c[i])!=0 && (isVowel(c[i])==isVowel(c[i+1]))){
                printf("%c%c\n", c[i], c[i+1]);
                cnt++;
            }
        }
    }
    printf("%d", cnt);
    fclose(f);
    return 0;
}
