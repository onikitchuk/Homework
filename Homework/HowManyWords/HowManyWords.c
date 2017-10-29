#include <stdio.h>
#define SIZE 50

int main() {

    int i = 0,countOfWords = 0;
    char enteredString[SIZE];

        printf("Enter the string of words:\n");
        gets(enteredString);
        for(i = 0; i < strlen(enteredString);i++){
            if(isalpha(enteredString[i]) > 0 && isalpha(enteredString[i - 1]) == 0){
            countOfWords++;
            }
        }
        printf("\nCount of words = %d\n", countOfWords);

    return 0;
}
