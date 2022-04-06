//https://i.imgur.com/iflP9lQ.png

#include <stdio.h>
#include <string.h>

struct Laptop{
    char firma[100];
    float mon;
    int touch;
    int price;
};
typedef struct Laptop Laptop;

struct ITStore{
    char location[100];
    char name[100];
    Laptop laptopi[100];
    int n;
};
typedef struct ITStore ITStore;

void pecati(ITStore * s, int n){
    for(int i=0;i<n;i++){
        printf("%s %s \n", s[i].name, s[i].location);
        for(int j=0;j<s[i].n;j++){
            if(s[i].laptopi[j].mon - (int) s[i].laptopi[j].mon != 0){
               printf("%s %.1f %d\n", s[i].laptopi[j].firma, s[i].laptopi[j].mon, s[i].laptopi[j].price);
            }else{
                printf("%s %d %d\n", s[i].laptopi[j].firma, (int)s[i].laptopi[j].mon, s[i].laptopi[j].price);
            }
        }
    }
}

void najeftina_ponuda(ITStore * s, int n){
    int minprice=100000;
    int mini;
    for(int i=0;i<n;i++){
        for(int j=0;j<s[i].n;j++){
            if((s[i].laptopi[j].price < minprice) && s[i].laptopi[j].touch){
                minprice=s[i].laptopi[j].price;
                mini=i;
            }
        }
    }
    printf("Najeftina ponuda ima prodavnicata: \n%s %s \n", s[mini].name, s[mini].location);
    printf("Najniskata cena iznesuva: %d", minprice);
}


int main() {
    ITStore s[100];
    int n;
    scanf("%d",&n); //broj na IT prodavnici

    //vnesuvanje na prodavnicite edna po edna, zaedno so raspolozlivite laptopvi vo niv
    for(int i=0;i<n;i++){
        scanf("%s %s %d", s[i].name,s[i].location,&s[i].n);
        for(int j=0;j<s[i].n;j++){
            scanf("%s %f %d %d", s[i].laptopi[j].firma, &s[i].laptopi[j].mon, &s[i].laptopi[j].touch, &s[i].laptopi[j].price);
        }
    }


    //pecatenje na site prodavnici
    pecati(s,n);


    //povik na glavnata metoda
    najeftina_ponuda(s, n);

    return 0;
}
