//https://i.imgur.com/TCIpU7c.png

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

class PlDrustvo{
    char * name;
    int turi;
    int n;
    int max;
    void cpys(const PlDrustvo&o){
        this->name=new char[strlen(o.name)+1];
        strcpy(this->name, o.name);
        this->turi=o.turi;
        this->n=o.n;
    }
    public:
    PlDrustvo(char * name="", int turi=0, int n=0){
        this->name=new char[strlen(name)+1];
        strcpy(this->name, name);
        this->turi=turi;
        this->n=n;
    }
    PlDrustvo(const PlDrustvo& other){
        cpys(other);
    }
    PlDrustvo& operator=(const PlDrustvo&other){
        if(this!=&other){
            delete [] name;
            cpys(other);
        }
        return *this;
    }
    ~PlDrustvo(){
        delete [] name;
    }
    bool operator >(const PlDrustvo& v){
        if(this->n>v.n){
            return true;
        }else{
            return false;
        }
    }
    bool operator <(const PlDrustvo& v){
        if(this->n<v.n){
            return true;
        }else{
            return false;
        }
    }
    PlDrustvo & operator + (const PlDrustvo & nov){
        if(*this<nov){
            this->turi=nov.turi;
            delete [] this->name;
            this->name= new char[strlen(nov.name)+1];
            strcpy(this->name, nov.name);
            this->max=nov.n;
            this->n+=nov.n;
            return *this;
        }
        this->max=this->n;
        this->n+=nov.n;
        return *this;
    }
    friend ostream &operator<<(ostream & out, const PlDrustvo & p){
        out<<"Ime: "<<p.name<<" Turi: "<<p.turi<<" Clenovi: "<<p.n<<endl;
        return out;
    }
    int getN(){
        return n;

    }
    int getTuri(){
        return turi;
    }
    int getMax(){
        return max;
    }
    char * getName(){
        return name;
    }
};

void najmnoguClenovi(PlDrustvo * d, int n){
    if(d[0]>d[1] && d[0]>d[2]){
        cout<<"Najmnogu clenovi ima planinarskoto drustvo: ";
        cout<<"Ime: "<<d[0].getName()<<" Turi: "<<d[0].getTuri()<<" Clenovi: "<<d[0].getMax()<<endl;
        return;
    }
    if(d[1]>d[0] && d[1]>d[2]){
        cout<<"Najmnogu clenbovi ima planinarskoto drustvo: "<<d[0];
        cout<<"Ime: "<<d[1].getName()<<" Turi: "<<d[1].getTuri()<<" Clenovi: "<<d[1].getMax()<<endl;
        return;
    }
    if(d[2]>d[1] && d[2]>d[0]){
        cout<<"Najmnogu clenbovi ima planinarskoto drustvo: "<<d[0];
        cout<<"Ime: "<<d[2].getName()<<" Turi: "<<d[2].getTuri()<<" Clenovi: "<<d[2].getMax()<<endl;
        return;
    }

}





int main()
{        		
    PlDrustvo drustva[3];
    PlDrustvo pl;
    for (int i=0;i<3;i++)
   	{
    	char ime[100];
    	int brTuri;
    	int brClenovi;
    	cin>>ime;
    	cin>>brTuri;
    	cin>>brClenovi;
    	PlDrustvo p(ime,brTuri,brClenovi);
        drustva[i] = p;
    	
   	}
    
    pl = drustva[0] + drustva[1];
    cout<<pl;
    
    najmnoguClenovi(drustva, 3);
    
    return 0;
}
