/*
За програмски јазик C.

Да се напише структура која ќе опишува отсечка во дводимензионален простор (две точки). Потоа да се напише функција која ќе проверува дали две отсечки се сечат.
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct tocka{
    int x;
    int y;
};
typedef struct tocka tocka;

struct otsecka{
    tocka prva;
    tocka vtora;
};
typedef struct otsecka otsecka;

int se_secat(otsecka o1, otsecka o2){//-2-2 20 //01 12
    int a1=abs(o1.vtora.y-o1.prva.y);//2
    int b1=abs(o1.prva.x-o1.vtora.x);//-4
    int a2=abs(o2.vtora.y-o2.prva.y);//1
    int b2=abs(o2.prva.x-o2.vtora.x);//-1
    int determinant=a1*b2-a2*b1;// 
    if(determinant!=0 && o1.vtora.y!=0){
        return 1;
    }
    return 0;       
}

int main() {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    tocka t1 = { x1, y1 };
    tocka t2 = { x2, y2 };
    otsecka o1 = { t1, t2 };
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    tocka t3 = { x1, y1 };
    tocka t4 = { x2, y2 };
    otsecka o2 = { t3, t4 };
    printf("%d\n", se_secat(o1, o2));
    return 0;
}