//https://i.imgur.com/iN9JiKH.png

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;


class Shape{
    protected:
        int a;
    public:
        Shape(){
            a=0;
        }
        Shape(int a){
            this->a=a;
        }
        virtual double plostina() = 0;
        virtual void pecati() = 0;
        virtual int getType() = 0;
};

class Square : public Shape{
    public: 
        Square(int a):Shape(a){}
        double plostina(){
            return a*a;
        }
        void pecati(){
            cout<<"Kvadrat so plostina = "<<plostina()<<endl;
        }
        int getType(){
            return 1;
        }
};


class Circle : public Shape{
    public: 
        Circle(int a):Shape(a){}
        double plostina(){
            return 3.14*a*a;
        }
        void pecati(){
            cout<<"Krug so plostina = "<<plostina()<<endl;
        }
        int getType(){
            return 2;
        }
};


class Triangle : public Shape{
    public: 
        Triangle(int a):Shape(a){}
        double plostina(){
            return (sqrt(3)/4)*a*a*1.0;
        }
        void pecati(){
            cout<<"Triagolnik so plostina = "<<plostina()<<endl;
        }
        int getType(){
            return 3;
        }
};

void checkNumTypes(Shape ** niza, int n){
    int kvad=0,krug=0,trig=0;
    for(int i=0;i<n;i++){
        if(niza[i]->getType()==1){
            kvad++;
        }else if(niza[i]->getType()==2){
            krug++;
        }else{
            trig++;
        }
    }
    cout<<"Broj na kvadrati vo nizata = "<<kvad<<endl;
    cout<<"Broj na krugovi vo nizata = "<<krug<<endl;
    cout<<"Broj na triagolnici vo nizata = "<<trig<<endl;
}

int main(){


	int n;
	cin >> n;

	//TODO: inicijaliziraj niza od pokazuvachi kon klasata Shape
    Shape ** niza;
	

	//TODO: alociraj memorija so golemina n za prethodno navedenata niza
	niza = new Shape *[n];

	int classType;
	int side;

	//TODO: konstruiraj for ciklus so chija pomosh ke ja popolnish nizata
	for(int i = 0; i < n; ++i){

		cin >> classType;
		cin >> side;
		if(classType==1){
            niza[i]= new Square(side);
        }else if(classType==2){
            niza [i] = new Circle(side);
           
        }else{
            niza[i]= new Triangle(side);
        }
	}
    
    
	for(int i = 0; i < n; ++i){

		niza[i]->pecati();
	}

	checkNumTypes(niza, n);
    delete [] niza;

	return 0;
}