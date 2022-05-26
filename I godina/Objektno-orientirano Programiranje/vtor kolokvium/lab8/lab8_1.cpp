//https://i.imgur.com/ceNVHtu.png

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual void draw() {
        cout << "Drawing a shape.\n";
    }
};

// креирајте класа Rectangle која наследува од Shape 
class Rectangle : public Shape {
    public:
        void draw(){
            cout<<"Drawing a rectangle.\n";
        }
};
    // во неа препокријте ја функцијата draw() така што ќе се испечати: "Drawing a rectangle.\n"


int main() {
    Shape* shape;

    // тука инстанцирајте објект од класата Shape и покажувачот shape нека покажува кон него
    Shape obj;
    shape = &obj;
    shape->draw();

    // сега инстанцирајте објект од класата Rectangle и покажувачот shape нека покажува кон него
    Rectangle obj1;
    shape = &obj1;
    // повторно повикајте ја функцијата draw() на shape
    shape->draw();
    return 0;
}

