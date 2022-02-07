/*
Од стандарден влез се внесуваат два цели броја N и Х.
Да се најде најблискот број помал од N коj е тотално различен од бројот Х.
Еден број е тотално различен од друг ако и само ако во него не се појавува ниту една од цифрите на другиот број.
Задачата да се реши без употреба на низи и матрици.
*/
#include <stdio.h>

int main(){
    int N,X,cifraX,cifraN;
    scanf("%d %d", &N, &X);
    N-=1;
    while(N>=-99999999){//86 7
        int tmp,tmpp=N;
        while(tmpp>0){
            tmp=X;
            cifraN=tmpp%10;
            while(tmp>0){
                cifraX=tmp%10;
                tmp/=10;
                if(cifraX!=cifraN){
                    continue;
                }else{
                    tmpp=-10;
                    break;
                }
            }
            tmpp/=10;
        }
        if(tmpp==-1){
            N--;
        }else{
            printf("%d", N);
            return 0;
        }
    }
    return 0;
}