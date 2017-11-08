#include <stdio.h>


//receiving a string from the user
char getString(char* enteredString){
        printf("Enter the letters and symbols:\n");
        gets(enteredString);
}
//counting words
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
    char* enteredString = (char*)malloc(sizeof(char) * 200000);

        getString(enteredString);
        isCountOfWords(enteredString,countOfWords);
    free(enteredString);
    return 0;
}
