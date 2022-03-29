#include <iostream>
#include <cstring>
using namespace std;

class Team{
    char * name;
    char * city;
    char * stadium;
    void copy(const Team & t){
        this->name = new char [strlen(t.name)+1];
        this->city = new char [strlen(t.city)+1];
        this->stadium = new char [strlen(t.stadium)+1];
        strcpy(this->name, t.name);
        strcpy(this->city, t.city);
        strcpy(this->stadium, t.stadium);
    }
    void freememory(){
        delete [] name;
        delete [] city;
        delete [] stadium;
    }
public:
    //2in1
    Team(char * name="", char * stadium="", char * city=""){
        this->name = new char [strlen(name)+1];
        this->city = new char [strlen(city)+1];
        this->stadium = new char [strlen(stadium)+1];
        strcpy(this->name, name);
        strcpy(this->city, city);
        strcpy(this->stadium, stadium);
    }
    //copy constructyor
    Team(const Team & t){
        copy(t);
    }
    //overload =
    Team & operator =(const Team  & t){
        if(&t!=this){
            freememory();
            copy(t); 
        }
        return *this;
    }
    //destructor
    ~Team(){
        freememory();
    }
    void print(){
        cout<<name<<stadium<<city<<endl;
    }
};


int main(){
    int n;
    cin>>n;
    Team * teams = new Team[n];//treba default
    char name[50];
    char city[50];
    char stadium[50];
    
    for(int i=0;i<n;i++){
        cin>>name>>stadium>>city;
        teams[i] =   Team(name, stadium, city);//treba =
    } 
    for(int i=0;i<n;i++){
        teams[i].print();
    } 
    return 0;
}