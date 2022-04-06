//https://i.imgur.com/Oyzmhmm.png

#include <stdio.h>
#include <string.h>
#define NEDELI 4
#define DENOVI 5

// ovde strukturata RabotnaNedela
struct RabotnaNedela{
    int casovi[DENOVI];
    int nedela;
};
typedef struct RabotnaNedela RN;

// ovde strukturata Rabotnik
struct Rabotnik{
    char ime[50];
    RN nedeli[NEDELI];
};
typedef struct Rabotnik R;

// ovde funkciite
int maxNedela(R * r){
    int maxweek=0,sumweek,k;
    for(int i=0;i<NEDELI;i++){
        sumweek=0;
        for(int j=0;j<DENOVI;j++){
            sumweek+=r->nedeli[i].casovi[j];
        }
        if(sumweek>maxweek){
            maxweek=sumweek;
            k=i;
        }
    }
    return k+1;
}

int casVoNedela(R r, int ned){
    int cas=0;
    for(int i=0;i<5;i++){
        cas+=r.nedeli[ned].casovi[i];
    }
    return cas;
}

void table(R *r, int n){
    int vkupno;
    printf("Rab\t1\t2\t3\t4\tVkupno\n");
    for(int i=0;i<n;i++){
        printf("%s\t",r[i].ime);
        vkupno=0;
        for(int j=0;j<4;j++){
            printf("%d\t",casVoNedela(r[i],j));
            vkupno+=casVoNedela(r[i],j);
        }
        printf("%d\n", vkupno);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    R rabotnici[n];
    int i;
    for (i = 0; i < n; ++i) {
        scanf("%s", rabotnici[i].ime);
        int j;
        for (j = 0; j < NEDELI; ++j) {
            int k;
            for (k = 0; k < DENOVI; ++k) {
                scanf("%d", &rabotnici[i].nedeli[j].casovi[k]);
            }

        }
    }
    printf("TABLE\n");
    table(rabotnici, n);
    printf("MAX NEDELA NA RABOTNIK: %s\n", rabotnici[n / 2].ime);
    printf("%d\n", maxNedela(&rabotnici[n / 2]));
    return 0;
}
