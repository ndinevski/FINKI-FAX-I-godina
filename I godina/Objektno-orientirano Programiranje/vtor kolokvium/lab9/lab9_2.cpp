//https://i.imgur.com/4z7gyuN.png

#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <cmath>
using namespace std;

class ArithmeticException{
    public:
        void message(){
            cout<<"Division by zero is not allowed"<<endl;
        }
};

class NumbersNotDivisibleException{
    int divisor;
    public:
        NumbersNotDivisibleException(int divisor){
            this->divisor = divisor;
        }
        void message(){
            cout<<"Division by "<<divisor<<" is not supported"<<endl;
        }
};

class ArrayFullException{
    public:
        void message(){
            cout<<"The array is full. Increase the capacity"<<endl;
        }
};

class IndexOutOfBoundsException{
    int index;
    public:
        IndexOutOfBoundsException(int index){
            this->index = index;
        }
        void message(){
            cout<<"Index "<<index<<" is out of bounds"<<endl;
        }
};

class NumberIsNotPositiveException{
    int number;
    public:
        NumberIsNotPositiveException(int number){
            this->number = number;
        }
        void message(){
            cout<<"Number "<<number<<" is not positive integer"<<endl;
        }
};
class PositiveIntegers{
    protected:
        int * numbers;
        int n;
        int max;
        void cpys(const PositiveIntegers& o){
            n=o.n;
            max=o.max;
            numbers = new int[n];
            for(int i=0; i<n; i++){
                numbers[i]=o.numbers[i];
            }
        }
    public:
        PositiveIntegers(){
            max=0;
            n=0;
            numbers = new int[0];
        }
        PositiveIntegers(int max){
            this->max = max;
            this->n=0;
            numbers = new int[0];
        }
        PositiveIntegers(const PositiveIntegers & other){
            cpys(other);
        }
        PositiveIntegers & operator = (const PositiveIntegers & other){
            if(this!=&other){
                delete [] numbers;
                cpys(other);
            }
            return *this;
        }

        ~PositiveIntegers(){
            delete [] numbers;
        }

        void increaseCapacity(int c){
            max+=c;
        }
        PositiveIntegers & operator +=(int nov){
            if(n==max){
                throw ArrayFullException();
            }
            if(nov<=0){
                throw NumberIsNotPositiveException(nov);
            }
            int * temp = new int[n+1];
            copy(numbers,numbers+n,temp);
            delete [] numbers;
            temp[n++]=nov;
            numbers = temp;
            return *this;
        }
        PositiveIntegers operator *(int nov){
            PositiveIntegers k(*this);
            for(int i=0;i<n;i++){
                k.numbers[i]*=nov;
            }
            return k;
        }
        PositiveIntegers operator /(int nov){
            //TOOD
            if(nov==0){
                throw ArithmeticException();
            }
            for(int i=0;i<n;i++){
                if(numbers[i]%nov!=0){
                    throw NumbersNotDivisibleException(nov);
                }
            }
            PositiveIntegers k(*this);
            for(int i=0;i<n;i++){
                k.numbers[i]/=nov;
            }
            return k;
        }
        int operator [] (int i){
            if(i>=n || i<0){
                throw IndexOutOfBoundsException(i);
            }
            return numbers[i];
        }
        void print(){
            cout<<"Size: "<<n<<" Capacity: "<<max<<" Numbers: ";
            for(int i=0;i<n;i++){
                cout<<numbers[i]<<" ";
            }
            cout<<endl;
        }
};

int main() {
	
	int n,capacity;
	cin >> n >> capacity;
	PositiveIntegers pi (capacity);
	for (int i=0;i<n;i++){
		int number;
		cin>>number;
        try{
		pi+=number;
        }
        catch (ArithmeticException& a){
        a.message();
        }
        catch (NumbersNotDivisibleException& a){
            a.message();
        }
        catch (NumberIsNotPositiveException& a){
            a.message();
        }
        catch (IndexOutOfBoundsException& a){
            a.message();
        }
        catch (ArrayFullException &a){
            a.message();
        }
	}
	cout<<"===FIRST ATTEMPT TO ADD NUMBERS==="<<endl;
	pi.print();
	int incCapacity;
	cin>>incCapacity;
	pi.increaseCapacity(incCapacity);
	cout<<"===INCREASING CAPACITY==="<<endl;
	pi.print();
	
	int n1;
	cin>>n1;
	for (int i=0;i<n1;i++){
		int number;
		cin>>number;
        try{
		pi+=number;    
        }   
        catch (ArithmeticException &a){
        a.message();
    }
    catch (NumbersNotDivisibleException &a){
        a.message();
    }
    catch (NumberIsNotPositiveException &a){
        a.message();
    }
    catch (IndexOutOfBoundsException &a){
        a.message();
    }
    catch (ArrayFullException& a){
        a.message();
    } 
	}
	cout<<"===SECOND ATTEMPT TO ADD NUMBERS==="<<endl;
	
    pi.print();	
	PositiveIntegers pi1;
	
	cout<<"===TESTING DIVISION==="<<endl;	
	try{
        pi1 = pi/0;
        pi1.print();
    }
    catch (ArithmeticException &a){
        a.message();
    }
    catch (NumbersNotDivisibleException &a){
        a.message();
    }
    try{
        pi1 = pi/1;
        pi1.print();	
    }
    catch (ArithmeticException &a){
        a.message();
    }
    catch (NumbersNotDivisibleException & a){
        a.message();
    }
	try{
        pi1 = pi/2;
        pi1.print();
    }
    catch (ArithmeticException &a){
        a.message();
    }
    catch (NumbersNotDivisibleException& a){
        a.message();
    }
    
	cout<<"===TESTING MULTIPLICATION==="<<endl;
    
	pi1 = pi*3;
	pi1.print();

	cout<<"===TESTING [] ==="<<endl;
    try{
	cout<<"PositiveIntegers[-1] = "<<pi[-1]<<endl;	
    }
    catch (ArithmeticException &a){
        a.message();
    }
    catch (NumbersNotDivisibleException& a){
        a.message();
    }
    catch (NumberIsNotPositiveException &a){
        a.message();
    }
    catch (IndexOutOfBoundsException& a){
        a.message();
    }
    catch (ArrayFullException& a){
        a.message();
    }
    try{
    cout<<"PositiveIntegers[2] = "<<pi[2]<<endl;
    }
    catch (ArithmeticException &a){
        a.message();
    }
    catch (NumbersNotDivisibleException& a){
        a.message();
    }
    catch (NumberIsNotPositiveException &a){
        a.message();
    }
    catch (IndexOutOfBoundsException& a){
        a.message();
    }
    catch (ArrayFullException& a){
        a.message();
    }
    try{
    cout<<"PositiveIntegers[3] = "<<pi[3]<<endl;	
    }
    catch (ArithmeticException &a){
        a.message();
    }
    catch (NumbersNotDivisibleException& a){
        a.message();
    }
    catch (NumberIsNotPositiveException &a){
        a.message();
    }
    catch (IndexOutOfBoundsException& a){
        a.message();
    }
    catch (ArrayFullException& a){
        a.message();
    }
    try{
    cout<<"PositiveIntegers[12] = "<<pi[12]<<endl;
    }
    catch (ArithmeticException &a){
        a.message();
    }
    catch (NumbersNotDivisibleException& a){
        a.message();
    }
    catch (NumberIsNotPositiveException &a){
        a.message();
    }
    catch (IndexOutOfBoundsException& a){
        a.message();
    }
    catch (ArrayFullException& a){
        a.message();
    }
	
	
	return 0;
}