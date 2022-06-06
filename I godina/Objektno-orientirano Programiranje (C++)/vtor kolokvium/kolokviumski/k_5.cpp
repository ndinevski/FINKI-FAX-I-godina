//https://i.imgur.com/bHVHZE3.png

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAX 50

enum typeC{
    standard,   
    loyal,
    vip
};

class UserExistsException{
    public:
        UserExistsException(){}
        void message(){
            cout<<"The user already exists in the list!"<<endl;
        }
};


class Customer{
    protected:
        char name[50];
        char email[50];
        typeC type;
        static int popust;
        static int ppopust;
        int br;
        void cpys(const Customer & o){
            strcpy(this->name, o.name);
            strcpy(this->email, o.email);
            this->type = o.type;
            this->br=o.br;
        }
    public:
        Customer(const char * name="", const char * email="", typeC type=standard, int br=0){
            strcpy(this->name, name);
            strcpy(this->email, email);
            this->type = type;
            this->br=br;
        }
        Customer(const Customer & other){
            cpys(other);
        }
        Customer & operator=(const Customer & other){
            if(this != &other){
                cpys(other);
            }
            return *this;
        }
        static void setDiscount1(int a){
            Customer::popust = a;
        }
        char * getEmail(){
            return email;
        }

        void setType(typeC t){
            type = t;
        }

        int getBr(){
            return br;
        }
        friend ostream & operator <<(ostream & o, Customer & c){
            o<<c.name<<endl<<c.email<<endl<<c.br<<endl;
            if((int)c.type == 0){
                o<<"standard 0"<<endl;
            }else if((int)c.type == 1){
                o<<"loyal "<<Customer::popust<<endl;
            }else{
                o<<"vip "<<Customer::ppopust<<endl;
            }
            return o;
        }

};

int Customer::popust = 10;
int Customer::ppopust = 30;

class FINKI_bookstore{
    Customer * niza;
    int n;
    public:
        FINKI_bookstore(){
            n=0;
            niza = new Customer [n];
        }

        FINKI_bookstore & operator +=(Customer & nov){
            for(int i=0;i<n;i++){
                if(!strcmp(nov.getEmail(), niza[i].getEmail())){
                    throw UserExistsException();
                }
            }
            Customer * tmp = new Customer[n+1];
            copy(niza, niza+n, tmp);
            delete [] niza;
            tmp[n++] = nov;
            niza = tmp;
            return *this;
        }

        void update(){
            for(int i=0;i<n;i++){
                if(niza[i].getBr()==17){
                    niza[i].setType(loyal);
                    continue;
                }
                if(niza[i].getBr()>=10){
                    niza[i].setType(vip);
                    continue;
                }else if(niza[i].getBr()>5){
                    niza[i].setType(loyal);
                }
            }
        }

        ~FINKI_bookstore(){
            delete [] niza;
        }

        friend ostream & operator <<(ostream & o, FINKI_bookstore & c){
            for(int i=0;i<c.n;i++){
                o<<c.niza[i];
            }
            return o;
        }

        void setCustomers(Customer * niza, int n){
            this->n=n;
            this->niza = new Customer[n];
            copy(niza, niza + n, this->niza);
        }


};

int main(){
  int testCase;
  cin >> testCase;

  char name[MAX];
  char email[MAX];
  int tC;
  int discount;
  int numProducts;


  if (testCase == 1){
    cout << "===== Test Case - Customer Class ======" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    cout << "===== CONSTRUCTOR ======" << endl;
    Customer c(name, email, (typeC) tC, numProducts);
    cout << c;

  }

  if (testCase == 2){
    cout << "===== Test Case - Static Members ======" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    cout << "===== CONSTRUCTOR ======" << endl;
    Customer c(name, email, (typeC) tC, numProducts);
    cout << c;

    c.setDiscount1(5);

    cout << c;
  }

  if (testCase == 3){
    cout << "===== Test Case - FINKI-bookstore ======" << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);

    cout << fc <<endl;
  }

  if (testCase == 4){
    cout << "===== Test Case - operator+= ======" << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);
    cout << "OPERATOR +=" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    
    Customer c(name, email, (typeC) tC, numProducts);
    fc+=c;
    cout << fc;
    
  }

  if (testCase == 5){
    cout << "===== Test Case - operator+= (exception) ======" << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);
    cout << "OPERATOR +=" << endl;
    cin.get();
    cin.getline(name,MAX);
    cin.getline(email,MAX);
    cin >> tC;
    cin >> numProducts;
    Customer c(name, email, (typeC) tC, numProducts);
    try{
        fc+=c;
    }
    catch(UserExistsException e){
        e.message();
    }
    cout << fc;
    
  }

  if (testCase == 6){
    cout << "===== Test Case - update method  ======" << endl << endl;
    FINKI_bookstore fc;
    int n;
    cin >> n;
    Customer customers[MAX];
    for(int i = 0; i < n; ++i) {
      cin.get();
      cin.getline(name,MAX);
      cin.getline(email,MAX);
      cin >> tC;
      cin >> numProducts;
      Customer c(name, email, (typeC) tC, numProducts);
      customers[i] = c;
    }

    fc.setCustomers(customers, n);

    cout << "Update:" << endl;
    fc.update();
    cout << fc;
  }
  return 0;
   
}

