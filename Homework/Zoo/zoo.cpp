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
        char* name = new char[20];
        char* kind = new char[20];
        int health = 100;
        int pawsNum = 4;


         for(int i = 0;i < 50;i++){

            cout<<"Enter the name of animal"<<endl;
            cin.getline(name,20);
            cout<<"Enter the kind of animal"<<endl;
            cin.getline(kind,20);
            cout<<""<<endl;

            animals[i] = new Animal(name, kind, health, pawsNum);

            cout<<"------------------------------------------------------"<<endl;
            cout<<"Add new animal. name = "
            <<animals[i]->name
            <<" kind = "<<animals[i]->kind
            <<" health = "<<animals[i]->health
            <<" pawsNum = "<<animals[i]->pawsNum
            <<endl;
            cout<<""<<endl;
        }
        cout<<animals[0]->name<<" "<<animals[0]->kind<<endl;
        cout<<animals[1]->name<<" "<<animals[1]->kind<<endl;
        delete []name;
        delete []kind;
    }
    Animal* animals[50];
};

int main(){
    Zoo z;
}
