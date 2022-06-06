#include <stdio.h>
#include <ctype.h>
#include <math.h>

struct CertificateCov19{
    int den;
    int mesec;
    int godina;
    char ime[50];
    int red;
};
typedef struct CertificateCov19 Cert;

struct Patient{
    char ime[50];
    char embg[13];
    Cert sertifikat;
};
typedef struct Patient Patient;

void vakciniraniTretaDoza(Patient * p, int n){//procent na treta doza
    int sotreta=0;
    for(int i=0;i<n;i++){
        if(p[i].sertifikat.red==3){
            sotreta++;
        }
    }
    printf("Procentualno se vakcinirale so treta doza %.2f%% od pacientite", (float)sotreta/n*100);
}

void pacientiTretaDoza(Patient * p, int n, int d, int m, int y){//koj treba da primi treta doza
    printf("Pacienti koi treba da primat 3ta doza vakcina na %d/%d/%d se:\n", d, m, y);
    //int denovipocetna = (y-1) * 12 * 30 + m*30 + d;
    for(int i=0;i<n;i++){
        if(p[i].sertifikat.red==2){
            //int denovipacient = ((p[i].sertifikat.godina-1) * 12 * 30) + p[i].sertifikat.mesec * 30 + p[i].sertifikat.den;
            //int razlika = denovipocetna - denovipacient;
            //if(razlika >= 160){
            //    printf("Ime: %s - embg: %s\n", p[i].ime, p[i].embg);
            //}
            if(p[i].sertifikat.mesec - m>=6 || m -p[i].sertifikat.mesec>=6 ){
                printf("Ime: %s - embg: %s\n", p[i].ime, p[i].embg);
            }//treba da se sporedat i denovi

        }
    }
}

int main(){
    int N;
    scanf("%d", &N);
    Patient pacienti[N];
    for(int i=0;i<N;i++){//vnesuvanje pacienti
        scanf("%s %s %s ", pacienti[i].ime,  pacienti[i].embg, pacienti[i].sertifikat.ime);
        scanf("%d/%d/%d", &pacienti[i].sertifikat.den,  &pacienti[i].sertifikat.mesec, &pacienti[i].sertifikat.godina);
        scanf("%d", &pacienti[i].sertifikat.red);
    }
    //printf("%s %d/%d/%d", pacienti[0].embg, pacienti[0].sertifikat.den, pacienti[0].sertifikat.mesec, pacienti[0].sertifikat.godina);
    int den,mesec,godina;
    scanf("%d/%d/%d", &den,  &mesec, &godina);//vnesuvanje datum
    pacientiTretaDoza(pacienti, N, den, mesec, godina);
    vakciniraniTretaDoza(pacienti,N);
    return 0;
}
