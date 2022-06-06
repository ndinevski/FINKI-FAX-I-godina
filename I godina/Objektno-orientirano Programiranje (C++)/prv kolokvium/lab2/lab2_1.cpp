// Да се дефинира класа Agol, во која се чуваат информации за:

// степени, минути и секунди (int)
// Во класата да се реализираат:

// конструктор по потреба
// методи за поставување на вредности на атрибутите на класата (set методи)
// метод за пресметување на вредноста на аголот во секунди
// Да се дефинира и метод за проверување на тоа дали внесениот агол е валиден, односно дали се внесени соодветни вредности за атрибутите (во границите кои ги дозволуваат).

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Agol {
private:
    int deg,min,sec;
public:
    Agol(){

    }
    void set_stepeni(int _deg){
        deg=_deg;
    }
    void set_minuti(int _min){
        min=_min;
    }
    void set_sekundi(int _sec){
        sec=_sec;
    }
    int getStepeni(){
        return deg;
    }
    int getMinuti(){
        return min;
    }
    int getSekundi(){
        return sec;
    }
    int to_sekundi(){
        return (min*60 + deg*60*60 + sec);
    }

};

bool changeOfSeconds(Agol a, int sec){
	return a.getSekundi()!=sec;
}

bool proveri(int deg, int min, int sec){
    if(sec>=0 && sec<=60 && min>0 && min<=60 && deg>=0 && deg<=360){
        return true;
    }
    return false;
}

int main() {
    Agol a1;
    //da se instancira objekt od klasata Agol
    int deg, min, sec;
    cin >> deg >> min >> sec;
    
    if (proveri(deg, min, sec)) {
    	a1.set_stepeni(deg);
        a1.set_minuti(min);
        a1.set_sekundi(sec);
        cout << a1.to_sekundi();
        if (changeOfSeconds(a1,sec))
			cout << "Ne smeete da gi menuvate sekundite vo ramkite na klasata!" << endl;
        return 0;    
    }
    cout<<"Nevalidni vrednosti za agol";
    
    return 0;
}
