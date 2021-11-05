#include <stdio.h>
#include <math.h>

int main(){
    float x1,x2,x3,y1,y2,y3,AB,AC,BC,max;
    scanf("%f%f\n%f%f\n%f%f", &x1, &y1, &x2, &y2, &x3, &y3);
    AB=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    AC=sqrt(pow(x3-x1,2)+pow(y3-y1,2));
    BC=sqrt(pow(x3-x2,2)+pow(y3-y2,2));
    if(AB>AC){
        if(AB>BC){
            printf("AB");
        }else{
            printf("BC");
        }
    }else if(BC>AC){
        if(BC>AB){
            printf("BC");
        }else{
            printf("AB");
        }
    }else{
        printf("AC");
    }
    return 0;
}