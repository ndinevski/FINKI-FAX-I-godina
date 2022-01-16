/*
Да се напише функција letterFrequency (char * text, char letter) што за даден letter ќе испечати информации која е релативната фреквенција на појавување на таа буква во текстуалната низа text 
(како мала и како голема буква). Текстот е ограничен на максимум 1000 карактери.
Релативната фреквенција на буква се пресметува како количник од бројот на појавувања на таа буква и вкупниот број на букви во текстот.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

float letterFrequency(char * text,char letter){
    int i,cnt=0,n=strlen(text);
    float freq;
    for(i=0;i<n;i++){
        if(text[i]==letter){
            cnt++;
        }
    }
    freq=100.0*cnt/n;
    return freq;
}

int main(){
    char a[1000];
    fgets(a , sizeof(a), stdin);
    a[strlen(a)-1]="\0"; 
    char c,cm;
    scanf("%c", &c);
    if(isupper(c)){
        cm=tolower(c);
        printf("%c -> %.3f%%\n",    cm, letterFrequency(a, cm));
        printf("%c -> %.3f%%\n", c, letterFrequency(a, c));
    }else{
        cm=toupper(c);
        printf("%c -> %.3f%%\n", c, letterFrequency(a, c));
        printf("%c -> %.3f%%\n", cm, letterFrequency(a, cm));
    }
    return 0;
}