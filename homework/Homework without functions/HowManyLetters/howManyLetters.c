#include <stdio.h>
#define SIZE 100

int main() {

    int i,j;
    int countOfLetter[SIZE];
    int temporary = 0;
    int temporaryLetter = 0;

    char enteredStr[SIZE];
    char lettStr[SIZE];

        printf("Enter some words:\n");
        gets(enteredStr);

        for(i = 0; i < SIZE; i++){
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

      //  printf("\n%s", lettStr);

        printf(" \n Unsorted list:\n");
        for(i = 0; i < strlen(lettStr); i++){
            for(j = 0; j < strlen(enteredStr); j++){
                if(lettStr[i] == enteredStr[j]){
                    countOfLetter[i]++;
                }
            }
            printf("%5c - %d\n", lettStr[i], countOfLetter[i]);
        }
        printf("\n");
        for(i = 0; i <= strlen(lettStr); i++){
            for(j = 0; j <= strlen(lettStr); j++){
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
            printf("\n");
            printf(" Sorted list:\n");
            int m;
        for(m = 0; m <= strlen(lettStr); m++){
            if(countOfLetter[m] != 0){
                printf("%5c - %d\n", lettStr[m], countOfLetter[m]);
            }
        }


        return 0;
    }
