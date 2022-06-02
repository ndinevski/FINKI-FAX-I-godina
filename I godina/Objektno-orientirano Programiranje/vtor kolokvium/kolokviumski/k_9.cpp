//https://i.imgur.com/DPlIhVD.png
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;


class Exception{
    public:
        Exception(){}
        void message(){
            cout<<"Ne moze da se vnese dadeniot trud"<<endl;
        }
};


class Trud{
    protected:
    char C;
    int godina;
    static int Konf;
    static int Spis;
    // void cpys(const Trud & o){
    //     this->C = o.C;
    //     this->godina = o.godina;
    // }
    public:
        Trud(char C='c', int godina=0){
            this->C = C;
            this->godina = godina;
        }
        int getPoints(){
            if(C=='c'){
                return Trud::Konf;
            }else{
                return Trud::Spis;
            }   
        }
        // Trud(const Trud& other){
        //     cpys(other);
        // }
        // Trud & operator = (const Trud & other){
        //     if(this!=&other){
        //         cpys(other);
        //     }
        //     return *this;
        // }

        int getYear(){
            return godina;
        }
        friend istream & operator>>(istream & in, Trud & t){
            return in>>t.C>>t.godina;
        }

};
int Trud::Konf = 1;
int Trud::Spis = 3;

class Student{
    protected:
        char ime[30];
        int index;
        int year;
        int * oceni;
        int n;
        // void cpys(const Student& o){
        //     strcpy(this->ime,o.ime);
        //     this->index = o.index;
        //     this->year = o.year;
        //     this->n=o.n;
        //     this->oceni = new int[o.n];
        //     copy(o.oceni, o.oceni + o.n, this->oceni);
        // }
    public:
        Student(const char * ime="", int index=0, int year=0, int *oceni=0, int n=0){
            strcpy(this->ime,ime);
            this->index = index;
            this->year = year;
            this->n=n;
            this->oceni = new int[n];
            copy(oceni, oceni + n, this->oceni);
        }
        // Student(const Student& other){
        //     cpys(other);
        // }
        // Student& operator=(const Student & other){
        //     if(this != &other){
        //         cpys(other);
        //     }
        //     return *this;
        // }
        // Student & dodadiTrud(Trud & t){
        //     return *this;
        // }
        virtual float rang(){
            float sum=0;
            for(int i=0; i<n; i++){
                sum+=oceni[i];
            }
            return (float)sum/n;
        }
        friend ostream & operator << (ostream & o , Student & s){
            return o<<s.index<<" "<<s.ime<<" "<<s.year<<" "<<s.rang()<<endl;
        }

};



class PhDStudent: public Student{
    protected:
        Trud * trudovi;
        int m;
        // void cpys(const PhDStudent& o){
        //     this->m=o.m;
        //     this->trudovi = new Trud[o.m];
        //     copy(o.trudovi, o.trudovi + o.m, this->trudovi);
        // }
    public:
        PhDStudent(const char * ime="", int index=0, int year=0, int *oceni=0, int n=0, Trud * trudovi=0, int m=0):Student(ime, index, year, oceni, n){
            this->m=m;
            this->trudovi = new Trud[m];
            copy(trudovi, trudovi + m, this->trudovi);
        }
        // PhDStudent(const PhDStudent& other):Student(other){
        //     cpys(other);
        // }
       
        PhDStudent & operator +=(Trud & t){
            if(t.getYear()<year){
                throw Exception();
                return *this;
            }

            Trud * tmp = new Trud[m+1];
            copy(trudovi, trudovi+m, tmp);
            delete [] trudovi;
            tmp[m++] = t;
            trudovi = tmp;
            return *this;
        }

        float rang(){
            float vk=0;
            for(int i=0; i<m;i++){
                vk+=trudovi[i].getPoints();
            }
            return (float)Student::rang() + vk;
        }
        friend ostream & operator << (ostream & o , PhDStudent & s){
            return o<<s.index<<" "<<s.ime<<" "<<s.year<<" "<<s.rang()<<endl;
        }


};




int main(){
	int testCase;
	cin >> testCase;

	int god, indeks, n, god_tr, m, n_tr;
	int izbor; //0 za Student, 1 za PhDStudent 
	char ime[30];
	int oceni[50];
	char tip;
	Trud trud[50];

	if (testCase == 1){
		cout << "===== Testiranje na klasite ======" << endl;
		cin >> ime;
		cin >> indeks;
		cin >> god;
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> oceni[j];
		Student s(ime, indeks, god, oceni, n);
		cout << s;

		cin >> ime;
		cin >> indeks;
		cin >> god;
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> oceni[j];
		cin >> n_tr;
		for (int j = 0; j < n_tr; j++){
			cin >> tip;
			cin >> god_tr;
			Trud t(tip, god_tr);
			trud[j] = t;
		}
		PhDStudent phd(ime, indeks, god, oceni, n, trud, n_tr);
		cout << phd;
	}
	if (testCase == 2){
		cout << "===== Testiranje na operatorot += ======" << endl;
		Student **niza;
		cin >> m;
		niza = new Student *[m];
		for (int i = 0; i<m; i++){
			cin >> izbor;
			cin >> ime;
			cin >> indeks;
			cin >> god;
			cin >> n;
			for (int j = 0; j < n; j++)
				cin >> oceni[j];

			if (izbor == 0){
				niza[i] = new Student(ime, indeks, god, oceni, n);
			}
			else{
				cin >> n_tr;
				for (int j = 0; j < n_tr; j++){
					cin >> tip;
					cin >> god_tr;
					Trud t(tip, god_tr);
					trud[j] = t;
				}
				niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
			}
		}
		// pecatenje na site studenti
            cout << "\nLista na site studenti:\n";
            for (int i = 0; i < m; i++)
                cout << *niza[i];

            // dodavanje nov trud za PhD student spored indeks
		
		Trud t;
		cin >> t;
        
		try{
		// vmetnete go kodot za dodavanje nov trud so pomos na operatorot +=
        PhDStudent * casted = dynamic_cast<PhDStudent *>(niza[1]);

        
            *casted += t;
        } catch (Exception & e){
            e.message();
        }
		
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];
	}
	if (testCase == 3){
		cout << "===== Testiranje na operatorot += ======" << endl;
		Student **niza;
		cin >> m;
		niza = new Student *[m];
		for (int i = 0; i<m; i++){
			cin >> izbor;
			cin >> ime;
			cin >> indeks;
			cin >> god;
			cin >> n;
			for (int j = 0; j < n; j++)
				cin >> oceni[j];

			if (izbor == 0){
				niza[i] = new Student(ime, indeks, god, oceni, n);
			}
			else{
				cin >> n_tr;
				for (int j = 0; j < n_tr; j++){
					cin >> tip;
					cin >> god_tr;
					Trud t(tip, god_tr);
					trud[j] = t;
				}
				niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
			}
		}
		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];

		// dodavanje nov trud za PhD student spored indeks
		Trud t;
		cin >> indeks;
		cin >> t;
        
		// vmetnete go kodot za dodavanje nov trud so pomos na operatorot += od Testcase 2


		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];
	}
	if (testCase == 4){
		cout << "===== Testiranje na isklucoci ======" << endl;
		cin >> ime;
		cin >> indeks;
		cin >> god;
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> oceni[j];
		cin >> n_tr;
		for (int j = 0; j < n_tr; j++){
			cin >> tip;
			cin >> god_tr;
			Trud t(tip, god_tr);
			trud[j] = t;
		}
		PhDStudent phd(ime, indeks, god, oceni, n, trud, n_tr);
		cout << phd;
	}
	if (testCase == 5){
		cout << "===== Testiranje na isklucoci ======" << endl;
		Student **niza;
		cin >> m;
		niza = new Student *[m];
		for (int i = 0; i<m; i++){
			cin >> izbor;
			cin >> ime;
			cin >> indeks;
			cin >> god;
			cin >> n;
			for (int j = 0; j < n; j++)
				cin >> oceni[j];

			if (izbor == 0){
				niza[i] = new Student(ime, indeks, god, oceni, n);
			}
			else{
				cin >> n_tr;
				for (int j = 0; j < n_tr; j++){
					cin >> tip;
					cin >> god_tr;
					Trud t(tip, god_tr);
					trud[j] = t;
				}
				niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
			}
		}
		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];

		// dodavanje nov trud za PhD student spored indeks
		Trud t;
		cin >> indeks;
		cin >> t;
        
		// vmetnete go kodot za dodavanje nov trud so pomos na operatorot += i spravete se so isklucokot

		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];
	}
	if (testCase == 6){
		cout << "===== Testiranje na static clenovi ======" << endl;
		Student **niza;
		cin >> m;
		niza = new Student *[m];
		for (int i = 0; i<m; i++){
			cin >> izbor;
			cin >> ime;
			cin >> indeks;
			cin >> god;
			cin >> n;
			for (int j = 0; j < n; j++)
				cin >> oceni[j];

			if (izbor == 0){
				niza[i] = new Student(ime, indeks, god, oceni, n);
			}
			else{
				cin >> n_tr;
				for (int j = 0; j < n_tr; j++){
					cin >> tip;
					cin >> god_tr;
					Trud t(tip, god_tr);
					trud[j] = t;
				}
				niza[i] = new PhDStudent(ime, indeks, god, oceni, n, trud, n_tr);
			}
		}
		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];

		int conf, journal;
		cin >> conf;
		cin >> journal;
		
        //postavete gi soodvetnite vrednosti za statickite promenlivi 
        
		// pecatenje na site studenti
		cout << "\nLista na site studenti:\n";
		for (int i = 0; i < m; i++)
			cout << *niza[i];
	}

	return 0;
}