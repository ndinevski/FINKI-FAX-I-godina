//https://i.imgur.com/5jtYI6M.png

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

enum Size{
    small,
    large,
    family
};



class Pizza{
    protected:
        char ime[20];
        char sostojki[49];
        float cena;
        void cpys(const Pizza & o){
            strcpy(this->ime, o.ime);
            strcpy(this->sostojki, o.sostojki);
            this->cena = o.cena;
        }
    public:
        Pizza(const char * ime="", const char * sostojki="", float cena=0){
            strcpy(this->ime, ime);
            strcpy(this->sostojki, sostojki);
            this->cena = cena;
            this->sostojki[49]='\0';
        }
        Pizza(const Pizza& other){
            cpys(other);
        }
        Pizza & operator=(const Pizza& other){
            if(this != &other){
                cpys(other);
            }
            return *this;
        }
        virtual float price()=0;
        // friend ostream & operator << (ostream & o, Pizza & p){
        //     o<<p.ime<<": "<<p.sostojki<<", "<<endl;
        //     return o;
        // }
};


class FlatPizza : public Pizza{
    protected:
        Size size;
    public:
        FlatPizza(const char * ime="", const char * sostojki="", float cena=0, Size size=small): Pizza(ime,sostojki,cena){
            this->size=size;
        }

        float price(){
            if((int)size == 0){
                return 1.1*cena;
            }else if((int )size==1){
                return 1.3*cena;
            }else{
                return 1.3*cena;
            }
        }
        friend ostream & operator << (ostream & o, FlatPizza & p){
            o<<p.ime<<": "<<p.sostojki<<", ";
            if((int)p.size == 0){
                o<<"small";
            }else if((int )p.size==1){
                o<<"large";
            }else{
                o<<"family";
            }
            o<<" - "<<p.price()<<endl;
            return o;
        }
};


class FoldedPizza : public Pizza{
    protected:
        bool belo;
    public:
        FoldedPizza(const char * ime="", const char * sostojki="", float cena=0, bool belo=true) : Pizza(ime,sostojki,cena){
            this->belo = belo;
        }
        float price(){
            if(belo){
                return 1.1*cena;
            }else{
                return 1.3*cena;
            }
        }
        friend ostream & operator << (ostream & o, FoldedPizza & p){
            o<<p.ime<<": "<<p.sostojki<<", ";
            if(p.belo){
                o<<"wf";
            }else{
                o<<"nwf";
            }
            o<<" - "<<p.price()<<endl;
            return o;
        }
        void setWhiteFlour(bool a){
            this->belo= a;
        }
};

bool operator < (Pizza &a, Pizza & b){
    if(a.price()<b.price()){
        return true;
    }
    return false;
}

void expensivePizza(Pizza ** p, int n){
    Pizza * max=nullptr;
    for(int i=0;i<n;i++){
        if(max==nullptr){
            max=p[i];
        }else if(p[i]->price()>max->price()){
            max=p[i];
        }
    }
    FlatPizza * casted = dynamic_cast<FlatPizza*>(max);
    FoldedPizza * casted2 = dynamic_cast<FoldedPizza *>(max);
    if(casted){
        cout<<*casted<<endl;
    }else{
        cout<<*casted2<<endl;
    }
    
}





int main() {
  int test_case;
  char name[20];
  char ingredients[100];
  float inPrice;
  Size size;
  bool whiteFlour;

  cin >> test_case;
  if (test_case == 1) {
    // Test Case FlatPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FlatPizza fp(name, ingredients, inPrice);
    cout << fp;
  } else if (test_case == 2) {
    // Test Case FlatPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    int s;
    cin>>s;
    FlatPizza fp(name, ingredients, inPrice, (Size)s);
    cout << fp;
    
  } else if (test_case == 3) {
    // Test Case FoldedPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza fp(name, ingredients, inPrice);
    cout << fp;
  } else if (test_case == 4) {
    // Test Case FoldedPizza - Constructor, operator <<, price
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza fp(name, ingredients, inPrice);
    fp.setWhiteFlour(false);
    cout << fp;

  } else if (test_case == 5) {
	// Test Cast - operator <, price
    int s;
    
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    cin>>s;
    FlatPizza *fp1 = new FlatPizza(name, ingredients, inPrice, (Size)s);
    cout << *fp1;
      
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    cin>>s;
    FlatPizza *fp2 = new FlatPizza(name, ingredients, inPrice, (Size)s);
    cout << *fp2;
      
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza *fp3 = new FoldedPizza(name, ingredients, inPrice);
    cout << *fp3;
      
    cin.get();
    cin.getline(name,20);
    cin.getline(ingredients,100);
    cin >> inPrice;
    FoldedPizza *fp4 = new FoldedPizza(name, ingredients, inPrice);
    fp4->setWhiteFlour(false);
    cout << *fp4;
      
    cout<<"Lower price: "<<endl;
    if(*fp1<*fp2)
        cout<<fp1->price()<<endl;
    else cout<<fp2->price()<<endl;
        
    if(*fp1<*fp3)
        cout<<fp1->price()<<endl;
    else cout<<fp3->price()<<endl;    
        
    if(*fp4<*fp2)
        cout<<fp4->price()<<endl;
    else cout<<fp2->price()<<endl;
    
    if(*fp3<*fp4)
        cout<<fp3->price()<<endl;
    else cout<<fp4->price()<<endl;

  } else if (test_case == 6) {
	// Test Cast - expensivePizza
    int num_p;
    int pizza_type;

    cin >> num_p;
    Pizza **pi = new Pizza *[num_p];
    for (int j = 0; j < num_p; ++j) {

      cin >> pizza_type;
      if (pizza_type == 1) {
        cin.get();
        cin.getline(name,20);
          
        cin.getline(ingredients,100);
        cin >> inPrice;
        int s;
        cin>>s;
        FlatPizza *fp = new FlatPizza(name, ingredients, inPrice, (Size)s);
        cout << (*fp);
        pi[j] = fp;
      }
      if (pizza_type == 2) {

        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza *fp =
            new FoldedPizza (name, ingredients, inPrice);
        if(j%2)
          (*fp).setWhiteFlour(false);
        cout << (*fp);
        pi[j] = fp;

      }
    }

    cout << endl;
    cout << "The most expensive pizza:\n";
    expensivePizza(pi,num_p);


  }
  return 0;
}






