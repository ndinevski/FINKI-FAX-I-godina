/*
Од стандарден влез се читаат знаци се додека не се прочита извичник. Во вака внесениот текст се скриени 
цели броеви (помали од 100). Да се напише програма што ќе ги прочита сите знаци и на излез ќе го испечати 
збирот на сите броеви скриени во текстот.
*/
#include <stdio.h>

int main(){
    char c;
    int sum=0,broj=0;
    do{
        scanf("%c", &c);
        if(c>='0'&& c<='9'){
            broj=broj*10+(c-'0');
        }else{
            sum+=broj;
            broj=0;
        }
    }while(c!='!');
    printf("%d", sum);
    return 0;
}
