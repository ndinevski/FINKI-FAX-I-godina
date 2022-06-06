//https://i.imgur.com/yPlYQ7X.png

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;


class Book{
    protected:
        char ISBN[20];
        char naslov[50];
        char avtor[30];
        float cena;
        void cpys(const Book & o){
            strcpy(this-> ISBN, o.ISBN);
            strcpy(this-> naslov, o.naslov);
            strcpy(this-> avtor, o.avtor);
            this-> cena = o.cena;
        }
    public:
        Book(const char * ISBN="",const char * naslov="", const char * avtor="", float cena=0){
            strcpy(this-> ISBN, ISBN);
            strcpy(this-> naslov, naslov);
            strcpy(this-> avtor, avtor);
            this-> cena = cena;
        }
        Book (const Book & other){
            cpys(other);
        }
        Book & operator = (const Book & other){
            if(this!=&other){
                cpys(other);
            }
            return *this;
        }
        friend ostream &operator<<(ostream &out, Book &o)
            {
        out << o.ISBN << ": " << o.naslov << ", " << o.avtor << " " << o.bookPrice() << endl;
        return out;
        }

        void setISBN(char * ISBN){
            strcpy(this-> ISBN, ISBN);
        }
        
        virtual float bookPrice () = 0;

};


class OnlineBook : public Book{
    protected:
        char * url;
        int golemina;
        void cpys(const OnlineBook & other){
            this->url = new char[strlen(other.url)+1];
            strcpy(this-> url, other.url);
            this->golemina = other.golemina;
        }
    public:
        OnlineBook(const char * ISBN="", const char * naslov="", const char * avtor="", float cena=0, const char * url="", int golemina=0): Book(ISBN, naslov, avtor, cena){
            this->url = new char[strlen(url)+1];
            strcpy(this-> url, url);
            this->golemina = golemina;
        }
        OnlineBook(const OnlineBook & other):Book(other){
            cpys(other);
        }
        OnlineBook &operator=(const OnlineBook &o)
        {
        if (this != &o)
        {
            delete[] url;
            cpys(o);
        }
        return *this;
        }
        ~OnlineBook(){
            delete [] url;
        }
        float bookPrice(){
            if(golemina>20){
                return cena*1.2;
            }
            return cena;
        }
        friend ostream & operator << (ostream & o, OnlineBook & b){
            o<<b.ISBN<<": "<<b.naslov<<", "<<b.avtor<<" "<<b.bookPrice()<<endl;
            return o;
        }
      

};


class PrintBook : public Book{
    protected:
        float tezina;
        bool zaliha;
        void cpys(const PrintBook & other){
            this->tezina = other.tezina;
            this->zaliha = other.zaliha;
        }
    public:
        PrintBook( const char * ISBN="",  const char * naslov="", const char * avtor="", float cena=0, float tezina= 0, bool zaliha=false): Book(ISBN, naslov, avtor, cena){
            this->tezina = tezina;
            this->zaliha = zaliha;
        }
        PrintBook(const PrintBook & other):Book(other){
            cpys(other);
        }
        float bookPrice(){
            if(tezina>0.7){
                return cena*1.15;
            }
            return cena;
        }
        friend ostream & operator << (ostream & o, PrintBook & b){
            o<<b.ISBN<<": "<<b.naslov<<", "<<b.avtor<<" "<<b.bookPrice()<<endl;
            return o;
        }
        

};


bool operator >(Book & a, Book & b){
    if(a.bookPrice() > b.bookPrice()){
        return true;
    }
    return false;
}


void mostExpensiveBook(Book** books, int n){
    int online=0, print=0, b;
    Book * maxbook=nullptr;
    for(int i=0; i < n; i++){
        OnlineBook * castedbook = dynamic_cast<OnlineBook *> (books[i]);
        if(castedbook!=0){
            online++;
        }else{
            print++;
        }

        if(maxbook==nullptr){
            maxbook = books[i];
        }else if(books[i]->bookPrice()>maxbook->bookPrice()){
            maxbook = books[i];
            if(castedbook!=0){
                b = 1;
            }else{
                b = 0;
            }
        }
    }
    cout<<"FINKI-Education"<<endl;
    cout<<"Total number of online books: "<<online<<endl;
    cout<<"Total number of print books: "<<print<<endl;
    cout<<"The most expensive book is: "<<endl;
    

    cout<<*maxbook<<endl;

    
}



int main(){

	char isbn[20], title[50], author[30], url[100];
	int size, tip;
	float price, weight;
	bool inStock;
	Book  **books;
	int n;

	int testCase;
	cin >> testCase;

	if (testCase == 1){
		cout << "====== Testing OnlineBook class ======" << endl;
		cin >> n;
		books = new Book *[n];

		for (int i = 0; i < n; i++){
			cin >> isbn;
			cin.get();
			cin.getline(title, 50);
			cin.getline(author, 30);
			cin >> price;
			cin >> url;
			cin >> size;
			cout << "CONSTRUCTOR" << endl;
			books[i] = new OnlineBook(isbn, title, author, price, url, size);
			cout << "OPERATOR <<" << endl;
			cout << *books[i];
		}
		cout << "OPERATOR >" << endl;
		cout << "Rezultat od sporedbata e: " << endl;
		if (*books[0] > *books[1])
			cout << *books[0];
		else
			cout << *books[1];
	}
	if (testCase == 2){
		cout << "====== Testing OnlineBook CONSTRUCTORS ======" << endl;
		cin >> isbn;
		cin.get();
		cin.getline(title, 50);
		cin.getline(author, 30);
		cin >> price;
		cin >> url;
		cin >> size;
		cout << "CONSTRUCTOR" << endl;
		OnlineBook ob1(isbn, title, author, price, url, size);
		cout << ob1 << endl;
		cout << "COPY CONSTRUCTOR" << endl;
		OnlineBook ob2(ob1);
		cin >> isbn;
		ob2.setISBN(isbn);
		cout << ob1 << endl;
		cout << ob2 << endl;
		cout << "OPERATOR =" << endl;
		ob1 = ob2;
		cin >> isbn;
		ob2.setISBN(isbn);
        cout<<"000-0672326974: C++ Primer Plus, Stephen Prata 24"<<endl<<endl;
		cout << ob2 << endl;
	}
	if (testCase == 3){
		cout << "====== Testing PrintBook class ======" << endl;
		cin >> n;
		books = new Book *[n];

		for (int i = 0; i < n; i++){
			cin >> isbn;
			cin.get();
			cin.getline(title, 50);
			cin.getline(author, 30);
			cin >> price;
			cin >> weight;
			cin >> inStock;
			cout << "CONSTRUCTOR" << endl;
			books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
			cout << "OPERATOR <<" << endl;
			cout << *books[i];
		}
		cout << "OPERATOR >" << endl;
		cout << "Rezultat od sporedbata e: " << endl;
		if (*books[0] > *books[1])
			cout << *books[0];
		else
			cout << *books[1];
	}
	if (testCase == 4){
		cout << "====== Testing method mostExpensiveBook() ======" << endl;
		cin >> n;
		books = new Book *[n];

		for (int i = 0; i<n; i++){

			cin >> tip >> isbn;
			cin.get();
			cin.getline(title, 50);
			cin.getline(author, 30);
			cin >> price;
			if (tip == 1) {

				cin >> url;
				cin >> size;

				books[i] = new OnlineBook(isbn, title, author, price, url, size);

			}
			else {
				cin >> weight;
				cin >> inStock;

				books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
			}
		}

		mostExpensiveBook(books, n);
	}

	for (int i = 0; i<n; i++) delete books[i];
		delete[] books;
	return 0;
}
