#include <stdio.h>
#define SIZE 500


char getString(char* enteredString){
        printf("Enter the string of words:\n");
        gets(enteredString);
}

int isCountOfWords(char* enteredString,int countOfWords){
    int i = 0;
    for(i = 0; i < strlen(enteredString);i++){
            if(isalpha(enteredString[i]) > 0 && isalpha(enteredString[i - 1]) == 0 ){
            countOfWords++;
            }
        }
        printf("\nCount of words = %d\n", countOfWords);
    return(countOfWords);
}

int main() {

    int i = 0,countOfWords = 0;
    char enteredString[SIZE];

        getString(enteredString);
        isCountOfWords(enteredString,countOfWords);

    return 0;
}
