//https://i.imgur.com/px36OmR.png

#include <stdio.h>
#include <string.h>

struct Vozenje{
    char name[100];
    int minutes;
    float price;
    int discount;
};

typedef struct Vozenje Vozenje;

struct ZabavenPark{
    char name[100];
    char location[100];
    Vozenje vozenja[100];
    int n;
};

typedef struct ZabavenPark ZabavenPark;

void pecati(ZabavenPark *z, int n){
    for(int m=0; m<n; m++){
        printf("%s %s\n", z[m].name, z[m].location);
        for(int i=0; i<z[m].n; i++){
            printf("%s %d %.2f \n",z[m].vozenja[i].name, z[m].vozenja[i].minutes, z[m].vozenja[i].price);
        }
    }
}

void najdobar_park(ZabavenPark * niza, int n)
{
    int i,j, maxI=0, maxV=0,maxVrememinutes= 0;

    for(i=0;i<n;i++)
    {
        int count=0;
        int vreme=0;
        for(j=0;j<niza[i].n;j++)
        {
            if(niza[i].vozenja[j].discount==1)
                count++;
            vreme+= niza[i].vozenja[j].minutes;
        }
        if(count>maxV)
        {
            maxV = count;
            maxI = i;
            maxVrememinutes = vreme;
        }
        else if(count==maxV&&vreme>maxVrememinutes)
        {
            maxI = i;
            maxVrememinutes = vreme;
        }
    }
    printf("Najdobar park: %s %s\n",niza[maxI].name,niza[maxI].location);
}

int main()
{
	int i, j, n, broj;
	//kreiraj vozenja od maksimum 100 zabavni parkovi
	ZabavenPark ff[100];
	scanf("%d", &n);
    //citanje na podatocite
    for (i = 0; i < n; i++){
		scanf("%s", ff[i].name);
		scanf("%s", ff[i].location);
		scanf("%d", &ff[i].n);
		for (j = 0; j < ff[i].n; j++){
			scanf("%s", ff[i].vozenja[j].name);  			
			scanf("%d", &ff[i].vozenja[j].minutes); 	
			scanf("%f", &ff[i].vozenja[j].price); 
            scanf("%d", &ff[i].vozenja[j].discount);
		}
	}
    pecati(ff,n);
    najdobar_park(ff,n);

	return 0;
}
