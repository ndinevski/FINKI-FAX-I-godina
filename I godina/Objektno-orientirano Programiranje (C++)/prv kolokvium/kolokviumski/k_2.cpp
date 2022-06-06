//https://i.imgur.com/w5OLhJu.png

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

class List{
    int * broevi;
    int n;
    void cpy(const List & other){
        this->n=other.n;
        this->broevi= new int[other.n];
        copy(other.broevi, other.broevi + other.n, this->broevi);
    }
public:
    List(int * broevi=nullptr, int n=0){
        this->n=n;
        this->broevi= new int[n];
        copy(broevi, broevi + n, this->broevi);
    }
    List(const List & other){
        cpy(other);
    }
    List & operator = (const List & other){
        if(&other!=this){
            delete [] broevi;
            cpy(other);
        }
        return *this;
    }
    ~List(){
        delete [] broevi;
    }
    void pecati(){
        cout<<"List info: "<<n<<": ";
        for(int i=0;i<this->n;i++){
            cout<<broevi[i]<<" ";
        }
        cout<<"sum: "<<sum()<<" average: "<<average()<<endl;
    }
    int sum(){
        int suma=0;
        for(int i=0;i<n;i++){
            suma+=broevi[i];       
        }
        return suma;
    }
    float average(){
        return (float)sum()/n;
    }
    int getN(){
        return n;
    }
};


class ListContainer{
    List * list;
    int n;
    int tries;
    int added;
    void cpy(const ListContainer & other){
        this->n=other.n;
        this->tries=other.tries;
        this->added=other.added;
        this->list = new List[other.n];
        copy(other.list,other.list+n,this->list);
    }
public:
    ListContainer(){
        this->n=0;
        this->list=nullptr;
        this->tries=0;
        this->added=0;
    }
    ListContainer(const List & other){
        cpy(other);
    }
    ListContainer &  operator = (const ListContainer & other){
        if(&other!=this){
            delete [] list;
            cpy(other);
        }
        return *this;
    }
    ~ListContainer(){
        delete [] list;
    }
    void addNewList(List l){
        for(int i=0;i<n;i++){
            if(list[i].sum()==l.sum()){
                tries++;
                return;
            }
        }
        List *tmp;
        tmp= new List[n+1];
        copy(list,list+n,tmp);
        delete [] list;
        this->list = new List[n+1];
        tmp[n++]=l;
        list=tmp;
        added++;
    }
    void print(){
        if(n==0){
            cout<<"The list is empty"<<endl;
            return;
        }
        for(int i=0;i<n;i++){
            cout<<"List number: "<<i+1<<" ";
            list[i].pecati();
        }
        cout<<"Sum: "<<sum()<<" Average: "<<average()<<endl;
        cout<<"Successful attempts: "<<added<<" Failed attempts: "<<tries<<endl;
    }
    int sum(){
        int suma=0;
        for(int i=0;i<n;i++){
            suma += list[i].sum();
        }
        return suma;
    }
    double average(){
        double av;
        av=sum();
        int N=0;
        for(int i=0;i<n;i++){
            N+=list[i].getN();
        }
        return (double)av/N;

    }

};



int main() {
	
	ListContainer lc;
	int N;	
	cin>>N;	
    
	for (int i=0;i<N;i++) {
		int n;
		int niza[100];
		
		cin>>n;
       
		for (int j=0;j<n;j++){
			cin>>niza[j];
            
		}
       
		List l=List(niza,n);
	
		lc.addNewList(l);
	}	
	
    
    int testCase;
    cin>>testCase;
    
    if (testCase==1) {
        cout<<"Test case for operator ="<<endl;
        ListContainer lc1;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1=lc;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1.sum();
        lc1.average();
        
    }
    else {
        lc.print();
    }
}