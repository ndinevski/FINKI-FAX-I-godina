/*
Благ број е број што е составен само од парни цифри (0, 2, 4, 6, 8). Во зададен опсег (почетокот m и крајот на 
опегот n се цели броеви чија вредност се внесува од тастатура), да се најде и испечати најмалиот „благ број“. 
Ако не постои таков број, да се испечати NE.
*/
#include <stdio.h>

int main(){
    int m,n,flag=0;
    scanf("%d %d", &m ,&n);
    for(int i=m;i<=n;i++){
        int tmp=i;
        while(tmp>0){
            if((tmp%10)%2!=0){
                flag=0;
                break;
            }else{
                flag=1;
                tmp/=10;
                continue;
            }
            tmp/=10;
        }
        if(flag==1){
            printf("%d", i);
            return 0;
        }
    }
    printf("NE");
    return 0;
}