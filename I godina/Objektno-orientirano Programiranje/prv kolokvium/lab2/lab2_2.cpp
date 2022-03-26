// Да се дефинира класа Krug, во која се чуваат информации за:

// радиус float
// бројот π const float.
// Во класата да се реализираат:

// default конструктор и конструктор со аргументи
// метод за пресметување плоштина
// метод за пресметување периметар
// метод кој кажува дали плоштината и периметарот на даден круг се еднакви

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

class Krug{
private:
    float radius;
    const float pi=3.14;
public:
    Krug(){}
    Krug(float rad){
        radius=rad;
    }
    float perimetar(){
        return 2*radius*pi;
    }
    float plostina(){
        return radius*radius*pi;
    }
    bool ednakvi(){
        if(perimetar()==plostina()){
            return true;
        }
        return false;
    }
};


int main() {
	float r;
	cin >> r;
	//instanciraj objekt od klasata Krug cij radius e vrednosta procitana od tastatura
    Krug k(r);
	cout <<k.perimetar() << endl;
	cout <<k.plostina() << endl;
	cout << k.ednakvi() <<endl;
    //instanciraj objekt od klasata Krug cij radius ne e definiran
    Krug k1();
	return 0;
}