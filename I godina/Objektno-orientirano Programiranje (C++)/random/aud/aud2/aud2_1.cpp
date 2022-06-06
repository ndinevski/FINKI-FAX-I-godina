// Да се напише класа за опишување на геометриско тело триаголник. Во класата
// да се напишат методи за пресметување на плоштината и периметарот на
// триаголникот.
// Потоа да се напише главна програма во која ќе се инстнацира еден објект од
// оваа класа со вредности за страните кои претходно ќе се прочитаат од
// стандарден влез. На овој објект да се повикат соодветните методи за
// пресметување на плоштината и периметарот.

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Triagolnik{
    private:
    float a;
    float b;
    float c;
    public:
    Triagolnik(float aa,float bb,float cc);
    ~Triagolnik(){}
    float area(){
        float s=(a+b+c)/2;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
    float per(){
        return a+b+c;
    }
};

Triagolnik::Triagolnik(float aa, float bb, float cc){
    if(a+b>c && a+c>b && b+c>a){
        a=aa;
        b=bb;
        c=cc;
    }else{
        cout<<"Ne validen vlez"<<endl;
    }
}

int main(){
    float a,b,c;
    cin>>a>>b>>c;
    Triagolnik triangle(a,b,c);
    cout<<triangle.area()<<" "<<triangle.per()<<endl;
    return 0;
}