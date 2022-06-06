#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct date{
    int day;
    int month;
    int year; 
};
typedef struct date date;

void readDate(date * d){
    scanf("%d %d %d",&d->day,&d->month,&d->year);
}

void printDate(date d){
    printf("%02d.%02d.%d", d.day, d.month, d.year );
}

int compare(date d1,date d2){
    if(d1.year<d2.year){
        return -1;
    }else if(d1.year>d2.year){
        return 1;
    }else{
        if(d1.month>d2.month){
            return 1;
        }else if(d1.month<d2.month){
            return -1;
        }else{
            if(d1.day>d2.day){
                return 1;
            }else if(d1.day<d2.day){
                return -1;
            }else{
                return 0;
            }
        }
    }

}

int main(){
    date date1,date2;
    readDate(&date1);
    readDate(&date2);
    if(compare(date1,date2)==1){
        printDate(date2);
    }else if(compare(date1,date2)==-1){
        printDate(date1);
    }else{
        printf("isti");
    }
    return 0;
}
