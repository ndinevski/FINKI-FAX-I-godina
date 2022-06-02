//https://i.imgur.com/gvoG5LI.png
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

class Image{
    protected:
        char * ime;
        char coek[50];
        int sirina;
        int visina;
        // void cpys(const Image & o){
        //     this->ime = new char[strlen(o.ime)+1];
        //     strcpy(this->ime,o.ime);
        //     strcpy(this->coek,o.coek);
        //     this->sirina = o.sirina;
        //     this->visina =o.visina;
        // }
    public:
        Image(const char * ime="untitled", const char * coek="unknown", const int sirina=800,const  int visina=800){
            this->ime = new char[strlen(ime)+1];
            strcpy(this->ime,ime);
            strcpy(this->coek,coek);
            this->sirina = sirina;
            this->visina = visina;
        }

        // Image(const Image & other){
        //     cpys(other);
        // }
        // Image & operator=(const Image & other){
        //     if(this != &other){
        //         delete [] ime;
        //         cpys(other);
        //     }
        //     return *this;
        // }

        virtual int fileSize(){
            return visina*sirina*3;
        }
        friend ostream & operator << (ostream & o , Image & i){
            o<<i.ime<<" "<<i.coek<<" "<<i.fileSize()<<endl;
            return o;
        }
        
};


class TransparentImage: public Image{
    protected:
        bool transparent;
       
    public:
        TransparentImage(const char * ime="untitled", const char * coek="unknown", const int sirina=800,const  int visina=800, bool transparent= true): Image(ime,coek, sirina, visina){
            this->transparent= transparent;
        }
        // TransparentImage(const TransparentImage & other): Image(other){
        //     this->transparent = other.transparent;
        // }
        int fileSize() override{
            if(transparent){
                return visina*sirina*4;
            }
            return (visina*sirina + (visina*sirina)/8);
            
        }
        friend ostream & operator << (ostream & o , TransparentImage & i){
            o<<i.ime<<" "<<i.coek<<" "<<i.fileSize()<<endl;
            return o;
        }

};




class Folder{
    protected:
        char imefolder[255];
        char sopstvenik[50];
        Image ** niza;
        int n;
    public:
        Folder(const char * imefolder="", const char * sopstvenik="unknown"){
            strcpy(this->imefolder,imefolder);
            strcpy(this->sopstvenik,sopstvenik);
            this->n=0;
            niza = new Image * [n];
        }
        int folderSize(){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+= niza[i]->fileSize();
            }
            return sum;
        }
        Image * getMaxFile(){
            int max=0, indeks;
            for (int i=0; i<n;i++){
                if(niza[i]->fileSize() > max){
                    max=niza[i]->fileSize();
                    indeks= i;
                }
            }
            return niza[indeks];
        }

        Folder & operator += (Image & nova){
            Image ** tmp = new Image *[n+1];
            copy(niza, niza + n, tmp);
            delete [] niza;
            tmp[n++] = new Image(nova);
            niza = tmp;
            return *this;
        }

        Folder & operator += (TransparentImage & nova){
            Image ** tmp = new Image *[n+1];
            copy(niza, niza + n, tmp);
            delete [] niza;
            tmp[n++] = new TransparentImage(nova);
            niza = tmp;
            return *this;
        }





        friend ostream & operator <<(ostream & o , Folder & f){
            o<<f.imefolder<<" "<<f.sopstvenik<<endl<<"--"<<endl;
            for(int i=0; i<f.n;i++){
                // TransparentImage * casted = dynamic_cast<TransparentImage *>(f.niza[i]);
                // Image *castedd= dynamic_cast<Image *>(f.niza[i]);
                // if(casted){
                //     o<<*casted;
                // }else{
                //     o<<*castedd;
                // }
                o<<*f.niza[i];
            }
            o<<"--"<<endl;
            o<<"Folder size: "<<f.folderSize()<<endl;
            return o;
        }

        Image * operator [] (int i){
            if(i>=n){
                return NULL;
            }
            return niza[i];
        }
};


Folder & max_folder_size(Folder * niza, int n){
    int max=0, indeks;
    for(int i=0;i<n;i++){
        if(niza[i].folderSize()>max){
            max=niza[i].folderSize();
            indeks=i;
        }
    }
    return niza[indeks];
}

























// TODO...

int main() {

    int tc; // Test Case

    char name[255];
    char user_name[51];
    int w, h;
    bool tl;

    cin >> tc;

    if (tc==1){
      // Testing constructor(s) & operator << for class File

      cin >> name;
      cin >> user_name;
      cin >> w;
      cin >> h;


      Image f1;

      cout<< f1;

      Image f2(name);
      cout<< f2;

      Image f3(name, user_name);
      cout<< f3;

      Image f4(name, user_name, w, h);
      cout<< f4;
    }
    else if (tc==2){
      // Testing constructor(s) & operator << for class TextFile
      cin >> name;
      cin >> user_name;
      cin >> w >> h;
      cin >> tl;

      TransparentImage tf1;
      cout<< tf1;

      TransparentImage tf4(name, user_name, w, h, tl);
      cout<< tf4;
    }
    else if (tc==3){
      // Testing constructor(s) & operator << for class Folder
      cin >> name;
      cin >> user_name;

      Folder f3(name, user_name);
      cout<< f3;
    }
    else if (tc==4){
      // Adding files to folder
      cin >> name;
      cin >> user_name;

      Folder dir(name, user_name);

      Image * f;
      TransparentImage *tf;

      int sub, fileType;

      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;

        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          f = new Image(name,user_name, w, h);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          cin >> tl;
          tf = new TransparentImage(name,user_name, w, h, tl);
            dir += *tf;
        }
      }
      cout<<dir;
    }
    else if(tc==5){
      // Testing getMaxFile for folder

      cin >> name;
      cin >> user_name;

      Folder dir(name, user_name);

      Image* f;
      TransparentImage* tf;

      int sub, fileType;

      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;

        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          f = new Image(name,user_name, w, h);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          cin >> tl;
          tf = new TransparentImage(name,user_name, w, h, tl);
            dir += *tf;
        }
      }
      cout<< *(dir.getMaxFile());
    }
    else if(tc==6){
      // Testing operator [] for folder

      cin >> name;
      cin >> user_name;

      Folder dir(name, user_name);

      Image* f;
      TransparentImage* tf;

      int sub, fileType;

      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;

        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          f = new Image(name,user_name, w, h);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          cin >> tl;
          tf = new TransparentImage(name,user_name, w, h, tl);
            dir += *tf;
        }
      }

      cin >> sub; // Reading index of specific file
      cout<< *dir[sub];
    }
    else if(tc==7){
      // Testing function max_folder_size
      int folders_num;

      Folder dir_list[10];

      Folder dir;
      cin >> folders_num;

      for (int i=0; i<folders_num; ++i){
        cin >> name;
        cin >> user_name;
        dir = Folder(name, user_name);


        Image* f;
        TransparentImage *tf;

        int sub, fileType;

        while (1){
          cin >> sub; // Should we add subfiles to this folder
          if (!sub) break;

          cin >>fileType;
          if (fileType == 1){ // Reading File
            cin >> name;
            cin >> user_name;
            cin >> w >> h;
            f = new Image(name,user_name, w, h);
              dir += *f;
          }
          else if (fileType == 2){
            cin >> name;
            cin >> user_name;
            cin >> w >> h;
            cin >> tl;
            tf = new TransparentImage(name,user_name, w, h, tl);
              dir += *tf;
          }
        }
        dir_list[i] = dir;
      }

      cout<<max_folder_size(dir_list, folders_num);
    }
    return 0;
};

