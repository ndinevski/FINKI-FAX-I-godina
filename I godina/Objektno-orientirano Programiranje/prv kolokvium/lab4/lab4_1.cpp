//https://i.imgur.com/gXZcK1w.png
#include <iostream>
#include <cstring>
using namespace std;

class List{
    int * arr;
    int n;
    void copys(const List & l){
        this->n=l.n;
        this->arr= new  int[this->n];
        for(int i=0;i<this->n;i++){
            this->arr[i]=l.arr[i];
        }
    }
public:
    //2in1
    List(int * arr=nullptr, int n=0){
        this->n=n;
        this->arr=new int[n];
        for(int i=0;i<n;i++){
            this->arr[i]=arr[i];
        }
    }
    //copy
    List(const List & l){
        copys(l);
    }
    //=
    List & operator =(const List & l){
        if(this!=&l){
            delete [] arr;
            copys(l);
        }
        return *this;
    }
    ~List(){
        delete [] arr;
    }
    int sum(){
        int sum=0;
        for(int i=0;i<n;i++){   
            sum+=arr[i];
        }
        return sum;
    }
    double average(){
        return (double)sum()/n;
    }
    void pecati(){
        cout<<n<<": ";
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"sum: "<<sum()<<" average: "<<average()<<endl;
    }
    int getBr(){
        return n;
    }

};

class ListContainer{
    List * l;
    int brojel;
    int obidi;
    void copy(const ListContainer & h){
        this->obidi=h.obidi;
        this->brojel=h.brojel;
        this->l=new List[h.brojel];
        for(int i=0;i<h.brojel;i++){
            l[i]=h.l[i];
        }
    }
public:
    ListContainer(List * l=nullptr,int brojel=0){
        this->brojel=brojel;
        this->l=new List[this->brojel];
        for(int i=0;i<this->brojel;i++){
            this->l[i]=l[i];
        }
        this->obidi=0;
    }
    ListContainer(const ListContainer & h){
        copy(h);
    }
    ListContainer & operator = (const ListContainer & h){
        if(&h!=this){
            delete [] l;
            copy(h);
        }
        return *this;
    }
    ~ListContainer(){
        delete [] l;
    }
    void print(){
        if(brojel!=0){
            for(int i=0;i<brojel;i++){
                cout<<"List number: "<<i+1;
                cout<<" List info: ";
                l[i].pecati();
            }
            cout<<"Sum: "<<sum()<<" Average: "<<average()<<endl<<"Successful attempts: "<<brojel<<" Failed attempts: "<<obidi<<endl; 
        }else{
            cout<<"The list is empty"<<endl;
        }
    }
    void addNewList(List k){
        List * tmp;
        tmp=new List[brojel+1];
        for(int i=0; i<brojel; i++){ 
            if(k.sum() == l[i].sum()){ 
                obidi++; 
                return; 
            } 
            tmp[i] = l[i]; 
        }
        tmp[brojel++] = k; 
        delete [] l; 
        this->l=new List[brojel+1];
        l = tmp;
    }
    int sum(){
        int sum=0;
        for(int i=0;i<brojel;i++){
            sum+=l[i].sum();
        }
        return sum;
    }
    double average(){
        double average=0;
        int total=0;
        for(int i=0;i<brojel;i++){
            average+=l[i].sum();
            total+=l[i].getBr();
        }
        return (double)average/total;
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