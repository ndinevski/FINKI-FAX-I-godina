// Во оваа задача треба да се внесат и испечатат податоци за автомобили.
// За еден автомобил (објект од класата Car) се чуваат следниве податоци:
// сопственик (објект од класата Person)
// датум на купување (објект од класата Date)
// цена (float price), предодредена вредност 0
// За класата Car потребно е да се напише метод за печатење print() и метод за добивање на цената getPrice().
// Класата Date содржи три цели броеви (int year, month, day) кои претставуваат датум. За неа треба да се напише метод за печатење print(), 
//предодреден (default) конструктор, конструктор со параметри и конструктор за копирање.
// Класата Person содржи име и презиме (низи од максимум 20 знаци, со предодредени вредности not specified), предодреден конструктор, конструктор со 
//параметри и метод за печатење print().
// Методот за печатење кај класата Person изгледа вака: [name] [lastName].
// Методот за печатење кај класата Date изгледа вака: [year].[month].[day]
// Методот за печатење кај класата Car изгледа вака:
// owner.print()
// date.print(
// Price: [price]
// Покрај тоа, потребно е да се напише метод cheaperThan(Car* cars, int numCars, float price) кој ќе ги испечати сите објекти Car од ниата cars со големина numCars чија цена е помала од price.

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

class Date{
private:
    int year;
    int month;
    int day;
public:
    Date(){//df constructor
        year=0;
        month=0;
        day=0;
    }
    //constructor
    Date(int _year, int _month, int _day){
        year=_year;
        month=_month;
        day=_day;
    }
    //copy constructor
    Date(const Date &d){
        year=d.year;
        month=d.month;
        day=d.day;
    }
    //destructor
    ~Date(){}
    //print function Date
    void print(){
        cout<<year<<"."<<month<<"."<<day<<endl;
    }
};

class Person{
private:
    char name[20];
    char surname[20];
public:
    Person(){//df constructor
        strcpy(name, "not specified");
        strcpy(surname, "not specified");
    }
    //constructor
    Person(char * _name, char * _surname){
        strcpy(name, _name);
        strcpy(surname, _surname);
    }
    //copy constructor
    Person(const Person & p){
        strcpy(name, p.name);
        strcpy(surname, p.surname);
    }
    //destructor
    ~Person(){}
    //print function Person
    void print(){
        cout<<name<<" "<<surname<<endl;
    }
};

class Car{
private:
    Person owner;
    Date date;
    float price;
public:
    Car(){//df constructor
        price=0;
    }
    //constructor
    Car(Person o, Date d, float _price){
        owner=o;
        date=d;
        price=_price;
    }
    //destructor
    ~Car(){}
    //getter
    float getPrice(){
        return price;
    }
    //print function Car
    void print(){
        owner.print();
        date.print();
        cout<<"Price: "<<price<<endl;
    }
};

void cheaperThan(Car* cars, int numCars, float price){
    for(int i=0;i<numCars;i++){
        if(cars[i].getPrice() < price){
            cars[i].print();
        }
    }
}

int main() {
	char name[20];
	char lastName[20];
	int year;
	int month;
	int day;
	float price;
	int testCase;
	cin >> testCase;

	if (testCase == 1) {
		cin >> name;
		cin >> lastName;
		Person lik(name, lastName);

		cin >> year;
		cin >> month;
		cin >> day;
		Date date(year, month, day);

		cin >> price;
		Car car(lik, date,  price);

		car.print();
	}
	else if (testCase == 2) {
		cin >> name;
		cin >> lastName;
		Person lik(name, lastName);

		cin >> year;
		cin >> month;
		cin >> day;
		Date date(Date(year, month, day));

		cin >> price;

		Car car(lik, date,  price);
		car.print();
	}
	else {
		int numCars;
		cin >> numCars;

		Car cars[10];
		for (int i = 0; i < numCars; i++) {
			cin >> name;
			cin >> lastName;
			Person lik(name, lastName);

			cin >> year;
			cin >> month;
			cin >> day;
			Date date(year, month, day);

			cin >> price;
			cars[i] = Car(lik, date,  price);
		}
        float priceLimit;
        cin >> priceLimit;
		cheaperThan(cars, numCars, priceLimit);
	}

    return 0;
}