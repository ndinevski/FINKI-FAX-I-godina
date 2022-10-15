/*
За програмски јазик C.

Да се напише програма во која од стандарден влез се вчитува N (бројот на производи), а потоа се вчитуваат податоците за N производи (име, цена, количина).
 Програмата треба на стандарден излез да ја отпечати листата на купени производи и вкупната сума која треба да се плати во следниот облик (пример)::

1. Flips    10.00 x 3 = 30.00
2. CocaCola 75.00 x 2 = 150.00
3. ChokoBanana  5.00 x 10 = 50.00
Total: 230.00
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct proizvod{
    char ime[20];
    float cena;
    float kolicina;
};
typedef struct proizvod proizvod;

void readProizvod(proizvod * p){
    scanf("%s %f %f", p->ime, &p->cena, &p->kolicina);
}
void printProizvod(proizvod  p){
    printf("%.2f x %.1f = %.2f",p.ime, 1.0*p.cena, 1.0*p.kolicina, p.cena*p.kolicina*1.0);
}
float cenaPoProizvod(proizvod p){
    float cenaPoProizvod=p.cena*p.kolicina*1.0;
    return cenaPoProizvod;
}

int main(){
    int i,n;
    float sum=0;
    scanf("%d", &n);
    proizvod p[100];
    for(i=1;i<=n;i++){
        readProizvod(&p[i]);
    }
    for(i=1;i<=n;i++){
        printf("%d. %s\t", i, p[i].ime);
        printProizvod(p[i]);
        sum+=cenaPoProizvod(p[i]);
        printf("\n");
    }
    printf("Total: %.2f", sum);
    return 0;
}