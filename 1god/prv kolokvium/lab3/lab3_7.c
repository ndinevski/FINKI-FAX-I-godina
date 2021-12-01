/*
За дадени освоени поени пишете ја оценката која го следи студентот според дадените табели.
0-50 = 5|51-60 = 6|61-70 = 7|71-80 = 8|81-90 = 9|91-100 = 10|
Покрај оценките да се испечатат и знаците + и – во зависност од вредноста на последната цифра на поените:
1 - 3 = "-"|4 - 7 = " "|8-0 = "+"
*/
#include <stdio.h>

int main(){
    int points, ocenka;
    scanf("%d", &points);
    if(points>=0&&points<=50){
        ocenka=5;
    }else if(points>=51&&points<=60){
        ocenka=6;
    }else if(points>=61&&points<=70){
        ocenka=7;
    }else if(points>=71&&points<=80){
        ocenka=8;
    }else if(points>=81&&points<=90){
        ocenka=9;
    }else if(points>=91&&points<=100){
        ocenka=10;
    }else{
        printf("Nevalidna vrednost za poeni!");
    }
    if(ocenka>=6&&ocenka<=10){
        if((points%10)>=1&&(points%10)<=3){
            printf("Ocenka %d-", ocenka);
        }else if((points%10)>=4&&(points%10)<=7){
            printf("Ocenka %d ", ocenka);
        }else{
            printf("Ocenka %d+", ocenka);
        }
    }else if(ocenka==5){
        printf("Ocenka 5");
    }
    return 0;
}