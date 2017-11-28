#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

class ArrayList{
private:
    const int INIT_SIZE = 3;
    int* array;
    int currentSize;
    int allocatedSize;

    void fillNewArray(int* newArray){
        for( int i = 0; i < currentSize; i++){
           newArray[i] = array[i];
           cout<<newArray[i]<<" ";
        }
    }

    void addToNotFullArray(int n){
        array[currentSize] = n;
        currentSize++;
        return;
    }

    void addToFullArray(int n){
        int* newArray = new int[allocatedSize*2];
        allocatedSize *= 2;
        fillNewArray(newArray);
        delete []array;
        array = newArray;
        cout<<endl;cout<<endl;
        cout<<"The array is enlarged 2 times after the original array size is exceeded"<<endl;
        addToNotFullArray(n);
    }
public:
    ArrayList(){
        array = new int[INIT_SIZE];
        currentSize = 0;
        allocatedSize = INIT_SIZE;
    }

        void add(int n){
            if(currentSize < allocatedSize){
                addToNotFullArray(n);
            } else {
                addToFullArray(n);
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

        int get(int index){
            cout<<endl;
            cout<<"Get item with index "<<index<<" - "<<array[index]<<" from the array"<<endl;
            return array[index];
        }

        void remove(int index){
            cout<<endl;
            cout<<"The item with the index "<<index<<" - "<<array[index]<<" will be deleted"<<endl;
            for( int i = index; i < currentSize; i++){
                array[i] = array[i + 1];
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
  ArrayList* list = new ArrayList();
    cout << "********** Source array of added elements **********"<<endl;
    cout<<endl;
    list->add(23);
    list->add(45);
    list->add(82);
    list->add(444);
    cout<<endl;
    list->print();
    cout<<endl;
    cout <<"********** Add to index **********"<< endl;
    list->addToIndex(3, 112);
    list->print();
    cout<<endl;
    cout <<"********** Get element **********"<< endl;
    list->get(1);
    cout << endl;
    list->print();
    cout<<endl;
    cout <<"********** Remove element **********"<< endl;
    list->remove(2);
    cout << endl;
    list->print();
    cout<<endl;
    cout<<"********** Trim to size **********"<<endl;
    list->trimToSize();
    cout<<endl;
}
