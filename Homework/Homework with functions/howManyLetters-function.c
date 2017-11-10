#include <stdio.h>

    //sorting of letters and their counting
    void sort(char* lettStr, int* countOfLetter, int temporary, int temporaryLetter){

        int i = 0;
        int j = 0;
        int sizeOfLettStr = strlen(lettStr);
        for(i = 0; i <= sizeOfLettStr; i++){
            for(j = 0; j <= sizeOfLettStr; j++){
                if(countOfLetter[j] < countOfLetter[j + 1]){
                    temporary = countOfLetter[j];
                    countOfLetter[j] = countOfLetter[j + 1];
                    countOfLetter[j + 1] = temporary;

                    temporaryLetter = lettStr[j];
                    lettStr[j] = lettStr[j + 1];
                    lettStr[j + 1] = temporaryLetter;
                }
            }
        }
    }


    //unselected list printing
    void printUnsortedList(char* lettStr, char* enteredStr, int* countOfLetter){
         int i = 0;
         int j = 0;
        printf(" \n Unsorted list:\n");
        for(i = 0; i < strlen(lettStr); i++){
            for(j = 0; j < strlen(enteredStr); j++){
                if(lettStr[i] == enteredStr[j]){
                    countOfLetter[i]++;
                }
            }
            printf("%5c - %d\n", lettStr[i], countOfLetter[i]);
        }
    }
    //storing one letter from a string in an array
    void testLetter(int countOfLetter[], char enteredStr[], char lettStr[]){
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
                    if(lettStr[j] == c){
                        varTest = 1;
                    }
                }
                if(varTest == 0){
                    lettStr[tempCount] = c;
                    tempCount++;
                }
            }
            lettStr[tempCount] = 0;
    }

int main() {

    int i,j;
    int temporary = 0;
    int temporaryLetter = 0;

        char* enteredStr = (char*)malloc(sizeof(char) * 200000);
        char* lettStr = (char*)malloc(sizeof(char) * 200000);
        int* countOfLetter = (int*)malloc(sizeof(int) * 200000);

        printf("Enter some words:\n");
        gets(enteredStr);

        testLetter(countOfLetter,  enteredStr, lettStr);
        printUnsortedList(lettStr, enteredStr, countOfLetter);
        printf("\n");
        sort(lettStr, countOfLetter, temporary, temporaryLetter);

        printf("\n");
        printf(" Sorted list:\n");

        int m;
        for(m = 0; m <= strlen(lettStr); m++){
            if(countOfLetter[m] != 0){
                printf("%5c - %d\n", lettStr[m], countOfLetter[m]);
            }
        }
        free(enteredStr);
        return 0;
}
