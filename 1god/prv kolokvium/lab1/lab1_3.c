#include <stdio.h>
#include <math.h>

int main(){
    float mass,height;
    scanf("%f %f", &mass, &height);
    height/=100;
    printf("%.2f", mass/(height*height));
    return 0;
}