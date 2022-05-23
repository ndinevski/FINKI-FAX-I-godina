//https://i.imgur.com/57W60WB.png

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

class ComplexNumber{
    float real;
    float imaginary;
    void copys(const ComplexNumber&o){
        this->real = o.real;
        this->imaginary = o.imaginary;
    }
    public:
    ComplexNumber(float real=0,float imaginary=0){
        this->real = real;
        this->imaginary = imaginary;
    }
    ComplexNumber(const ComplexNumber& other){
        copys(other);
    }
    ~ComplexNumber(){}
    double module(){
        return sqrt(pow(real, 2) + pow(imaginary, 2));
    }
    ComplexNumber & operator = (const ComplexNumber & o){
        if(this!=&o){
            copys(o);
        }
        return *this;
    }
    friend ostream &operator<<(ostream & out, const ComplexNumber & o){
        if(!o.real){
            out<<o.imaginary<<"i"<<endl;
        }else if(!o.imaginary){
            out<<o.real<<endl;
        }else{
            out<<o.real<<"+"<<o.imaginary<<"i"<<endl;
        }
        return out;
    }
    ComplexNumber operator+(const ComplexNumber & o){
        ComplexNumber z;
        z.real=real+o.real;
        z.imaginary=imaginary+o.imaginary;
        return z;
    }
    ComplexNumber operator-(const ComplexNumber & o){
        ComplexNumber z;
        z.real=real-o.real;
        z.imaginary=imaginary-o.imaginary;
        return z;
    }
    ComplexNumber operator*(const ComplexNumber & o){
        ComplexNumber z;
        z.real=real*o.real;
        z.imaginary=imaginary*o.imaginary;
        return z;
    }
    ComplexNumber operator/(const ComplexNumber & o){
        ComplexNumber z;
        z.real=real/o.real;
        z.imaginary=imaginary/o.imaginary;
        return z;
    }
    bool operator==(const ComplexNumber & o){
        return (real==o.real && imaginary==o.imaginary);
    }
    bool operator >(const ComplexNumber & o){
        if(real>o.real){
            return true;
        }else if(real<o.real){
            return false;
        }else{
            if(imaginary>o.imaginary){
                return true;
            }else{
                return false;
            }
        }
    }
    bool operator <(const ComplexNumber & o){
        if(real<o.real){
            return true;
        }else if(real>o.real){
            return false;
        }else{
            if(imaginary<o.imaginary){
                return true;
            }else{
                return false;
            }
        }
    }

    void setReal(float r){
        this->real=r;
    }
    void setImaginary(float i){
        this->imaginary=i;
    }


};

class Equation{
    ComplexNumber * numbers;
    char * znaci;
    public:
    Equation(ComplexNumber * numbers=nullptr, char * znaci=nullptr){}
    ~Equation(){
        delete [] numbers; 
        delete [] znaci;
    }
    friend istream &operator >> (istream & in, Equation & nov){
        char o='o';
		int index=0;
		float number;

		while(o != '='){
		    ComplexNumber *temp=new ComplexNumber[index+1];
		    char *tempc=new char[index+1];

		    for(int i=0;i<index;i++){
                temp[i]=nov.numbers[i];
                tempc[i]=nov.znaci[i];
		}
            in>>number;
            temp[index].setReal(number);
            in>>number;
            temp[index].setImaginary(number);
            in>>o;
            tempc[index]=o;
            index++;
            nov.numbers=temp;
            nov.znaci=tempc;
		}

		return in;
    }
    double sumModules(){
        double sum = 0;
        sum+=this->numbers[0].module();
        for(int i=0;this->znaci[i]!='=';i++){
            sum+=this->numbers[i+1].module();
        }
        return sum;
    }
    ComplexNumber result(){
        int i = 0;
        ComplexNumber z = this->numbers[0];
        while (this->znaci[i]!='='){
            switch (this->znaci[i]){
                case '+':
                    z=z+this->numbers[i+1];
                    break;
                case '-':
                    z=z-this->numbers[i+1];
                    break;
                case '*':
                    z=z*this->numbers[i+1];
                    break;
                case '/':
                    z=z/this->numbers[i+1];
                    break;
            }
            i++;
        }
        return z;
    }
    
};
int main() {
	int testCase;
	double real, imaginary;
	ComplexNumber first, second, result;

	cin >> testCase;

	if (testCase <= 8) {
		cin >> real;
		cin >> imaginary;
		first = ComplexNumber(real, imaginary);
		cin >> real;
		cin >> imaginary;
		second = ComplexNumber(real, imaginary);
	}

	if (testCase == 1) {
		cout << "===== OPERATOR + =====" << endl;
		result = first + second;
		cout << result;
	}
	else if (testCase == 2) {
		cout << "===== OPERATOR - =====" << endl;
		result = first - second;
		cout << result;
	}
	else if (testCase == 3) {
		cout << "===== OPERATOR * =====" << endl;
		result = first * second;
		cout << result;
	}
	else if (testCase == 4) {
		cout << "===== OPERATOR / =====" << endl;
		result = first / second;
		cout << result;
	}
	else if (testCase == 5) {
		cout << "===== OPERATOR == =====" << endl;
		cout << first;
		cout << second;
		if (first == second)
			cout << "EQUAL" << endl;
		else
			cout << "NOT EQUAL" << endl;
	}
	else if (testCase == 6) {
		cout << "===== OPERATOR > =====" << endl;
		cout << first;
		cout << second;
		if (first > second)
			cout << "FIRST GREATER THAN SECOND" << endl;
		else
			cout << "FIRST LESSER THAN SECOND" << endl;
	}
	else if (testCase == 7) {
		cout << "===== OPERATOR < =====" << endl;
		cout << first;
		cout << second;
		if (first < second)
			cout << "FIRST LESSER THAN SECOND" << endl;
		else
			cout << "FIRST GREATER THAN SECOND" << endl;
	}
	else if (testCase == 8) {
		cout << "===== MODULE =====" << endl;
		double module = first.module();
		cout << first;
		cout << "Module: " << module << endl;
		cout << second;
		module = second.module();
		cout << "Module: " << module << endl;
	}
	else if (testCase == 9) {
		cout << "===== OPERATOR >> & SUM OF MODULES =====" << endl;
		Equation equation;
		cin >> equation;
		cout << equation.sumModules();
	}
	else if (testCase == 10) {
		cout << "===== EQUATION RESULT =====" << endl;
		Equation equation;
		cin >> equation;
		result = equation.result();
		cout << result;
	}
	return 0;
}







