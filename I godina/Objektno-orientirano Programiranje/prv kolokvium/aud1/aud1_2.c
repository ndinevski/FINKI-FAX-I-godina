#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct Student{
    char ime[15];
    char prezime[30];
    char index[10];
    int oceni[40];
    int brojacOcenki;
};
typedef struct Student student;

void readStudent(student*s){
    scanf("%s %s %s %d", s->ime,s->prezime,s->index,&s->brojacOcenki);
    for(int i=0;i<s->brojacOcenki;i++){
        scanf("%d", &s->oceni[i]);
    }
}

void normalizeIme(char*ime){
    ime[0]=toupper(ime[0]);
    for(int i=1;i<strlen(ime);i++){
        ime[i]=tolower(ime[i]);
    }
}

float prosek(student s){
    int sum=0;
    for(int i=0;i<s.brojacOcenki;i++){
        sum+=s.oceni[i];
    }
    return sum*1.0/s.brojacOcenki;
}

void printStudent(student s){
    normalizeIme(s.ime);
    normalizeIme(s.prezime);
    printf("%s %s %s %.2f",s.ime, s.prezime,s.index, prosek(s));
}

void sort(student*s,int n){
    int i,j;
    student h;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(prosek(s[j])<prosek(s[j+1])){
                h=s[j];
                s[j]=s[j+1];
                s[j+1]=h;
            }
        }
    }
}

int main(){
    int n,i;
    scanf("%d", &n);
    student s[100];
    for(i=0;i<n;i++){
        readStudent(&s[i]);
    }
    sort(s,n);
    for(i=0;i<n;i++){   
        printStudent(s[i]);
        printf("\n");
    }
    return 0;
}