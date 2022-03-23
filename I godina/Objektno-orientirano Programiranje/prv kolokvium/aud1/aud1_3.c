#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct grad{
    char name[20];
    int population;
};

struct prets{
    char name[100];
    char party[20];
};

typedef struct grad City;
typedef struct prets Pres;

struct drzava{
    char name[20];
    City capital;
    Pres president;
    int population;
};
typedef struct drzava Country;

void readPresident(Pres * p){
    scanf("%s %s",p->name, p->party);
}
void readCity(City * c){
    scanf("%s %d", c->name, &c->population);
}
void readCountry(Country * c){
    scanf("%s", c->name);
    readPresident(&c->president);
    readCity(&c->capital);
    scanf("%d", &c->population);
}

void printPresident(Pres  p){
    printf("%s %s",p.name, p.party);
}
void printCity(City  c){
    printf("%s %d", c.name, c.population);
}
void printCountry(Country  c){
    printf("%s", c.name);
    printf("\n");
    printPresident(c.president);
    printf("\n");
    printCity(c.capital);
    printf("\n");
    printf("%d", c.population);
    printf("\n");
}

int comparePopulation(Country c1,Country c2){
    if(c1.population>c2.population){
        return 1;
    }else if(c1.population<c2.population){
        return -1;
    }else{
        return 0;
    }
}
void printBiggestPopulation(Country *c, int n){
    Country max= c[0];
    for(int i=1;i<n;i++){
        if(comparePopulation(c[i],max)==1){
            max=c[i];
        }
    }
    printCountry(max);
}

int main(){
    Country c[100];
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        readCountry(&c[i]);
    }
    printBiggestPopulation(c,n);
    return 0;
}