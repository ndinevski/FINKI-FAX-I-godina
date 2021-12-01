/*
Да се напише програма која вчитува од стандарден влез два децимални броја 
(маса во кг и висина во цм) и пресметува и печати на стандарден излез индекс 
на телесна маса по формулата:

$BMI = \frac{masa}{visina * visina}$

Висината претходно треба да се претвори од сантиметри во метри.
*/
#include <stdio.h>
#include <math.h>

int main(){
    float mass,height;
    scanf("%f %f", &mass, &height);
    height/=100;
    printf("%.2f", mass/(height*height));
    return 0;
}