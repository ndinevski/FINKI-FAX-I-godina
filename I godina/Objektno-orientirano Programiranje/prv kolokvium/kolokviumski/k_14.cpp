#include <iostream> 
using namespace std;

int Volume(int a,int b=0,float c=0){
    return a*b*c;
}

int main(){
int a=5,b=2,c=3;
cout<<Volume(a)<<endl;
return 0;
}