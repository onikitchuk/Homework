#include <stdio.h>

    //sorting of letters and their counting
    void sort(char* letterStr, int* countOfLetter, int temporaryCount, int temporaryLetter){

        int i = 0;
        int j = 0;
        int sizeOfLetterStr = strlen(letterStr);
        for(i = 0; i < sizeOfLetterStr; i++){
            for(j = i + 1; j < sizeOfLetterStr; j++){
                if(countOfLetter[i] < countOfLetter[j]){
                    temporaryCount = countOfLetter[j];
                    countOfLetter[j] = countOfLetter[i];
                    countOfLetter[i] = temporaryCount;

                    temporaryLetter = letterStr[j];
                    letterStr[j] = letterStr[i];
                    letterStr[i] = temporaryLetter;
                }
            }
        }
    }

    //Unsorted list printing
    void printUnsortedList(char* letterStr, char* enteredStr, int* countOfLetter){
         int i = 0;
         int j = 0;
        printf(" \n Unsorted list:\n");
        int sizeOfLetterStr = strlen(letterStr);
        int sizeOfEnteredStr = strlen(enteredStr);
        for(i = 0; i < sizeOfLetterStr; i++){
            for(j = 0; j < sizeOfEnteredStr; j++){
                if(letterStr[i] == enteredStr[j]){
                    countOfLetter[i]++;
                }
            }
            printf("%5c - %d\n", letterStr[i], countOfLetter[i]);
        }
    }

    //storing one letter from a string in an array
    void storingOneLetterInArray(int countOfLetter[], char enteredStr[], char letterStr[]){
        int i = 0;
        int j = 0;
        int sizeCountOfLetter = strlen(countOfLetter);
            for(i = 0; i < sizeCountOfLetter; i++){
                countOfLetter[i] = 0;
            }
            int tempCount = 0;
            for(i = 0; i < enteredStr[i] != '\0'; i++){
                char c = enteredStr[i];
                if(c == ' '){
                    continue;
                }
                int varTest = 0;
                for(j = 0; j < tempCount; j++){
                    if(letterStr[j] == c){
                        varTest = 1;
                    }
                }
                if(varTest == 0){
                    letterStr[tempCount] = c;
                    tempCount++;
                }
            }
            letterStr[tempCount] = 0;
    }

int main() {

    int i,j;
    int temporaryCount = 0;
    int temporaryLetter = 0;

    char* enteredStr = (char*)malloc(sizeof(char) * 200000);
    char* letterStr = (char*)malloc(sizeof(char) * 200000);
    int* countOfLetter = (int*)malloc(sizeof(int) * 200000);

        printf("Enter some words:\n");
        gets(enteredStr);

        storingOneLetterInArray(countOfLetter,  enteredStr, letterStr);
        printUnsortedList(letterStr, enteredStr, countOfLetter);
        printf("\n");
        sort(letterStr, countOfLetter, temporaryCount, temporaryLetter);

        printf("\n");

        //Sorted list printing
        printf(" Sorted list:\n");
        int m;
        int sizeOfLetterStr = strlen(letterStr);
        for(m = 0; m <= sizeOfLetterStr; m++){
            if(countOfLetter[m] != 0){
                printf("%5c - %d\n", letterStr[m], countOfLetter[m]);
            }
        }
        free(enteredStr);
        free(letterStr);
        free(countOfLetter);
        return 0;
}
