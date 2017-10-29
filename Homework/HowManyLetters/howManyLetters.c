#include <stdio.h>

#define SIZE_COUNT 26
#define SIZE_ENTERED_STRING 50

ReceivedString(char letterOfString[]);

int main()
{
char alphabet[SIZE_COUNT] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','r','s','t','u','v','w','x','y','z'};
int countLetters[SIZE_COUNT] = {0};
char letterOfString[SIZE_ENTERED_STRING];

int k;
int i;

    ReceivedString(letterOfString);

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
    return 0;
}

ReceivedString(char letterOfString[]){
int i = 0;
int j = 0;
char enteredString[SIZE_ENTERED_STRING];

printf("Enter the word:\n");
scanf("%s", &enteredString);
    for(i,j; enteredString[i] != '\0'; i++){
            if(enteredString[i] != ' '){
                    letterOfString[j++] = enteredString[i];
                    letterOfString[j] = '\0';
                }
        }
 }


