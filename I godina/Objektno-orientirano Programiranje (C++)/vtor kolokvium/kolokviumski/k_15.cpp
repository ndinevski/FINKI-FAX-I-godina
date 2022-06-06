//https://i.imgur.com/BPFMfpY.png
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

class BadInputException{
    public:
        BadInputException(){}
        void message(){
            cout<<"Greshna opisna ocenka"<<endl;
        }
};
char * cleanString (char * string) {
	int count;
	for (int i=0;i<strlen(string);i++)
		if (isalpha(string[i]))
			count++;
	
	char * newString = new char [count+1];
	int j=0;
	for (int i=0;i<strlen(string);i++){
		if (isalpha(string[i])){
			newString[j]=string[i];
			++j;
		}			
	}
    
    return newString;
}
class StudentKurs{
   protected:
       char ime[30];
       int ocenka;
       bool daliUsno;
       static int MAX;
       static int MINOCENKA;
       
   public:
    StudentKurs(char* ime,int finalenIspit){
       strcpy(this->ime,ime);
       this->ocenka=finalenIspit;
       this->daliUsno=false;
     }
     
     friend ostream &operator << (ostream &out, StudentKurs &sk){
		out<<sk.ime<<" --- "<<sk.ocenka<<endl;
		return out;
	}
    
     char * getIme(){
         return ime;
     }
     int getOcenka(){
         return ocenka;
     }
     bool getUsno(){
         return daliUsno;
     }
     static int getMAX(){
         return StudentKurs::MAX;
     }
     virtual void ocena(){
         return;
     }
     //дополни ја класата
     static void setMAX(int a){
        StudentKurs::MAX = a;
     }
     static int getMIN(){
         return StudentKurs::MINOCENKA;
     }

};
int StudentKurs::MAX = 10;
int StudentKurs::MINOCENKA = 6;

class StudentKursUsno: public StudentKurs{
    protected:
        char * usna;
    public:
        StudentKursUsno(char * ime,int finalenIspit): StudentKurs(ime, finalenIspit){
            this->usna = new char[0];
            
        }
        
        StudentKursUsno & operator +=(char * nova){
            for(int i=0;i<strlen(nova);i++){
                if(!isalpha(nova[i])){
                    throw BadInputException();

                }
            }
            usna = new char[strlen(nova)+1];
            strcpy(usna, nova);
            return *this;
        }
        void ocena(){
            if(!strcmp(usna,"odlicen")){
                ocenka+=2;
            }else if(!strcmp(usna, "dobro")){
                ocenka+=1;
            }else if(!strcmp(usna, "losho")){
                ocenka-=1;
            }
         
        }

};
//вметни го кодот за StudentKursUsno 


class KursFakultet{
private:
    char naziv[30];
    StudentKurs *studenti[20];
    int broj;
    
public:
    KursFakultet(char *naziv, StudentKurs** studenti,int broj ){
      strcpy(this->naziv,naziv);
      for (int i=0;i<broj;i++){
        //ako studentot ima usno isprashuvanje
        if (studenti[i]->getUsno()){
            this->studenti[i]=new StudentKursUsno(*dynamic_cast<StudentKursUsno*>(studenti[i]));
        }
        else this->studenti[i]=new StudentKurs(*studenti[i]);
      }
      this->broj=broj;
    }
    ~KursFakultet(){
    for (int i=0;i<broj;i++) delete studenti[i];
    }

    //дополни ја класата
    void pecatiStudenti(){
        cout<<"Kursot "<<naziv<<" go polozile: "<<endl;
        for(int i=0; i<broj;i++){
            if(studenti[i]->getOcenka()>=StudentKurs::getMIN()){
                cout<<*studenti[i];
            }
        }
    }

    void postaviOpisnaOcenka(char * imes, char * opisna){
        for(int i=0; i<broj;i++){
            StudentKursUsno * tmp = dynamic_cast<StudentKursUsno *>(studenti[i]);
            if(!strcmp(studenti[i]->getIme(),imes)){
                if(tmp){
                    try{
               
                *tmp+=opisna;
                } catch (BadInputException e){
                    e.message();
                    *tmp+=cleanString(opisna);
                }
                }
            }
        }
    }
};

int main(){

StudentKurs **niza;
int n,m,ocenka;
char ime[30],opisna[10];
bool daliUsno;
cin>>n;
niza=new StudentKurs*[n];
for (int i=0;i<n;i++){
   cin>>ime;
   cin>>ocenka;
   cin>>daliUsno;
   if (!daliUsno)
    niza[i]=new StudentKurs(ime,ocenka);
   else
    niza[i]=new StudentKursUsno(ime,ocenka);
}

KursFakultet programiranje("OOP",niza,n);
for (int i=0;i<n;i++) delete niza[i];
delete [] niza;
cin>>m;
    
for (int i=0;i<m;i++){
   cin>>ime>>opisna;
   programiranje.postaviOpisnaOcenka(ime,opisna);
}

StudentKurs::setMAX(9);

programiranje.pecatiStudenti();

}
