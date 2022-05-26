//https://i.imgur.com/92Cb0k4.png

#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <cmath>
using namespace std;

bool okPassword(char * password){
    int flagu=0,flagl=0,flagd=0;
    for(int i=0;i<strlen(password);i++){
        if(isupper(password[i])){
            flagu=1;
        }
        if(islower(password[i])){
            flagl=1;
        }
        if(isdigit(password[i])){
            flagd=1;
        }
    }
    return flagu && flagl && flagd;
}

bool okEmail(char * email){
    int cnt=0;
    for(int i=0;i<strlen(email);i++){
        if(email[i]=='@'){
            cnt++;
        }
    }
    if(cnt==1){
        return true;
    }
    return false;
}

class MaximumSizeLimit{
    public:
        MaximumSizeLimit(){}
        void message(){
            cout<<"You can't add more than 5 users."<<endl;
        }
};

class InvalidPasswordException{
    public:
        InvalidPasswordException(){}
        void message(){
            cout<<"Password is too weak."<<endl;
        }
};

class InvalidEmailException{
    public:
        InvalidEmailException(){}
        void message(){
            cout<<"Mail is not valid."<<endl;
        }
};


class User{
    protected:
    char username[50];
    char password[50];
    char email[50];
    public:
    User(char *username="", char *password="", char *email=""){
        //throw InvalidPasswordException()
        if(!okPassword(password)){
            throw InvalidPasswordException();
        }
        if(!okEmail(email)){
            throw InvalidEmailException();
        }
        strcpy(this->username, username);
        strcpy(this->password, password);
        strcpy(this->email, email);
    }
    virtual double popularity() = 0;

};

class FacebookUser : public User {
    int friends;
    int likes;
    int comments;
    public:
    FacebookUser(char *username="", char *password="", char *email="",int friends=0, int likes=0, int comments=0):User(username, password, email){
        this->friends = friends;
        this->likes = likes;
        this->comments = comments;
    }
    double popularity(){
        return friends+likes*0.1+comments*0.5;
    }
};      

class TwitterUser : public User {
    int followers;
    int tweets;
    public:
    TwitterUser(char *username="", char *password="", char *email="",int followers=0,int tweets=0):User(username, password, email){
        this->followers = followers;
        this->tweets = tweets;
    }
    double popularity(){
        return followers+0.5*tweets;
    }
};


class SocialNetwork{
    User ** users;
    int n;
    static int MAX_USERS;
    public:
        SocialNetwork(){
            this->n=0;
            this->users = new User * [this->n];
        }
        SocialNetwork(User **users,int n){
            this->n=n;
            this->users = new User * [this->n];
            copy(users,users+n,this->users);
        }
        SocialNetwork & operator +=(User * p){
            if(n+1>MAX_USERS){
                throw MaximumSizeLimit();
            }
            User ** tmp = new User * [n+1];
            copy(users, users + n, tmp);
            delete [] users;
            tmp[n++] = p;
            users= tmp;
            return *this;
        }
        ~SocialNetwork(){
            delete [] users;
        }
        double avgPopularity(){
            double sum=0;
            for(int i=0;i<n;i++){
                sum+=users[i]->popularity();
            }
            return (double)sum/n;
        }
        void changeMaximumSize(int number){
            SocialNetwork::MAX_USERS = number;
        }
};  

int SocialNetwork::MAX_USERS =5;

int main() {

  SocialNetwork network = SocialNetwork();
    int n;
    cin >> n;
    char username[50];
    char password[50];
    char email[50];
    int userType;
    for (int i=0; i < n; ++i) {
      cin >> username;
      cin >> password;
      cin >> email;
      cin >> userType;
      if (userType == 1) {
        int friends;
        int likes;
        int comments;
        cin >> friends >> likes >> comments;
          
        // TODO: Try-catch
        try{
        User * u = new FacebookUser(username,password,email,friends,likes,comments);
        network += u;
        }
        catch(InvalidPasswordException e){
            e.message();
        }
        catch(InvalidEmailException e){
            e.message();
        }
        catch(MaximumSizeLimit e){
            e.message();
        }
      }
      else {
        int followers;
        int tweets;
        cin >> followers >> tweets;
          
        // TODO: Try-catch
        try{  
        User * u= new TwitterUser(username,password,email,followers,tweets);
        network += u;
        }
        catch(InvalidPasswordException e){
            e.message();
        }
        catch(InvalidEmailException e){
            e.message();
        }
        catch(MaximumSizeLimit e){
            e.message();
        }
      }

    }
    network.changeMaximumSize(6);
    cin >> username;
    cin >> password;
    cin >> email;
    int followers;
    int tweets;
    cin >> followers >> tweets;
    try{
    // TODO: Try-catch
    User * u= new TwitterUser(username,password,email,followers,tweets);
    network += u;
    }
    catch (InvalidPasswordException e){
        e.message();
    }
    catch(InvalidEmailException e){
            e.message();
    }
    catch(MaximumSizeLimit e){
            e.message();
        }
    cout << network.avgPopularity();

}
