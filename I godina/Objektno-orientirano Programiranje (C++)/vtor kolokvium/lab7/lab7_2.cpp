//https://i.imgur.com/N9Shany.png

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Number{
    public:
        virtual double doubleValue() =0;
        virtual int intValue() = 0;
        virtual void print()=0;
};

bool operator==(Number * broj1, Number & broj2){
    return (broj1->doubleValue()==broj2.doubleValue() && broj1->intValue()==broj2.intValue());
}

class Integer : public Number{
    protected:
        int number;
    public:
        Integer(int number=0){
            this->number = number;
        }
        double doubleValue(){ 
            return 0;
        }
        int intValue() {
            return number;
        }
        void print(){
            cout<<"Integer: "<<number<<endl;
        }
};


class Double : public Number{
    protected:
        double number;
    public:
    Double(double number=0){
        this->number = number;
    }
    double doubleValue(){
            return number - intValue();
    }
    int intValue() {
            return (int)number;
    }
    void print(){
            cout<<"Double: "<<number<<endl;
    }
};

class Numbers{
    protected:
        Number ** numbers;
        int n;
        void cpys(const Numbers & o){
            this->n = o.n;
            this->numbers = new Number *[o.n];
            copy(o.numbers, o.numbers+n,numbers);
        }
    public:
        Numbers(){
            this->n=0;
            this->numbers = new Number * [this->n];
        }
        Numbers(const Number & other){
            cpys(other);
        }
        Numbers & operator = (const Numbers & other){
            if(this!=&other){
                delete [] numbers;
                cpys(other);
            }
            return *this;
        }
        Numbers & operator +=(Number * nov){
            for(int i=0;i<n;i++){
                if(numbers[i]==*nov){
                    return *this;
                }
            }
           
            Number ** tmp = new Number * [n+1];
            copy(numbers,numbers+n,tmp);
            delete [] numbers;
            tmp[n++]=nov;
            numbers=tmp;
            return *this;
        }
        ~Numbers(){
            delete [] numbers;
        }
        double suma(){
            double sum=0;
            for(int i=0;i<n;i++){
                sum+=(numbers[i]->intValue()+numbers[i]->doubleValue());
            }
            return sum;
        }
        bool isInteger(Number * numb){
            Integer * casted = dynamic_cast<Integer *>(numb);
            if(casted!=0){
                return true;
            }
            return false;
        }
        int intsuma(){
            int sum=0;
            for(int i=0;i<n;i++){
                if(isInteger(numbers[i])){
                    sum+=(numbers[i]->intValue()+numbers[i]->doubleValue());
                }
            }
            return sum;
        }
        int intcount(){
            int count=0;
            for(int i=0;i<n;i++){
                if(isInteger(numbers[i])){
                    count++;
                }
            }
            return count;
        }
        void statistics(){
            cout<<"Count of numbers: "<<n<<endl;
            cout<<"Sum of all numbers: "<<suma()<<endl;
            cout<<"Count of integer numbers: "<<intcount()<<endl;
            cout<<"Sum of integer numbers: "<<intsuma()<<endl;
            cout<<"Count of double numbers: "<<n-intcount()<<endl;
            cout<<"Sum of double numbers: "<<suma() - intsuma()<<endl;
        }
        void integersLessThan(Integer integer){
            int flag=0;
            for(int i=0;i<n;i++){
                if(isInteger(numbers[i])){
                    if(numbers[i]->intValue()<integer.intValue()){
                        numbers[i]->print();
                        flag=1;
                    }
                }
            }
            if(!flag){
                cout<<"None"<<endl;
            }
        }
        void doublesBiggerThan(Double doubles){
            int flag=0;
            for(int i=0;i<n;i++){
                if(isInteger(numbers[i])){
                    continue;
                }
                if((numbers[i]->intValue()+numbers[i]->doubleValue()) > (doubles.intValue()+doubles.doubleValue())){
                        numbers[i]->print();
                        flag=1;
                }
            }
            if(!flag){
                cout<<"None"<<endl;
            }
        }

};

int main() {
	
	int n;
	cin>>n;
	Numbers numbers;
	for (int i=0;i<n;i++){
		int type;
		double number;
		cin>>type>>number;
		if (type==0){//Integer object
			Integer * integer = new Integer((int) number);
			numbers+=integer;
		}
		else {
			Double * doublee = new Double(number);
			numbers+=doublee;
		}
	}
	
	int lessThan;
	double biggerThan;
	
	cin>>lessThan;
	cin>>biggerThan;		
	
	cout<<"STATISTICS FOR THE NUMBERS\n";
	numbers.statistics();
	cout<<"INTEGER NUMBERS LESS THAN "<<lessThan<<endl;
	numbers.integersLessThan(Integer(lessThan));
	cout<<"DOUBLE NUMBERS BIGGER THAN "<<biggerThan<<endl;
	numbers.doublesBiggerThan(Double(biggerThan));
	
	return 0;
}