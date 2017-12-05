#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Map {
public:
     int array[100];
     // use the asci character string
        int hash (char* str){
           int num = 0;
           for(int i = 0; str[i] != '\0'; i++){
                num += int(str[i] % 10);
           }
            return num;
     }

     void put(char* str, int data){
        array[hash(str)] = data;
     }

     int get(char* str){
        return array[hash(str)];
     }
};

int main(int argc, const char * argv[]){
   Map m;
        cout<<"\n------------"<<endl;
        m.put("igor", 91);
        m.put("igir", 345);
        m.put("vasewrsgfdsgfdhewtrwtytywrywywyw", 36);

        cout<<m.get("igor")<<endl;
        cout<<m.get("igir")<<endl;
        cout<<m.get("vasewrsgfdsgfdhewtrwtytywrywywyw")<<endl;
        cout<<"\n------------"<<endl;

    return 0;
}
