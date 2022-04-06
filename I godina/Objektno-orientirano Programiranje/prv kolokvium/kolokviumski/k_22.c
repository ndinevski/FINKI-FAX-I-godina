//https://i.imgur.com/HmryDHL.png

#include <stdio.h>
#include <string.h>

//место за вашиот код

struct Proizvod{
    char kod[20];
    int cena;
    int brojvomagacin;
};
typedef struct Proizvod Proizvod;

struct Narachka{
    char ime[15];
    Proizvod proizvodi[10];
    int brojnaracani[10];
    int brojproizvodi;
};
typedef struct Narachka Narachka;

void pecatiFaktura(Narachka n){
    printf("Faktura za %s\n", n.ime);
    for(int i=0;i<n.brojproizvodi;i++){
        if(n.proizvodi[i].brojvomagacin < n.brojnaracani[i]){
            printf("Fakturata ne moze da se izgotvi");
            return;
        }
    }
    for(int i=0;i<n.brojproizvodi;i++){
        for(int j=0;j<n.brojproizvodi - i -1;j++){
            if(strcmp(n.proizvodi[j].kod,n.proizvodi[j+1].kod)>0){
                Proizvod tmp;
                tmp= n.proizvodi[j];
                n.proizvodi[j]=n.proizvodi[j+1];
                n.proizvodi[j+1]=tmp;
            }
        }
    }
    int vk=0;
    for(int i=0;i<n.brojproizvodi;i++){
        printf("%s %d %d %d\n", n.proizvodi[i].kod, n.proizvodi[i].cena, n.brojnaracani[i], n.proizvodi[i].cena * n.brojnaracani[i]);
        vk+=n.proizvodi[i].cena * n.brojnaracani[i];
    }
    printf("Vkupnata suma na fakturata e %d", vk);
}




int main() {

    Narachka narachka;

    // внеси го името лицето кое ја прави нарачката
    // внеси го бројот на порачани производи во нарачката
    scanf("%s %d", narachka.ime, &narachka.brojproizvodi);
    int i;
    //за секој од нарачаните производи се внесуваат информации
    for (i = 0; i < narachka.brojproizvodi; i++) {
        // внеси код
        // внеси единицчна цена
        // внеси број на производи во магацин
        scanf("%s %d %d",narachka.proizvodi[i].kod, &narachka.proizvodi[i].cena, &narachka.proizvodi[i].brojvomagacin);
    }
    //за секој производ се внесува колку такви производи се порачани во нарачката
    int j;
    for (j = 0; j < narachka.brojproizvodi; j++) {
       //се внесува број на производи во нарачката
       scanf("%d", &narachka.brojnaracani[j]);
    }

    pecatiFaktura(narachka);
    // повик на функцијата pecatiFaktura


    return 0;
}
