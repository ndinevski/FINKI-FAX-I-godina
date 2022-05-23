//https://i.imgur.com/Rlh13ZS.png

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

class Matrica{
    int n;
    float M[10][10];
    public:
    Matrica(int num=0){
        this->n=10;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            this->M[i][j]=num;
            }
        }
    }
    ~Matrica(){}
     Matrica &operator *(const Matrica &o){
        
        float temp[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int zbir = 0;
                for(int k=0;k<n;k++){
                    zbir+=(this->M[i][k]*o.M[k][j]);
                }
                temp[i][j]=zbir;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                this->M[i][j]=temp[i][j];
            }
        }
        return *this;
    }
    Matrica &operator +(const Matrica& o){
        for(int i=0;i<n;i++){    
            for(int j=0;j<n;j++){    
                this->M[i][j]+=o.M[i][j];  
            }    
        } 
        return *this;
    }
    
    Matrica &operator -(const Matrica& o){
        for(int i=0;i<n;i++){    
            for(int j=0;j<n;j++){    
                this->M[i][j]-=o.M[i][j];  
            }    
        } 
        return *this;
    }

    friend istream & operator>>(istream & in, Matrica & nov){
        in>>nov.n>>nov.n;
        for(int i=0;i<nov.n;i++){
            for(int j=0;j<nov.n;j++){
                in>>nov.M[i][j];
            }
        }
        return in;
    }
    friend ostream & operator<<(ostream & out, const Matrica & nov){
        for(int i=0;i<nov.n;i++){
            for(int j=0;j<nov.n;j++){
                out<<nov.M[i][j]<<" ";
            }
            out<<endl;
        }
        return out;
    }
    
};

int main()
{
    Matrica A,B,C;
    cin>>A>>B>>C;
    Matrica D=B*C;
    Matrica R=A-D+2;
    cout<<R;
}