#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

class ArrayList{
private:
    int* array;
    int currentSize;
    int allocatedSize;
    int sz;

     void addItemToUnfilledArray(int n){
        array[currentSize] = n;
        currentSize++;
        return;
    }

    void addItemToFullArray(int n){
        int* newArray = new int[allocatedSize*2];
        allocatedSize *= 2;

        for (int i = 0; i < currentSize; i++){
            newArray[i] = array[i];
        }

        delete []array;
        array = newArray;

        cout<<endl;cout<<endl;
        cout<<"The array is enlarged 2 times after the original array size is exceeded"<<endl;
        addItemToUnfilledArray(n);
    }

public:
    ArrayList(){
        array = new int[0];
        currentSize = 0;
        allocatedSize = 0;
    }

    ArrayList(int sz){
        array = new int[sz];
        currentSize = 0;
        allocatedSize = sz;
        for ( int i = 0; i < sz; i++ ){
            array[i] = 0;
        }
    }

        void add(int n){
            if(currentSize < allocatedSize){
                addItemToUnfilledArray(n);
            } else {
               addItemToFullArray(n);
            }
        }

        void addToIndex(int index, int n){
            cout<<endl;
            if(currentSize < allocatedSize){
                currentSize++;
                for( int i = currentSize - 1; i != index - 1; i--){
                    array[i] = array[i - 1];
                }
                array[index] = n;
            }
            cout<<"Adding "<<n<<" to index "<<index<<endl;
            cout<<endl;
        }

        int get(){
            int index;
            while (true){
            cout<<endl;
            cout<<"enter the index of the item you want to receive "<<endl;
            cin >> index;
            if(index > currentSize){
                cout<<"You enter incorrect value"<<endl;
                exit(index);
            }
            else
                break;
            }

            cout<<"Get item with index "<<index<<" - "<<array[index]<<" from the array"<<endl;
            return array[index];
        }

        void remove(int index){
            cout<<endl;
            cout<<"The item with the index "<<index<<" - "<<array[index]<<" will be deleted"<<endl;
            for( int i = index + 1; i <= currentSize; i++){
                array[i - 1] = array[i];
            }
            currentSize--;
        }

        void trimToSize(){
            cout<<endl;
            int* trimArray = new int[currentSize];
            for(int i = 0; i < currentSize; i++){
                trimArray[i] = array[i];
            }

            delete []array;
            int* array = trimArray;
            allocatedSize = currentSize;
            for(int i = 0; i < currentSize;i++){
                cout<<trimArray[i]<<" ";
            }
        }

        void print(){
            for(int i = 0; i < allocatedSize; i++){
                cout<<array[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){

    ArrayList* list = new ArrayList(3);
    cout << "********** Source array of added elements **********"<<endl;
    cout<<endl;
    list->add(23);
    list->add(45);
    list->add(82);
    list->print();
    list->add(444);
    cout<<endl;
    list->print();
    cout<<endl;
    cout <<"********** Add to index **********"<< endl;
    list->addToIndex(3, 112);
    list->print();
    cout<<endl;
    cout <<"********** Get element **********"<< endl;
    list->get();
    cout << endl;
    list->print();
    cout<<endl;
    cout <<"********** Remove element **********"<< endl;
    list->remove(3);
    cout << endl;
    list->print();
    cout<<endl;
    cout<<"********** Trim to size **********"<<endl;
    list->trimToSize();
    cout<<endl;
}
