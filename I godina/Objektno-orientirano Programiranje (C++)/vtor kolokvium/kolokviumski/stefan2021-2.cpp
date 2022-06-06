//https://i.imgur.com/L2YUGBI.png

#include<cstring>
#include<iostream>
#include <algorithm>
#include <cctype>
using namespace std;

class MediaSegment{
protected:
    char naslov[100];
    char avtor[100];
    int sekundi;
    int golemina;
public:
   MediaSegment(char * naslov = "", char * avtor = "", int sekundi=0, int golemina=0){
        strcpy(this->naslov, naslov);
        strcpy(this->avtor, avtor);
        this->sekundi=sekundi;
        this->golemina = golemina;
   }
   virtual float price() const= 0;

};


class AudioRecording: virtual public MediaSegment{
protected:
    short format;
    short channels;
public:
    AudioRecording(char * naslov = "", char * avtor = "", int sekundi=0, int golemina=0, short format=0, short channels=0): MediaSegment(naslov, avtor, sekundi, golemina){
        this->format=format;
        this->channels=channels;
    }
    float price() const{
        if(format==3){
            return 1.5*sekundi*channels;
        }
        return 1.0*sekundi*channels;
    }

    friend ostream & operator <<(ostream & o, AudioRecording & a){
        return o<<a.naslov<<" - "<<a.avtor<<" - "<<a.sekundi<<" - "<<a.golemina<<" - "<<a.price()<<endl;
    }
};


class VideoRecording: virtual public MediaSegment{
protected:
    short sirina;
    short compression;
public:
    VideoRecording(char * naslov = "", char * avtor = "", int sekundi=0, int golemina=0, short sirina=0, short compression=0): MediaSegment(naslov, avtor, sekundi, golemina){
        this->sirina=sirina;
        this->compression=compression;
    }
    float price() const{
        if(sirina <=1920){
            if(compression==0){
                return 1.5*sekundi*100;
            }else if(compression==1){
                return 0.9*sekundi*100;
            }
            return sekundi*100.0;
        }else{
            if(compression==0){
                return 1.5*sekundi*170;
            }else if(compression==1){
                return 0.9*sekundi*170;
            }
            return sekundi*170.0;
        }
    }

    friend ostream & operator <<(ostream & o, VideoRecording & a){
        return o<<a.naslov<<" - "<<a.avtor<<" - "<<a.sekundi<<" - "<<a.golemina<<" - "<<a.sirina<<" - "<<a.price()<<endl;
    }
};

class MusicVideo: public AudioRecording , public VideoRecording {
private:
    char date[9];
public:
    MusicVideo(char * naslov = "", char * avtor = "", int sekundi=0, int golemina=0, short format=0, short channels=0, short sirina=0, short compression=0, char * date="") :
        MediaSegment(naslov, avtor, sekundi, golemina){
        this->format= format;
        this->channels = channels;
        this->sirina = sirina;
        this->compression = compression;
        strcpy(this->date, date);
    }

    float price()const {
        if(date[6]=='1' || date[6]=='2'){
            return (AudioRecording::price() + VideoRecording::price())*1.3;
        }
        return (float)(AudioRecording::price() + VideoRecording::price());
    }

    friend ostream & operator <<(ostream & o, MusicVideo & a){
        return o<<a.AudioRecording::naslov<<" - "<<a.AudioRecording::avtor<<" - "<<a.date<<" - "<<a.AudioRecording::sekundi<<" - "<<a.price()<<endl;
    }
};


float total_price(MediaSegment ** niza, int n){
    float totalprice=0;
    for(int i=0;i<n;i++){
        totalprice+= niza[i]->price();
    }
    return totalprice;
}

MusicVideo & cheapest_music_video(MediaSegment ** niza, int n){
    MusicVideo * tmp=nullptr;
    for(int i=0;i<n;i++){
        MusicVideo * casted = dynamic_cast<MusicVideo *>(niza[i]);
        if(casted!=0){
            if(tmp==nullptr){
                tmp=casted;
            }else if(casted->price() < tmp->price()){
                tmp=casted;
            }
        }
    }

    return *tmp;
}



int main() {

  int test_case_num;
  cin>>test_case_num;


  // for MediaSegment
  char title[100];
  char author[1000];
  unsigned int size;
  unsigned int duration;


  // for AudioRecording
  //-------------------
  unsigned short channels;

  // AudioFormat:
  // 0 - mp3
  // 1 - wav
  // 2 - ogg
  // 3 - flac
  unsigned short format;


  // for VideoRecording
  //-------------------
  unsigned short width;

  // VideoCompression:
  // 0 - x264
  // 1 - Theora
  // 2 - AV1
  int compression;


  // for MusicVideo
  //-------------------
  char publication_date[9];


  if (test_case_num == 1){
    cout<<"Testing class AudioRecording and operator<<"<<std::endl;
    cin.get();
    cin.getline(title,100);
    cin.getline(author, 100);
    //cin.get();
    cin >> duration >> size;
    cin >> format >> channels;

    AudioRecording a(title, author, duration, size, format, channels);

    cout<<a;

  }

  else if (test_case_num == 2){
    cout<<"Testing class VideoRecording and operator<<"<<std::endl;
    cin.get();
    cin.getline(title,100);
    cin.getline(author, 100);
    //cin.get();
    cin >> duration >> size;
    cin >> width >> compression;

    VideoRecording v(title, author, duration, size, width, compression);

    cout<<v;

  }

  else if (test_case_num == 3){
    cout<<"Testing class MusicVideo and operator<<"<<std::endl;

    cin.get();
    cin.getline(title,100);
    cin.getline(author, 100);
    //cin.get();
    cin >> duration >> size;

    cin >> format >> channels;
    cin >> width >> compression;

    cin.get();
    cin.getline(publication_date, 9);
    MusicVideo mv(title, author, duration, size, format, channels, width, compression, publication_date);

    cout << mv;
  }

  else if (test_case_num == 4){
    cout<<"Testing function: total_price "<<std::endl;

    MediaSegment ** m;

    int num_media_segments;
    cin >> num_media_segments;

    // 1 - AudioRecording
    // 2 - VideoRecording
    // 3 - MusicVideo
    short media_type;

    m = new MediaSegment*[num_media_segments];

    for (int i=0; i<num_media_segments; i++) {

      cin >> media_type;

      cin.get();
      cin.getline(title,100);
      cin.getline(author, 100);
      //cin.get();
      cin >> duration >> size;

      switch(media_type) {
      case 1:
              cin >> format >> channels;
              m[i] = new AudioRecording(title, author, duration, size, format, channels);
          break;
      case 2:
              cin >> width >> compression;
              m[i] = new VideoRecording(title, author, duration, size, width, compression);
          break;
      case 3:
              cin >> format >> channels;
              cin >> width >> compression;
              cin.get();
              cin.getline(publication_date, 9);
              m[i] = new MusicVideo(title, author, duration, size, format, channels, width, compression, publication_date);
          break;
      }
    }

    //for (int i=0;i<num_media_segments; i++){
    //    cout << *m[i];
    //}

    cout<< "Total price is: " << total_price(m, num_media_segments);

    delete [] m;

  }
  else if (test_case_num == 5){
    cout<<"Testing function: cheapest_music_video "<<std::endl;

    MediaSegment ** m;

    int num_media_segments;
    cin >> num_media_segments;

    // 1 - AudioRecording
    // 2 - VideoRecording
    // 3 - MusicVideo
    short media_type;

    m = new MediaSegment*[num_media_segments];

    for (int i=0; i<num_media_segments; i++) {

      cin >> media_type;

      cin.get();
      cin.getline(title,100);
      cin.getline(author, 100);
      //cin.get();
      cin >> duration >> size;

      switch(media_type) {
      case 1:
              cin >> format >> channels;
              m[i] = new AudioRecording(title, author, duration, size, format, channels);
          break;
      case 2:
              cin >> width >> compression;
              m[i] = new VideoRecording(title, author, duration, size, width, compression);
          break;
      case 3:
              cin >> format >> channels;
              cin >> width >> compression;
              cin.get();
              cin.getline(publication_date, 9);
              m[i] = new MusicVideo(title, author, duration, size, format, channels, width, compression, publication_date);
          break;
      }
    }

    cout<<cheapest_music_video(m, num_media_segments);

    delete [] m;
  }

  return 0;
}
