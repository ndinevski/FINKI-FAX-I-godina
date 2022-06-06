//https://i.imgur.com/LBERuPO.png

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

class NBAPlayer{
    protected:
        char * name;
        char team[40];
        double points;
        double assists;
        double rebounds;
        void cpys(const NBAPlayer & o){
            this->name=new char[strlen(o.name)+1];
            strcpy(this->name, o.name);
            strcpy(this->team, o.team);
            this->points=o.points;
            this->assists=o.assists;
            this->rebounds=o.rebounds;
        }
    public:
        NBAPlayer(char * name="", char * team="", double points=0, double assists=0, double rebounds=0){
            this->name=new char[strlen(name)+1];
            strcpy(this->name, name);
            strcpy(this->team, team);
            this->points=points;
            this->assists=assists;
            this->rebounds=rebounds;
        }
        NBAPlayer(const NBAPlayer & other){
            cpys(other);
        }
        NBAPlayer & operator = (const NBAPlayer & other){
            if(this!=&other){
                delete [] name;
                cpys(other);
            }
            return *this;
        }
        ~NBAPlayer(){
            delete [] name;
        }
        double rating(){
            return 0.45*points+0.3*assists+0.25*rebounds;
        }
        void print(){
            cout<<name<<" - "<<team<<endl;
            cout<<"Points: "<<points<<endl;
            cout<<"Assists: "<<assists<<endl;
            cout<<"Rebounds: "<<rebounds<<endl;
            cout<<"Rating: "<<rating()<<endl;
        }
};

class AllStarPlayer : public NBAPlayer{
    private:
        double ASpoints;
        double ASassists;
        double ASrebounds;
    public:
        AllStarPlayer(NBAPlayer & t, double ASpoints=0, double ASassists=0, double ASrebounds=0) : NBAPlayer(t){
            this->ASpoints=ASpoints;
            this->ASassists=ASassists;
            this->ASrebounds=ASrebounds;
        }

        AllStarPlayer(char * name="", char * team="", double points=0, double assists=0, double rebounds=0, double ASpoints=0, double ASassists=0, double ASrebounds=0) : NBAPlayer(name, team, points, assists, rebounds){
            this->ASpoints=ASpoints;
            this->ASassists=ASassists;
            this->ASrebounds=ASrebounds;
        } 
        
        AllStarPlayer(const AllStarPlayer & other) : NBAPlayer(other){
            this->ASpoints=other.ASpoints;
            this->ASassists=other.ASassists;
            this->ASrebounds=other.ASrebounds;
        }
        AllStarPlayer & operator = (const AllStarPlayer & t){
            if(&t!=this){
                NBAPlayer::operator=(t);
                this->ASpoints=t.ASpoints;
                this->ASassists=t.ASassists;
                this->ASrebounds=t.ASrebounds;
            }
            return *this;
        }
        ~AllStarPlayer(){}
        double allStarRating(){
            return 0.3*ASpoints+0.4*ASassists+0.3*ASrebounds;
        }
        double rating(){
            return (allStarRating() + NBAPlayer::rating())/2.0;
        }
        void print(){
            NBAPlayer::print();
            cout<<"All Star Rating: "<<allStarRating()<<endl;
            cout<<"New Rating: "<<rating()<<endl;
        }
};



int main(){
  char name[50];
  char team[40];
  double points;
  double assists;
  double rebounds;
  double allStarPoints;
  double allStarAssists;
  double allStarRebounds;

  NBAPlayer * players = new NBAPlayer[5];
  AllStarPlayer * asPlayers = new AllStarPlayer[5];
  int n;
  cin >> n;

  if (n == 1) {

    cout << "NBA PLAYERS:" << endl;
    cout << "=====================================" << endl;
    for (int i = 0; i < 5; ++i) {
      cin >> name >> team >> points >> assists >> rebounds;
      players[i] = NBAPlayer(name,team,points,assists,rebounds);
      players[i].print();
    }
  }
  else if (n == 2) {

    for (int i=0; i < 5; ++i){
      cin >> name >> team >> points >> assists >> rebounds;
      cin >> allStarPoints >> allStarAssists >> allStarRebounds;
      players[i] = NBAPlayer(name,team,points,assists,rebounds);
      asPlayers[i] = AllStarPlayer(players[i],allStarPoints,allStarAssists,allStarRebounds);
    }

    cout << "NBA PLAYERS:" << endl;
    cout << "=====================================" << endl;
    for (int i=0; i < 5; ++i)
      players[i].print();

    cout << "ALL STAR PLAYERS:" << endl;
    cout << "=====================================" << endl;
    for (int i=0; i < 5; ++i)
      asPlayers[i].print();

    }
    else if (n == 3) {

      for (int i=0; i < 5; ++i){
        cin >> name >> team >> points >> assists >> rebounds;
        cin >> allStarPoints >> allStarAssists >> allStarRebounds;
        asPlayers[i] = AllStarPlayer(name, team, points, assists, rebounds,
                                     allStarPoints,allStarAssists,allStarRebounds);
      }
      cout << "ALL STAR PLAYERS:" << endl;
      cout << "=====================================" << endl;
      for (int i=0; i < 5; ++i)
        asPlayers[i].print();

    }
    
    delete [] players;
    delete [] asPlayers;
    return 0;
}