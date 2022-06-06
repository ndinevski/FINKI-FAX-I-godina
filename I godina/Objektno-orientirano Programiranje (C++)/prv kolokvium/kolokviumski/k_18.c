//https://i.imgur.com/pVjhfq0.png

#include <stdio.h>
#include <ctype.h>

struct SkiLift{
    char name[15];
    int maxnum;
    int on;
};
typedef struct SkiLift SkiLift;

struct SkiCenter{
    char name[20];
    char country[20];
    SkiLift liftovi[20];
    int n;
};
typedef struct SkiCenter SkiCenter;

void najgolemKapacitet(SkiCenter *sc, int n){
    int sumacentar,maxi,maxj,i,j,sumapusteni,sumapus;
    int max=0;
    for(i=0;i<n;i++){
        sumacentar=0;
        sumapusteni=0;
        for(j=0;j<sc[i].n;j++){
            if(sc[i].liftovi[j].on){
                sumacentar+=sc[i].liftovi[j].maxnum;
            }
        }
        if(sumacentar==max && sc[i].n>sc[maxi].n){
            max=sumacentar;
            maxi=i;
            maxj=j;
        }else if(sumacentar>max){
            max=sumacentar;
            maxi=i;
            maxj=j;
        }
    }
    printf("%s\n%s\n%d", sc[maxi].name,sc[maxi].country,max );
}

int main()
{
    int n;
	scanf("%d", &n);
	SkiCenter sc[20];
	for (int i = 0; i < n; i++){
		//vnesi ime
		//vnesi drzava
		//vnesi broj na liftovi
        scanf("%s %s %d", sc[i].name,sc[i].country,&sc[i].n);
		for(int j=0;j<sc[i].n;j++){
            scanf("%s %d %d", sc[i].liftovi[j].name,&sc[i].liftovi[j].maxnum,&sc[i].liftovi[j].on);
		}
        //za sekoj ski lift vnesi:
			//vnesi ime
            //vnesi maksimalen broj korisnici
            //vnesi dali e pusten vo funkcija
	}

    //povik na funkcijata najgolemKapacitet
    najgolemKapacitet(sc,n);
	return 0;
}
