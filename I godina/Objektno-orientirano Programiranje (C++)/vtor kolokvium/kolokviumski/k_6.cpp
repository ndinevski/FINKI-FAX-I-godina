//https://i.imgur.com/bHVHZE3.png

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

class ExistingGame{
    public:
        ExistingGame(){}
        void message(){
            cout<<"The game is already in the collection"<<endl;
        }
};


class Game{
    protected:
        char ime[100];
        float cena;
        bool kupena;
    public:
        Game(const char * ime = "",  float cena = 0, bool kupena = false){
            strcpy(this->ime,ime);
            this->cena = cena;
            this->kupena = kupena;
        }
        char * getIme(){
            return ime;
        }
        virtual float getCenas(){
            if (kupena){
                return cena * 0.3;
            }
            return cena;
        }
        friend ostream & operator<<(ostream & o, Game & g){
            o<<"Game: "<<g.ime<<", regular price: $"<<g.cena;
            if(g.kupena){
                o<<", bought on sale";
            }
            return o;
        }
        friend istream & operator >>(istream & i, Game & g){
            i.get();
            i.getline(g.ime,100);
            i>>g.cena>>g.kupena;
            return i;
        }
        float getCena(){
            return cena;
        }

        bool getKupena(){
            return kupena;
        }

        float plus(){
            return 0;
        }

        virtual int getone(){ 
            return 1;
        }

};


class SubscriptionGame: public Game{
    protected:
        float mesecen;
        int m;
        int y;
    public:
        SubscriptionGame(const char * ime = "",  float cena = 0, bool kupena = false, float mesecen = 0, int m = 0, int y=0):Game(ime, cena, kupena){
            this->mesecen = mesecen;
            this->m = m;
            this->y= y;
        }
        friend ostream & operator <<(ostream & o, SubscriptionGame & g){
            o<<"Game: "<<g.ime<<", regular price: $"<<g.cena;
            if(g.kupena){
                o<<", bought on sale";
            }
            o<<", monthly fee: $"<<g.mesecen<<", purchased: ";
            o<<g.m<<"-"<<g.y<<endl;
            return o;
        }
        float getCenas(){
            float price = Game::getCenas();
            int months=0;
            if (y<2018){
            months = (12 - m) + (2017 - y)*12 + 5;
            }
            else {
                months = 5 - m;
            }

            price += months * mesecen;

            return price;
        }
        friend istream & operator >>(istream & i, SubscriptionGame & g){
            i.get();
            i.getline(g.ime,100);
            i>>g.cena>>g.kupena;
            i>>g.mesecen>>g.m>>g.y;
            return i;
        }

        float plus(){
            return (float)mesecen*(m-1);
        }

        int getone(){
            return 1;
        }


};


bool operator == (Game &a , Game & b){
    if(!strcmp(a.getIme(), b.getIme())){
        return true;
    }
    return false;
}


class User{
    protected:
     char user[50];
     Game ** igri;
     int n;
    public:
        User(const char * user=""){
            strcpy(this->user, user);
            this->n=0;
            igri=new Game *[n];
        }

        User & operator += (Game & g){
            for(int i=0;i<n;i++){
                if(*igri[i]==g){
                    throw ExistingGame();
                    return *this;
                }
            }

            Game ** tmp = new Game*[n+1];
            copy(igri,igri+n,tmp);
            delete [] igri;

            SubscriptionGame * sg = dynamic_cast< SubscriptionGame* >(&g);
            if(sg){
                tmp[n++]= new SubscriptionGame (*sg);
            }else{
                tmp[n++]=new Game(g);
            }
            igri = tmp;
            return *this;
        }

    
        float total_spent(){
            float sum = 0;
            for (int i=0; i<n; ++i){
                sum += igri[i]->getCenas();
            }
            return sum;
        }


        friend ostream& operator<<(ostream& o , User & u){
            o<<endl<<"User: "<<u.user<<endl;
            for (int i=0; i < u.n; ++i){
                Game * g;
                SubscriptionGame * sg;
                g = &(u.get_game(i));
                sg = dynamic_cast<SubscriptionGame *> (g);
                if (sg){
                    cout<<"- "<<*sg;
                }else {
                    cout<<"- "<<*g;
                }
                cout<<"\n";
            }
            return o;
        }

        Game & get_game(int i){
            return (*(igri[i]));
        }

        char *get_name(){
            return user;
        }

        int get_games_number(){
            return n;
        }

        ~User(){
            delete [] igri;
        }
};










int main() {
  int test_case_num;

  cin>>test_case_num;

  // for Game
  char game_name[100];
  float game_price;
  bool game_on_sale;

  // for SubscritionGame
  float sub_game_monthly_fee;
  int sub_game_month, sub_game_year;

  // for User
  char username[100];
  int num_user_games;

  if (test_case_num == 1){
    cout<<"Testing class Game and operator<< for Game"<<std::endl;
    cin.get();
    cin.getline(game_name,100);
    //cin.get();
    cin>>game_price>>game_on_sale;

    Game g(game_name, game_price, game_on_sale);

    cout<<g;
  }
  else if (test_case_num == 2){
    cout<<"Testing class SubscriptionGame and operator<< for SubscritionGame"<<std::endl;
    cin.get();
    cin.getline(game_name, 100);

    cin>>game_price>>game_on_sale;

    cin>>sub_game_monthly_fee;
    cin>>sub_game_month>>sub_game_year;

    SubscriptionGame sg(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
    cout<<sg;
  }
  else if (test_case_num == 3){
    cout<<"Testing operator>> for Game"<<std::endl;
    Game g;

    cin>>g;

    cout<<g;
  }
  else if (test_case_num == 4){
    cout<<"Testing operator>> for SubscriptionGame"<<std::endl;
    SubscriptionGame sg;

    cin>>sg;

    cout<<sg;
  }
  else if (test_case_num == 5){
    cout<<"Testing class User and operator+= for User"<<std::endl;
    cin.get();
    cin.getline(username,100);
    User u(username);

    int num_user_games;
    int game_type;
    cin >>num_user_games;

    try {

      for (int i=0; i<num_user_games; ++i){

        cin >> game_type;

        Game *g;
        // 1 - Game, 2 - SubscriptionGame
        if (game_type == 1){
          cin.get();
          cin.getline(game_name, 100);

          cin>>game_price>>game_on_sale;
          g = new Game(game_name, game_price, game_on_sale);
        }
        else if (game_type == 2){
          cin.get();
          cin.getline(game_name, 100);

          cin>>game_price>>game_on_sale;

          cin>>sub_game_monthly_fee;
          cin>>sub_game_month>>sub_game_year;
          g = new SubscriptionGame(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
        }

        //cout<<(*g);


        u+=(*g);
      }
    }catch(ExistingGame &ex){
      ex.message();
    }

    cout<<u;

//    cout<<"\nUser: "<<u.get_username()<<"\n";

//    for (int i=0; i < u.get_games_number(); ++i){
//        Game * g;
//        SubscriptionGame * sg;
//        g = &(u.get_game(i));

//        sg = dynamic_cast<SubscriptionGame *> (g);

//        if (sg){
//          cout<<"- "<<(*sg);
//        }
//        else {
//          cout<<"- "<<(*g);
//        }
//        cout<<"\n";
//    }

  }
  else if (test_case_num == 6){
      cout<<"Testing exception ExistingGame for User"<<endl;
      cin.get();
      cin.getline(username,100);
      User u(username);

      int num_user_games;
      int game_type;
      cin >>num_user_games;

      for (int i=0; i<num_user_games; ++i){

          cin >> game_type;

          Game *g;
          // 1 - Game, 2 - SubscriptionGame
          if (game_type == 1){
            cin.get();
            cin.getline(game_name, 100);

            cin>>game_price>>game_on_sale;
            g = new Game(game_name, game_price, game_on_sale);
          }
          else if (game_type == 2){
            cin.get();
            cin.getline(game_name, 100);

            cin>>game_price>>game_on_sale;

            cin>>sub_game_monthly_fee;
            cin>>sub_game_month>>sub_game_year;
            g = new SubscriptionGame(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
          }

          //cout<<(*g);

          try {
            u+=(*g);
          }
          catch(ExistingGame &ex){
            ex.message();
          }
        }

      cout<<u;

//      for (int i=0; i < u.get_games_number(); ++i){
//          Game * g;
//          SubscriptionGame * sg;
//          g = &(u.get_game(i));

//          sg = dynamic_cast<SubscriptionGame *> (g);

//          if (sg){
//            cout<<"- "<<(*sg);
//          }
//          else {
//            cout<<"- "<<(*g);
//          }
//          cout<<"\n";
//      }
  }
  else if (test_case_num == 7){
      cout<<"Testing total_spent method() for User"<<std::endl;
      cin.get();
      cin.getline(username,100);
      User u(username);

      int num_user_games;
      int game_type;
      cin >>num_user_games;

      for (int i=0; i<num_user_games; ++i){

          cin >> game_type;

          Game *g;
          // 1 - Game, 2 - SubscriptionGame
          if (game_type == 1){
            cin.get();
            cin.getline(game_name, 100);

            cin>>game_price>>game_on_sale;
            g = new Game(game_name, game_price, game_on_sale);
          }
          else if (game_type == 2){
            cin.get();
            cin.getline(game_name, 100);

            cin>>game_price>>game_on_sale;

            cin>>sub_game_monthly_fee;
            cin>>sub_game_month>>sub_game_year;
            g = new SubscriptionGame(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
          }

          //cout<<(*g);


          u+=(*g);
        }

      cout<<u;

      cout<<"Total money spent: $"<<u.total_spent()<<endl;
  }
}

