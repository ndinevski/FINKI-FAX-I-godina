//https://i.imgur.com/sthgqZ3.png

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

enum Extension{
    pdf,
    txt,
    exe
};

class File{
    char * name;
    Extension e;
    char * owner;
    int filesize;
    void cpy(const File & f){
        this->name = new char[strlen(f.name)+1];
        strcpy(this->name, f.name);
        this->owner = new char [strlen(f.owner)+1];
        strcpy(this->owner, f.owner);
        this->filesize=f.filesize;
        this->e=f.e;
    }
public:
    File(char * name="", char * owner="", int filesize=0, Extension e=pdf){
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        this->owner = new char [strlen(owner)+1];
        strcpy(this->owner, owner);
        this->filesize=filesize;
        this->e=e;
    }
    File(const File & f){
        cpy(f);
    }
    File & operator = (const File & f){
        if(&f!=this){
            delete [] name;
            delete [] owner;
            cpy(f);
        }
        return *this;
    }
    ~File(){
        delete [] name;
        delete [] owner;
    }
    void print(){
        cout<<"File name: "<<name<<".";
        if(e==0){
            cout<<"pdf";
        }else if(e==1){
            cout<<"txt";
        }else{
            cout<<"exe";
        }
        cout<<endl<<"File owner: "<<owner<<endl;
        cout<<"File size: "<<filesize<<endl;
    }
    bool equals(const File & that){
        return ((strcmp(this->name, that.name)==0) && (strcmp(this->owner,that.owner)==0) && this->e==that.e);
    }
    bool equalsType(const File & that){
        return (strcmp(this->name, that.name)==0 && this->e==that.e);
    }
};

class Folder{
    char * name;
    int n;
    File * files;
    void cpy(const Folder & f){
        this->n=f.n;
        this->files=new File[f.n];
        copy(f.files,f.files + f.n,this->files);
        this->name = new char[strlen(f.name)+1];
        strcpy(this->name, f.name);
    }
public:
    Folder(const char* name=""){
        this->n=0;
        this->files=nullptr;
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
    }
    Folder(const Folder & f){
        cpy(f);
    }
    Folder & operator = (const Folder & f){
        if(&f!=this){
            delete [] name;
            delete [] files;
            cpy(f);
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
    void add(const File & file){
        File * tmp;
        tmp = new File[n+1];
        copy(files,files+n,tmp);
        delete [] files;
        files = new File[n+1];
        tmp[n++]=file;
        files = tmp;
    }
    void remove(const File & file){
        File * tmp;
        tmp = new File[n-1];
        for(int i=0;i<n;i++){
            if(files[i].equals(file)){
                for(int j=i;j<n-1;j++){
                    tmp[j]=files[j];
                }
                break;
            }else{
                tmp[i]=files[i];
            }
        }
        delete [] files;
        files = new File[n-1];
        files=tmp;
        n--;
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
		cout << "======= FILE EQUALS & EQUALS TYPE =======" << endl;
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

		bool equalsType = first.equalsType(second);
		cout << "FIRST EQUALS TYPE SECOND: ";
		if (equalsType)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

		equalsType = second.equals(third);
		cout << "SECOND EQUALS TYPE THIRD: ";
		if (equalsType)
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
