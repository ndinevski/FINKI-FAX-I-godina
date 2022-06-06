//https://i.imgur.com/EGaRqNQ.png

#include <iostream>
#include <cstring>
using namespace std;
enum Extension{
    pdf,
    txt,
    exe
};

class File{
    char * name;
    Extension t;
    char * owner;
    int filesize;
    void copy(const File & f){
        this->name=new char [strlen(f.name)+1];
        this->t=(Extension)f.t;
        this->owner=new char [strlen(f.owner)+1];
        this->filesize=f.filesize;
        strcpy(this->name, f.name);
        strcpy(this->owner, f.owner);
    }
public:
    File(char * name="", char * owner="", int filesize=0, Extension t=pdf){
        this->name=new char [strlen(name)+1];
        this->t=t;
        this->owner=new char [strlen(owner)+1];
        this->filesize=filesize;
        strcpy(this->name, name);
        strcpy(this->owner, owner);
    }
    File(const File & f){
        copy(f);
    }

    File & operator = (const File & f){
        if(&f!=this){
            delete [] name;
            delete [] owner;
            copy(f);
        }
        return *this;
    } 

    ~File(){
        delete [] name;
        delete [] owner;
    }

    void print(){
        cout<<"File name: "<<name<<".";
        if(t==0){
            cout<<"pdf";
        }else if(t==1){
            cout<<"txt";
        }else if(t==2){
            cout<<"exe";
        }
        cout<<endl<<"File owner: "<<owner<<endl;
        cout<<"File size: "<<filesize<<endl;
    }

    bool equals(const File & that){
        return ((strcmp(this->name,that.name)==0) && (strcmp(this->owner,that.owner)==0) && this->t==that.t);
    }
    bool equalsExtension(const File & that){
        return ((strcmp(this->name,that.name)==0) && this->t==that.t);
    }

};

class Folder{
    char * name;
    int n;
    File * files;
    void copy(const Folder & f){
        this->name=new char[strlen(f.name)+ 1];
        strcpy(this->name, f.name);
        this->n=f.n;
        this->files=new File[this->n];
        for(int i=0;i<this->n;i++){
            this->files[i]=f.files[i];
        }
    }
public:
    Folder(char * name=""){
        this->name=new char[strlen(name)+ 1];
        strcpy(this->name, name);
        this->n=0;
        this->files=new File[n];
    }
    Folder(const Folder & f){
        copy(f);
    }
    Folder & operator = (const Folder & f){
        if(this!=&f){
            delete [] name;
            delete [] files;
            copy(f);
        }
        return *this;
    }
    ~Folder(){
        delete [] name;
        delete [] files;
    }
    void print(){
        cout<<"Folder name: "<<name<<endl;
        for(int i=0;i<n;i++){
            files[i].print();
        }
    }
    void remove(const File & file){
        for (int i=0; i<n; i++) {
            if (files[i].equals(file)) {
                --n;
                for (int j=i; j<n; j++) {
                    files[j] = files[j + 1];
                }
                break;
            }
        }
    }
    void add(const File & file){
        File * tmp = new File[n+1];
        for(int i=0;i<n;i++){
            tmp[i]=files[i];
        }
        tmp[n++]=file;
        delete [] files;
        files = tmp;
    }
};

int main() {
	char fileName[20];
	char fileOwner[20];
	int ext;
	int fileSize;

	int testCase;
	cin >> testCase;
	if (testCase == 1) {
		cout << "======= FILE CONSTRUCTORS AND = OPERATOR =======" << endl;
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File created = File(fileName, fileOwner, fileSize, (Extension) ext);
		File copied = File(created);
		File assigned = created;

		cout << "======= CREATED =======" << endl;
		created.print();
		cout << endl;
        cout << "======= COPIED =======" << endl;
		copied.print();
		cout << endl;
        cout << "======= ASSIGNED =======" << endl;
		assigned.print();
	}
	else if (testCase == 2) {
		cout << "======= FILE EQUALS AND EQUALS TYPE =======" << endl;
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File first(fileName, fileOwner, fileSize, (Extension) ext);
		first.print();

		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;	

		File second(fileName, fileOwner, fileSize, (Extension) ext);
		second.print();

		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File third(fileName, fileOwner, fileSize, (Extension) ext);
		third.print();

		bool equals = first.equals(second);
		cout << "FIRST EQUALS SECOND: ";
		if (equals)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

		equals = first.equals(third);
		cout << "FIRST EQUALS THIRD: ";
		if (equals)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

		bool equalsExtension = first.equalsExtension(second);
		cout << "FIRST EQUALS TYPE SECOND: ";
		if (equalsExtension)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

		equalsExtension = second.equals(third);
		cout << "SECOND EQUALS TYPE THIRD: ";
		if (equalsExtension)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

	}
	else if (testCase == 3) {
		cout << "======= FOLDER CONSTRUCTOR =======" << endl;
		cin >> fileName;
		Folder folder(fileName);
		folder.print();

	}
	else if (testCase == 4) {
		cout << "======= ADD FILE IN FOLDER =======" << endl;
		char name[20];
		cin >> name;
		Folder folder(name);

		int iter;
		cin >> iter;

		while (iter > 0) {
			cin >> fileName;
			cin >> fileOwner;
			cin >> fileSize;
			cin >> ext;

			File file(fileName, fileOwner, fileSize, (Extension) ext);
			folder.add(file);
			iter--;
		}
		folder.print();
	}
	else {
		cout << "======= REMOVE FILE FROM FOLDER =======" << endl;
		char name[20];
		cin >> name;
		Folder folder(name);

		int iter;
		cin >> iter;

		while (iter > 0) {
			cin >> fileName;
			cin >> fileOwner;
			cin >> fileSize;
			cin >> ext;

			File file(fileName, fileOwner, fileSize, (Extension) ext);
			folder.add(file);
			iter--;
		}
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File file(fileName, fileOwner, fileSize, (Extension) ext);
		folder.remove(file);
		folder.print();
	}
	return 0;
}