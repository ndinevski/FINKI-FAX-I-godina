//https://i.imgur.com/jwDcEQn.png

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

class Lekar{
    protected:
        int fax;
        char ime[10];
        char prezime[11];
        double platas;
        void cpys(const Lekar&o){
            this->fax=o.fax;
            strcpy(this->ime, o.ime);
            strcpy(this->prezime, o.prezime);
            this->platas=o.platas;
        }
    public:
        Lekar(int fax=0, char * ime="", char*prezime="", double platas=0){
            this->fax=fax;
            strcpy(this->ime, ime);
            strcpy(this->prezime, prezime);
            this->platas=platas;
        }
        Lekar(const Lekar& other){
            cpys(other);
        }
        Lekar & operator = (const Lekar & other){
            if(this!=&other){
                cpys(other);
            }
            return *this;
        }
        ~Lekar(){}
        double plata(){
            return platas;
        }
        void pecati(){
            cout<<fax<<": "<<ime<<" "<<prezime<<endl;
        }
};

class MaticenLekar : public Lekar {
    private:
        int n;
        float * kotiz;
    public:
        MaticenLekar(int fax=0, char * ime="", char*prezime="", double platas=0, int n=0, float * kotiz=nullptr) : Lekar(fax, ime,prezime,platas){
            this->n=n;
            this->kotiz=new float[n];
            for(int i=0; i<n; i++){
                this->kotiz[i]=kotiz[i];
            }
        }
        MaticenLekar(Lekar & other, int n=0, float * kotiz=0) : Lekar(other){
            this->n=n;
            this->kotiz=new float[n];
            for(int i=0; i<n; i++){
                this->kotiz[i]=kotiz[i];
            }
        }
        MaticenLekar(const MaticenLekar & other) : Lekar (other){
            this->n=other.n;
            this->kotiz=new float[other.n];
            for(int i=0; i<n; i++){
                this->kotiz[i]=other.kotiz[i];
            }
        }
        MaticenLekar & operator = (const MaticenLekar & m ){
            if( this!=&m){
                delete [] kotiz;
                Lekar::operator=(m);
                this->n=m.n;
                this->kotiz=new float[m.n];
                for(int i=0; i<n; i++){
                    this->kotiz[i]=m.kotiz[i];
                }
            }
            return *this;
        }
        ~MaticenLekar(){
            delete [] kotiz;
        }
        float prosek(){
            float sum=0;
            for(int i=0; i<this->n;i++){
                sum+=kotiz[i];
            }
            return (float)sum/this->n;
        }
        void pecati(){
            Lekar::pecati();
            cout<<"Prosek na kotizacii: "<<prosek()<<endl;
        }
        double plata(){
            return Lekar::plata()+0.3*prosek();
        }
};

int main() {
	int n;
	cin>>n;
	int pacienti;
	float kotizacii[100];
	int faksimil;
	char ime [20];
	char prezime [20];
	double osnovnaPlata;
	
	Lekar * lekari = new Lekar [n];
	MaticenLekar * maticni = new MaticenLekar [n];
	
	for (int i=0;i<n;i++){
		cin >> faksimil >> ime >> prezime >> osnovnaPlata;
		lekari[i] = Lekar(faksimil,ime,prezime,osnovnaPlata);		
	}
	
	for (int i=0;i<n;i++){
		cin >> pacienti;
		for (int j=0;j<pacienti;j++){
			cin >> kotizacii[j];
		}
		maticni[i]=MaticenLekar(lekari[i],pacienti,kotizacii);
	}
	
	int testCase;
	cin>>testCase;
	
	if (testCase==1){
		cout<<"===TESTIRANJE NA KLASATA LEKAR==="<<endl;
		for (int i=0;i<n;i++){
			lekari[i].pecati();
			cout<<"Osnovnata plata na gorenavedeniot lekar e: "<<lekari[i].plata()<<endl;
		}
	}
	else {
		cout<<"===TESTIRANJE NA KLASATA MATICENLEKAR==="<<endl;
		for (int i=0;i<n;i++){
			maticni[i].pecati();
			cout<<"Platata na gorenavedeniot maticen lekar e: "<<maticni[i].plata()<<endl;
		}
	}
	
	delete [] lekari;
	delete [] maticni;
	
	return 0;
}