#include <iostream>
#include <cstring>
using namespace std;

class String{
private:
    char * content;
public:
    //2in1 constructor
    String(char * content=""){
        this->content=new char[strlen(content)+1];
        strcpy(this->content, content);
    }
    //MUST: Copy constructor, = overload, destructor
    String(const String &other){
        this->content=new char[strlen(other.content)+1];
        strcpy(this->content, other.content);
    }

    String & operator= (const String & from){
        if(this!=&from){
            delete [] content;
            this->content=new char[strlen(from.content)+1];
            strcpy(this->content, from.content);
        }
        return *this;
    }

    ~String(){
        delete [] content;
    }
};


int main(){
    
    return 0;
}