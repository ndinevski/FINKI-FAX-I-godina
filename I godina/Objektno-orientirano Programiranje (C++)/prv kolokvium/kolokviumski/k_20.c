//https://i.imgur.com/gAH8u2m.png

#include <stdio.h>
#include <ctype.h>

struct Pacient{
    char ime[100];
    int zdrastveno;
    int pregledi;
};
typedef struct Pacient Pacient;

struct MaticenDoktor{
    char ime[100];
    int br_pac;
    Pacient niza[200];
    float cena;
};
typedef struct MaticenDoktor doktor;

void najuspesen_doktor(doktor * d, int n){
    float zarabotka,maxzarabotka=0;
    int maxi,maxj,i,j,brpreg,maxpreg;
    for(i=0;i<n;i++){
        zarabotka=0;
        brpreg=0;
        for(j=0;j<d[i].br_pac;j++){
            if(!d[i].niza[j].zdrastveno){
                zarabotka+=(d[i].niza[j].pregledi * d[i].cena);
            }
            brpreg+=d[i].niza[j].pregledi;
        }
        if(zarabotka==maxzarabotka && brpreg>maxpreg){
            maxzarabotka=zarabotka;
            maxi=i;
            maxj=j;
            maxpreg=brpreg;
        }else if(zarabotka>maxzarabotka){
            maxzarabotka=zarabotka;
            maxi=i;
            maxj=j;
            maxpreg=brpreg;
        }
    }
    printf("%s %.2f %d", d[maxi].ime, maxzarabotka, maxpreg);
}

int main()
{
	int i, j, n, broj;
	doktor md[200];
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		//ime na doktor
		scanf("%s", &md[i].ime);
		//broj na pacienti
		scanf("%d", &md[i].br_pac);
		//cena na pregled
		scanf("%f", &md[i].cena);

		for (j = 0; j < md[i].br_pac; j++){
			scanf("%s", &md[i].niza[j].ime);
			scanf("%d", &md[i].niza[j].zdrastveno);
			scanf("%d", &md[i].niza[j].pregledi);
		}
	}
	najuspesen_doktor(md, n);

	return 0;
}

