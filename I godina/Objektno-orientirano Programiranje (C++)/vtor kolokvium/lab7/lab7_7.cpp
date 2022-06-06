//https://i.imgur.com/plME68e.png

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Secret{
    public:
        Secret(){}
        virtual double simpleEntropy() = 0;
        virtual int total() = 0;
};

bool operator == (Secret & s1, Secret & s2){
    return(s1.simpleEntropy() == s2.simpleEntropy() && s1.total() == s2.total());
}
bool operator != (Secret & s1, Secret & s2){
    return(s1.simpleEntropy() != s2.simpleEntropy() || s1.total() != s2.total());
}



class DigitSecret : public Secret {
    int niza[100];
    int n;
    public:
        DigitSecret(){
            this->n=0;
            for(int i=0;i<n;i++){
                this->niza[i]=0;
            }
        }
        DigitSecret(int * niza, int n):Secret(){
            this->n=n;
            copy(niza, niza + n, this->niza);
        }
        double simpleEntropy(){
            int vk=0;
            for (int i=0; i<n; i++){
                int isti=0;
                for (int j=0; j<n; j++){
                    if (niza[i]==niza[j]){
                        isti++;
                    }
                }
                if (isti==1){
                    vk++;
                }
            }
            return (double)vk/n;
        }
        int total(){
            return n;
        }
        friend ostream & operator <<(ostream & o, DigitSecret & s){
            for(int i=0; i<s.n; i++){
                o<<s.niza[i];
            }
            o<<" Simple entropy: "<<s.simpleEntropy()<<" Total: "<<s.total();
            return o;
        }

};

class CharSecret : public Secret {
    char niza[100];
    public:
        CharSecret(){}
        CharSecret(char * niza){
            strcpy(this->niza, niza);
        }
        int total(){
            return strlen(this->niza);
        }
        double simpleEntropy(){
            int vk=0;
            for (int i=0; i<strlen(niza); i++){
                int isti=0;
                for (int j=0; j<strlen(niza); j++){
                    if (niza[i]==niza[j]){
                        isti++;
                    }   
                }   
                if (isti==1){
                    vk++;
                }
            }
            return 1.0*vk/strlen(niza);
        }
        friend ostream & operator <<(ostream & o, CharSecret & s){
            o<<s.niza;
            o<<" Simple entropy: "<<s.simpleEntropy()<<" Total: "<<s.total();
            return o;
        }
};

void process(Secret **secrets, int n){
    double maxentropy=secrets[0]->simpleEntropy();
    Secret * max = secrets[0];
    for(int i=1;i<n;i++){
        if(secrets[i]->simpleEntropy()>maxentropy){
            maxentropy = secrets[i]->simpleEntropy();
            max = secrets[i];
        }
    }
    DigitSecret * d =dynamic_cast<DigitSecret *>(max);
    if(d){
        cout<<*d<<endl;
    }else{
        CharSecret * c = dynamic_cast<CharSecret *>(max);
        cout<<*c<<endl;
    }
}

void printAll(Secret ** secrets, int n){
    for(int i=0;i<n;i++){
        DigitSecret * d =dynamic_cast<DigitSecret *>(secrets[i]);
    if(d){
        cout<<*d<<endl;
    }else{
        CharSecret * c = dynamic_cast<CharSecret *>(secrets[i]);
        cout<<*c<<endl;
    }
    }
}



int main() {
    int n;
    cin >> n;
    if(n == 0) {
		cout << "Constructors" << endl;
		int numbers [] = {1,2,3,4,5};
        DigitSecret ds(numbers,5);
        CharSecret cs("abcabc");
        cout << "OK" << endl;
    } else if(n == 1) {
  		cout << "operator <<" << endl;
		int numbers [] = {1,2,3,4,5};
        DigitSecret ds(numbers,5);
        CharSecret cs("abcabc");
        cout << ds << endl;
        cout << cs << endl;
    }  else if(n == 2) {
  		cout << "== and !=" << endl;
		int numbers [] = {1,2,3,4,5};
        DigitSecret ds(numbers,5);
        CharSecret cs("abcabc");
        CharSecret css("abcabc");
        cout << (ds == cs) << endl;
        cout << (cs != ds) << endl;
        cout << (cs == css) << endl;
        cout << (cs != css) << endl;
    } else if(n == 3) {
  		cout << "Secret processor" << endl;
		int numbers1 [] = {1,2,3,4,5,6,4,3,2,1,1,2,3,4,5};
        DigitSecret ds1(numbers1,15);
		int numbers2 [] = {1,2,3,4,5,0,0,0,5,5,4,4,3,3,2};
        DigitSecret ds2(numbers2,15);
		int numbers3 [] = {1,0,9,4,3,8,4,0,9,3,1,4,3,2,1,4,4,3,7,2};
        DigitSecret ds3(numbers3,20);
        CharSecret cs1("fhdaieowujkfjdsafjdsakjhueiqoyroq");
        CharSecret cs2("nvzcfsadrqipqhfjdfncxoqw");
        CharSecret cs3("uyoihfdsanmqeqrzvdhfeqyrq");
        Secret** s = new Secret*[6];
        s[0] = &ds1;
        s[1] = &ds2;
        s[2] = &ds3;
        s[3] = &cs1;
        s[4] = &cs2;
        s[5] = &cs3;
        process(s,6);
        delete [] s;
    }
    else if (n==4){
        cout << "Print all secrets" << endl;
		int numbers1 [] = {1,2,3,4,5,5,4,3,2,1,1,2,3,4,5};
        DigitSecret ds1(numbers1,15);
		int numbers2 [] = {1,2,3,4,5,0,0,0,5,5,4,4,3,3,2};
        DigitSecret ds2(numbers2,15);
		int numbers3 [] = {1,0,9,4,3,8,4,0,9,3,1,4,3,2,1,4,4,3,7,2};
        DigitSecret ds3(numbers3,20);
        CharSecret cs1("fhdaieowujkfjdsafjdsakjhueiqoyroq");
        CharSecret cs2("nvzcfsadrqipqhfjdfncxoqw");
        CharSecret cs3("uyoihfdsanmqeqrzvdhfeqyrq");
        Secret** s = new Secret*[6];
        s[0] = &ds1;
        s[1] = &ds2;
        s[2] = &ds3;
        s[3] = &cs1;
        s[4] = &cs2;
        s[5] = &cs3;
        printAll(s,6);
        delete [] s;
    }
    
    return 0;
}