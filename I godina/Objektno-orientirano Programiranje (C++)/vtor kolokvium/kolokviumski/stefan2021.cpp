//https://i.imgur.com/L2YUGBI.png

#include<cstring>
#include<iostream>
#include <algorithm>
#include <cctype>

using namespace std;

class OperationNotSupported{
public:
    void showMessage(){
        cout<<"Username already exists"<<endl;
    }
};

class OperationNotSupport{
public:
    void showMessage(){
        cout<<"The group's capacity has been exceeded."<<endl;
    }
};




class User {
    char *username;
    char *companyName;
    int position;

    void copy(const User &u) {
        this->username = new char[strlen(u.username) + 1];
        strcpy(this->username, u.username);
        this->companyName = new char[strlen(u.companyName) + 1];
        strcpy(this->companyName, u.companyName);
        this->position = u.position;
    }

public:
    User(char *username = "", char *companyName = "", int position = 0) {
        this->username = new char[strlen(username) + 1];
        strcpy(this->username, username);
        this->companyName = new char[strlen(companyName) + 1];
        strcpy(this->companyName, companyName);
        this->position = position;
    }

    User(const User &u) {
        copy(u);
    }

    User &operator=(const User &u) {
        if (this != &u) {
            delete[] username;
            delete[] companyName;
            copy(u);
        }
        return *this;
    }

    ~User() {
        delete[] username;
        delete[] companyName;
    }

    char *getUsername() const {
        return username;
    }

    void setUsername(char *username) {
        this->username = new char[strlen(username) + 1];
        strcpy(this->username, username);
    }

    char *getCompanyName() const {
        return companyName;
    }

    void setCompanyName(char *companyName) {
        this->companyName = new char[strlen(companyName) + 1];
        strcpy(this->companyName, companyName);
    }

    int getPosition() const {
        return position;
    }

    void setPosition(int position) {
        this->position = position;
    }


    friend ostream &operator<<(ostream &os, const User &user) {
        return os << "Username: " << user.username
                  << " Company name: " << user.companyName
                  << " Position: " << user.position;
    }

    friend istream &operator>>(istream &in, User &user) {
        return in >> user.username >> user.companyName >> user.position;
    }

    bool operator==(User &u) {
        return strcmp(this->username, u.username) == 0;
    }
};


class Group{
protected:
        User * clenovi;
        int n;
        char ime[50];
public:
    Group(char * ime=""){
        strcpy(this->ime, ime);
        this->n=0;
        this->clenovi = new User [n];
    }
    ~Group(){
        delete [] clenovi;
    }

    void addMember(User & u){
        for(int i=0;i<n;i++){
            if(clenovi[i]==u){
                throw OperationNotSupported();
            }
        }

        User * tmp = new User[n+1];
        copy(clenovi, clenovi + n , tmp);
        delete [] clenovi;
        tmp[n++]=u;
        clenovi = tmp;
    }

    double rating(){
        double vkupnonivo=0;
        for(int i=0; i<n;i++){
            vkupnonivo+=clenovi[i].getPosition();
        }
        if(n==0){
            return 0;
        }
        return (double)(10-(double)vkupnonivo / n) * n/100;
    }

    friend ostream & operator << (ostream& o, Group & g){
        o<<"Group: "<<g.ime<<endl;
        o<<"Members: "<<g.n<<endl;
        o<<"Rating: "<<g.rating()<<endl;
        o<<"Members list: "<<endl;
        if(g.n==0){
            return o<<"EMPTY"<<endl;
        }
        for(int i=0;i<g.n;i++){
            o<<i+1<<". "<<g.clenovi[i]<<endl;
        }
        return o;
    }
};


class PrivateGroup : public Group{
protected:
    static int capacity;
public:
    PrivateGroup(char * ime=""): Group(ime){
    }

    void addMember(User & u){
        //Exception to do
        if(n+1>getCapacity()){
            throw OperationNotSupport();
        }
        User * tmp = new User[n+1];
        copy(clenovi, clenovi + n , tmp);
        delete [] clenovi;
        tmp[n++]=u;
        clenovi = tmp;
    }
    static void setCapacity(int a){
        PrivateGroup::capacity = a;
    }
    static int getCapacity(){
        return PrivateGroup::capacity;
    }
    double rating(){
        double vkupnonivo=0;
        for(int i=0; i<n;i++){
            vkupnonivo+=clenovi[i].getPosition();
        }
        if(n==0){
            return 0;
        }
        return (double)Group::rating()/PrivateGroup::capacity*80;
    }
    friend ostream & operator << (ostream &os, PrivateGroup & g){
        if(g.n==0){
            os<<"Private Group: "<<g.ime<<endl;
            os<<"Members: "<<g.n<<endl;
            os<<"Rating: "<<g.rating()<<endl;
            os<<"Members list: "<<endl;
            os<<"EMPTY"<<endl;
            return os;
        }
        os<<"Group: "<<g.ime<<endl;
        os<<"Members: "<<g.n<<endl;
        os<<"Rating: "<<g.rating()<<endl;
        os<<"Members list: "<<endl;

        for(int i=0;i<g.n;i++){
            os<<i+1<<". "<<g.clenovi[i]<<endl;
        }
        return os;
    }

};

int PrivateGroup::capacity = 10;




int main() {
    int testCase;
    cin >> testCase;
    if (testCase == 1) {
        cout << "TESTING CLASS GROUP: CONSTRUCTOR AND OPERATOR <<" << endl;
        Group g("test");
        cout << g;
    } else if (testCase == 2) {
        cout << "TESTING CLASS PRIVATE GROUP: CONSTRUCTOR AND OPERATOR <<" << endl;
        PrivateGroup pg("private test");
        cout << pg;
    } else if (testCase == 3) {
        cout << "TESTING CLASS GROUP: CONSTRUCTOR, METHOD ADD_MEMBER AND OPERATOR <<" << endl;
        Group *g = new Group("FINKI students");
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            User u;
            cin >> u;
            g->addMember(u);
        }
        cout << *g;
        delete g;
    } else if (testCase == 4) {
        cout << "TESTING CLASS PRIVATE_GROUP: CONSTRUCTOR, METHOD ADD_MEMBER AND OPERATOR <<" << endl;
        PrivateGroup *g = new PrivateGroup("FINKI students");
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            User u;
            cin >> u;
            g->addMember(u);
        }
        cout << *g;
        delete g;
    } else if (testCase == 5) {
        cout << "TESTING CLASS GROUP: CONSTRUCTOR, METHOD ADD_MEMBER, EXCEPTION AND OPERATOR <<" << endl;
        Group *g = new Group("FINKI students");
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            User u;
            cin >> u;
            try {
                g->addMember(u);
            } catch (OperationNotSupported &e) {
                e.showMessage();
            }
        }
        cout << *g;
        delete g;
    } else if (testCase == 6) {
        cout << "TESTING CLASS PRIVATE GROUP: CONSTRUCTOR, METHOD ADD_MEMBER, EXCEPTION AND OPERATOR <<" << endl;
        PrivateGroup *g = new PrivateGroup("FINKI");
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            User u;
            cin >> u;
            try {
                g->addMember(u);
            } catch (OperationNotSupported e) {
                e.showMessage();
            }
            catch (OperationNotSupport e) {
                e.showMessage();
            }
        }
        cout << *g;
        delete g;
    } else if (testCase == 7) {
        cout << "TESTING CLASS PRIVATE GROUP: CONSTRUCTOR, METHOD ADD_MEMBER AND CHANGE OF STATIC MEMBER"
             << endl;
        PrivateGroup *g = new PrivateGroup("FINKI");
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            User u;
            cin >> u;
            g->addMember(u);
        }
        cout << "RATING BEFORE CHANGE" << endl;
        cout << g->rating();
        PrivateGroup::setCapacity(20);
        cout << "RATING AFTER CHANGE" << endl;
        cout << g->rating();
        delete g;
    }
    else if (testCase==8) {
        cout << "TESTING CLASS PRIVATE GROUP: CONSTRUCTOR, METHOD ADD_MEMBER, EXCEPTION AND CHANGE OF STATIC MEMBER"
             << endl;

        PrivateGroup *g = new PrivateGroup("FINKI");
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            User u;
            cin >> u;
            try {
                g->addMember(u);
            }
            catch (OperationNotSupported e) {
                e.showMessage();
            }
             catch (OperationNotSupport & e) {
                int capacity = PrivateGroup::getCapacity();
                cout<<"Increasing capacity from "<<capacity<<" to "<<capacity+1<<endl;
                PrivateGroup::setCapacity(capacity+1);
                g->addMember(u);
                cout<<g->rating()<<endl;
            }
        }

    }else {
        cout<<"INTEGRATION TEST"<<endl;
        char name [50];
        int nGroups;
        cin>>nGroups;
        Group ** groups = new Group * [nGroups];
        for (int i=0;i<nGroups;i++) {
            int type;
            cin>>type;
            cin>>name;
            if (type==1) { //normal group
                groups[i] = new Group(name);
            } else { //private group
                groups[i] = new PrivateGroup(name);
            }
            int nUsers;
            cin>>nUsers;
            for (int j=0;j<nUsers;j++) {
                User u;
                cin>>u;
                try {
                    groups[i]->addMember(u);
                } catch (OperationNotSupported e) {
                    e.showMessage();
                }
                  catch (OperationNotSupport e) {
                    e.showMessage();
                }
            }
        }

        cout<<"BEFORE CHANGE OF PRIVATE GROUP COEFFICIENT"<<endl;
        for (int i = 0; i < nGroups; ++i) {
            cout<<*groups[i];
        }
        PrivateGroup::setCapacity(15);
        cout<<"AFTER CHANGE OF PRIVATE GROUP COEFFICIENT"<<endl;
        for (int i = 0; i < nGroups; ++i) {
            cout<<*groups[i];
        }
    }
}
