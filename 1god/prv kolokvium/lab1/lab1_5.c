#include <stdio.h>

int main(){
    int time,hours,minutes,seconds;
    scanf("%d", &time);
    hours=time/3600;
    minutes=(time-(3600*hours))/60;
    seconds=(time-(3600*hours+60*minutes));
    printf("%d sekundi se %d casovi, %d minuti i %d sekundi",time,hours,minutes,seconds);
    return 0;
}
