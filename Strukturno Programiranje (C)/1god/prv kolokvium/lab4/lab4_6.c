/*
Продолжение на претходната задача:
Од стандарден влез најпрво се читаат информации за бројот на фискални сметки коишто ќе бидат 
скенирани М, а потоа се вчитуваат податоци за M фискални сметки, како во претходната задача.
На стандарден излез да се испечати повратокот на ДДВ за секоја од скенираните фискални сметки. 
На крајот да се испечати сумата на купените артикли на фискалната сметка со најголем повраток на 
ДДВ, како и повратокот на ДДВ за таа сметка.
Да се игнорираат фискалните сметки, коишто имаат сума на артиклите поголема од 30.000 денари и за 
истите да се испечати соодветна порака, како во тест примерите.
*/
#include <stdio.h>

int main(){
    int n,m,num,max=0,maxart=0;
    char tax;
    scanf("%d\n", &m);
    while(m>0){
        scanf("\n%d ", &n);
        int total=0;
        float sum=0.0;
        while(n>0){
            scanf("%d %c", &num, &tax);
            total+=num;
            switch(tax){
                case 'A':
                    sum+=num*0.18;
                    break;
                case 'B':
                    sum+=num*0.05;
                    break;
                default:
                    break;
            }
            n--;
        }
        if(total>30000){
            printf("Sum %d is bigger than 30000\n", total);
        }else{
            printf("Total tax return is: %.2f\n", sum*0.15);
            if(sum*0.15>maxart){
                maxart=sum*0.15;
            }
            if(total>max){
                max=total;
            }   
        }
        m--;  
    }
    printf("Max amount of reciept: %d. Max tax return for reciepts: %.2f", max, maxart);
    return 0;
}