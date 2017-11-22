#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

class Animal{
    private:
        string name;
        string kind;
        int age;
        int pawsNum;
        int health;
        bool isPresent;

    public:
        Animal(){
            name = "No name";
            kind = "No kind";
            age = 0;
            pawsNum = 0;
            health = 0;
            isPresent = false;

        };

        void setAnimal(){

            cout<<"Enter the name of the animal"<<endl;
            getline(cin, name);
            getline(cin, name);

            cout<<"Enter the kind of animal"<<endl;
            getline(cin, kind);

            cout<<"Enter the age of the animal"<<endl;
            cin >> age;

            cout<<"Enter the number of paws of the animal"<<endl;
            cin >> pawsNum;

            cout<<"Animal health status "<<"%"<<endl;
            cin >> health;

            cout<<"Is animal in show? 1 / 0"<<endl;
            cin >> isPresent;
        }

       void getAnimal(){
            cout<<"--------------------------------"<<endl;
            cout<< "Name: "<< name<<endl;
            cout<< "Kind: "<< kind<<endl;
            cout<< "Age : "<<age<<endl;
            cout<< "Number of paws: "<< pawsNum<<endl;
            cout<< "Health: "<< health<<"%"<<endl;

            if(isPresent == 1){
                cout<<"This animal is present in the show"<<endl;
            }
            if(isPresent == 0){
                cout<<"This animal is absent"<<endl;
            }
                cout<<"--------------------------------"<<endl;
            }
        ~Animal(){
            cout<<"Destructor works"<<endl;
        }
};

class Zoo{
    private:
        Animal arrayOfAnimals[100];
        int sizeOfArrayOfAnimals;
        int deleteAnimalFromArray;
    public:
        int countOfAnimals = 0;
        Zoo(){ sizeOfArrayOfAnimals = 0;};

        void showAnimal(){
            cout<<"******************"<<endl;
            cout<<"--- Population ---"<<endl<<endl;
            if(countOfAnimals == 0){
                cout<<"No animals in population"<<endl;
            }
            cout<<"--------------------------------"<<endl;
            cout<<"Number of animals - "<<countOfAnimals<<endl;
            for (int i = 0; i < sizeOfArrayOfAnimals; i++){
                arrayOfAnimals[i].getAnimal();
                cout<<endl;
            }
        }
        void addAnimal(){
            arrayOfAnimals[sizeOfArrayOfAnimals].setAnimal();
            sizeOfArrayOfAnimals++;
            countOfAnimals++;
        }
        void deleteAnimal(){
            for(int i = 0; i < sizeOfArrayOfAnimals; i++){
                arrayOfAnimals[i].getAnimal();
                cout<<endl;
            }
            cout<<"Which animal you want to delete?"<<endl;
            cout<<"Select its index in the array:"<<endl;
            cin >> deleteAnimalFromArray;
            Animal operatingArray[100];

            int indexDeletedAnimal = 0;

            for(int i = 0; i < sizeOfArrayOfAnimals; i++){
                if (i != deleteAnimalFromArray){
                    operatingArray[indexDeletedAnimal] = arrayOfAnimals[i];
                    indexDeletedAnimal++;
                }
            }
            sizeOfArrayOfAnimals--;
            for (int i = 0; i < sizeOfArrayOfAnimals; i++){
                arrayOfAnimals[i] = operatingArray[i];
            }
            countOfAnimals--;
        }
};

class Manager{
    private:
        int choiceOfAction;
    int GetUserChoice(){
        cin >> choiceOfAction;
        switch(choiceOfAction){
            case 1:
                Z.showAnimal();
                break;
            case 2:
                Z.addAnimal();
                break;
            case 3:
                Z.deleteAnimal();
                break;
            case 4:
                return 4;
                break;
            }
        }
    public:
        Zoo Z;
        int k = 1;
        int a;
        int showUserMenu(){
            do{
                cout<<""<<endl;
                cout<<"--- Users menu ---"<<endl<<endl;
                cout<<"1. View population"<<endl;
                cout<<"2, Add an animal"<<endl;
                cout<<"3. Delete the animal"<<endl;
                cout<<"4. Finish work"<<endl;
                a = GetUserChoice();
                if(a == 4){
                    k = 0;
                }
            } while (k);
              return 1;
        }
};

int main(){
    Manager M;
    if (M.showUserMenu() == 0)
        return 0;
}
