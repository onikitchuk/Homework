#include <stdio.h>

#define SIZE_COUNT 26
#define SIZE_ENTERED_STRING 50


int main(){

char alphabet[SIZE_COUNT] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','r','s','t','u','v','w','x','y','z'};
char letterOfString[SIZE_ENTERED_STRING];
char temporary = 0;
char enteredString[SIZE_ENTERED_STRING];

int k = 0;
int i = 0;
int j = 0;
int n = 0;
int countLetters[SIZE_COUNT] = {0};


    printf("Enter the word:\n");
    gets(enteredString);
    for(i,j; enteredString[i] != '\0'; i++){
            if(enteredString[i] != ' '){
                    letterOfString[j++] = enteredString[i];
                    letterOfString[j] = '\0';
                }
        }


    for(k = 0;k < strlen(letterOfString);k++){
        for(i = 0; i < SIZE_COUNT; i++){
            if(alphabet[i] == letterOfString[k])
            {
                countLetters[i]++;
                break;
            }
        }
    }
    printf("\n");

    for(i = 0; i < SIZE_COUNT; i++){
        if(countLetters[i] > 0){
            printf("%c - %d \n",alphabet[i], countLetters[i]);
        }
    }
    printf("\n");
     for(i = 0; i < SIZE_COUNT; i++){
        for(j = 0; j < SIZE_COUNT; j++){
            if(countLetters[j] < countLetters[j + 1]){
                temporary = countLetters[j];
                countLetters[j] = countLetters[j + 1];
                countLetters[j + 1] = temporary;
            }
        }
    }
    for(n = 1; n <= SIZE_COUNT; n++){
            if(countLetters[n] != 0){
                printf("%d ", countLetters[n]);
            }

    }

    return 0;
}




