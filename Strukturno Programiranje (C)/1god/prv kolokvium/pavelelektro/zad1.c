#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char a[1000],prvarec[500],vtorarec[500];
    int i=0,j=0;
    fgets(a, 300, stdin);
    while(a[i]!='.'){
        prvarec[i]=a[i];
        i++;
    }
    prvarec[i]='.';
    i+=2;
    while(a[i]!='.'){
        vtorarec[j]=a[i];
        i++;j++;
    }
    vtorarec[j]='.';

    for(i=0;i<strlen(prvarec);i++){
        int broj=0;
        if(isdigit(prvarec[i])){
            for(j=0;j<5;j++){
                if(prvarec[i+j]==' '){
                    break;
                }
                broj=broj*10 + (int) prvarec[i+j];
            }
            int broj2=0;
            for(j=0;j<strlen(vtorarec);j++){
                
                if(isdigit(vtorarec[j])){
                    for(int k=0;k<5;k++){
                        if(prvarec[i+k]==' '){
                        break;
                        }   
                        broj2=broj2*10 + (int) prvarec[i+k];
                    }
                    break;
                }
            }
            //broj2 da se klaj vo prvarec i broj da se klaj vo vtorarec
        }
    }
    
    puts(prvarec);
    puts(vtorarec);
    return 0;
}