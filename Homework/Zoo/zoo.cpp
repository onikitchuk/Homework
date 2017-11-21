#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;


class Animal {
public:
    const int NAME_LENGTH = 20;

    int age;
    char* kind;
    char* name;
    int pawsNum;
    int health;
    bool isShow;

    Animal(char* name, char* kind, int health, int pawsNum){
        this->name = name;
        this->kind = kind;
        this->health = health;
        this->pawsNum = pawsNum;
    }
};

class Zoo{
public:
    Zoo(){

        int health = 100;
        int pawsNum = 4;

         for(int i = 0; i < 2; i++){

            char* name = new char[20];
            char* kind = new char[20];

            animals[i] = new Animal(name, kind, health, pawsNum);

            cout<<"Enter the name of animal"<<endl;
            cin.getline(name, 20);
            cout<<"Enter the kind of animal"<<endl;
            cin.getline(kind, 20);
            cout<<""<<endl;

            cout<<"---------------------------------------------"<<endl;
            cout<<"Add new animal. name = "
            <<animals[i]->name
            <<" kind = "<<animals[i]->kind
            <<" health = "<<animals[i]->health
            <<" pawsNum = "<<animals[i]->pawsNum
            <<endl;
            cout<<""<<endl;

        }
    }
    Animal* animals[50];
};

int main(){
    Zoo z;
}
