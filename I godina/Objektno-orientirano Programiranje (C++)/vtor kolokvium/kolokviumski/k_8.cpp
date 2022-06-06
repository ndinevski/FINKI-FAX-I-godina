//https://i.imgur.com/UkHvfzL.png

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

class Koncert{
    protected:
        char naziv[20];
        char lokacija[20];
        static float popust;
        float cenas;
    public:
        Koncert( const char * naziv="", const char * lokacija="", float cenas=0){
            strcpy(this->naziv, naziv);
            strcpy(this->lokacija, lokacija);
            this->cenas = cenas;
        }
        static void setSezonskiPopust(float a){
            Koncert::popust=a;
        }
        static float getSezonskiPopust(){
            return Koncert::popust/100.0;
        }
        char * getNaziv(){
            return naziv;
        }
        virtual float cena(){
            return cenas - cenas*Koncert::popust/100.0;
        }
    

};

float Koncert::popust = 20;


class ElektronskiKoncert : public Koncert{
    private:
        char * ime;
        float hours;
        bool dnevna;
    public:
        ElektronskiKoncert( const char * naziv="", const char * lokacija="", float cenas=0,const char * ime="", float hours=0, bool dnevna=true):Koncert(naziv, lokacija, cenas){
            this->ime = new char[strlen(ime)+1];
            strcpy(this->ime,ime);
            this->hours = hours;
            this->dnevna = dnevna;
        }
        ~ElektronskiKoncert(){
            delete [] ime;
        }
        float cena(){
            float c;
            if(hours>7){
                c= Koncert::cena() + 360;
            }else if(hours>=5){
                c =  Koncert::cena() + 150;
            }else{
                c = Koncert::cena();
            }
            if(dnevna){
                c = c - 200;
            }else{
                c = c+ 100;
            }
            return (float)c;
        }

};

void najskapKoncert(Koncert ** koncerti, int n){
    int max=0, indeks,cnt=0;
    for(int i=0;i<n;i++){
        ElektronskiKoncert * casted = dynamic_cast<ElektronskiKoncert *>(koncerti[i]);
        if(casted){
            cnt++;
        }
        if(koncerti[i]->cena() > max){
            indeks= i;
            max = koncerti[i]->cena();
        }
    }
    cout<<"Najskap koncert: "<<koncerti[indeks]->getNaziv()<<" "<<koncerti[indeks]->cena()<<endl;
    cout<<"Elektronski koncerti: "<<cnt<<" od vkupno "<<n<<endl;
}


bool prebarajKoncert(Koncert ** koncerti, int n, char * naziv, bool elektronski){
    for(int i=0;i<n;i++){
        if(elektronski){
            ElektronskiKoncert * casted = dynamic_cast<ElektronskiKoncert *>(koncerti[i]);
            if(casted){
                if(strcmp(koncerti[i]->getNaziv(), naziv)==0){
                cout<<koncerti[i]->getNaziv()<<" "<<koncerti[i]->cena()<<endl;
                return true;
            }
               
            }
        }else{
            if(strcmp(koncerti[i]->getNaziv(), naziv)==0){
                cout<<koncerti[i]->getNaziv()<<" "<<koncerti[i]->cena()<<endl;
                return true;
            }
        }
    }
    return false;
}



int main(){

    int tip,n,novaCena;
    char naziv[100], lokacija[100], imeDJ[40];
    bool dnevna;
    float cenaBilet, novPopust;
    float casovi;

        cin>>tip;
        if (tip==1){//Koncert
        	cin>>naziv>>lokacija>>cenaBilet;
        	Koncert k1(naziv,lokacija,cenaBilet);
        	cout<<"Kreiran e koncert so naziv: "<<k1.getNaziv()<<endl;
        }
        else if (tip==2){//cena - Koncert
            cin>>naziv>>lokacija>>cenaBilet;
        	Koncert k1(naziv,lokacija,cenaBilet);
        	cout<<"Osnovna cena na koncertot so naziv "<<k1.getNaziv()<< " e: " <<k1.cena()<<endl;
        }
        else if (tip==3){//ElektronskiKoncert
            cin>>naziv>>lokacija>>cenaBilet>>imeDJ>>casovi>>dnevna;
            ElektronskiKoncert s(naziv,lokacija,cenaBilet,imeDJ,casovi,dnevna);
            cout<<"Kreiran e elektronski koncert so naziv "<<s.getNaziv()<<" i sezonskiPopust "<<s.getSezonskiPopust()<<endl;
        }
        else if (tip==4){//cena - ElektronskiKoncert
             cin>>naziv>>lokacija>>cenaBilet>>imeDJ>>casovi>>dnevna;
             ElektronskiKoncert s(naziv,lokacija,cenaBilet,imeDJ,casovi,dnevna);
             cout<<"Cenata na elektronskiot koncert so naziv "<<s.getNaziv()<<" e: "<<s.cena()<<endl;
        }
        else if (tip==5) {//najskapKoncert

        }
        else if (tip==6) {//prebarajKoncert
            Koncert ** koncerti = new Koncert *[5];
            int n;
            koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
            koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
            koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
            koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
            koncerti[4] = new ElektronskiKoncert("CavoParadiso","Mykonos",8800,"Guetta",3,true);
            char naziv[100];
        	najskapKoncert(koncerti,5);
        }
        else if (tip==7){//prebaraj
        	  Koncert ** koncerti = new Koncert *[5];
            int n;
            koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
            koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
            koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
            koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
            koncerti[4] = new ElektronskiKoncert("CavoParadiso","Mykonos",8800,"Guetta",3,true);
            char naziv[100];
            bool elektronski;
        	cin>>elektronski;
        	if(prebarajKoncert(koncerti,5, "Area",elektronski))
                cout<<"Pronajden"<<endl;
            else cout<<"Ne e pronajden"<<endl;

            if(prebarajKoncert(koncerti,5, "Area",!elektronski))
                cout<<"Pronajden"<<endl;
            else cout<<"Ne e pronajden"<<endl;

        }
        else if (tip==8){//smeni cena
        	Koncert ** koncerti = new Koncert *[5];
            koncerti[0] = new Koncert("Area","BorisTrajkovski",350);
            koncerti[1] = new ElektronskiKoncert("TomorrowLand","Belgium",8000,"Afrojack",7.5,false);
            koncerti[2] = new ElektronskiKoncert("SeaDance","Budva",9100,"Tiesto",5,true);
            koncerti[3] = new Koncert("Superhiks","PlatoUkim",100);
            koncerti[2] -> setSezonskiPopust(90);   
        	najskapKoncert(koncerti,4);
        }

    return 0;
}
