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