#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


void choice(enteredNumber, randomNumber, val){

        int i = 0;

         for(i = 0; i < 3; i++){
            if(i == 2){
                printf("\nLast try!\n");
            }
            for(;;){
                printf("\nEnter posiive value ( from 1 to 10 ):\n");
                    val = scanf("%d", &enteredNumber);
                if(enteredNumber < 0){
                    printf("Hey, it`s negative number!\n");
                    continue;
                }
                if(val == 0){
                    printf("\nIt`s not correct value!\n");
                    fflush(stdin);
                    continue;
                }
                break;
            }
            if(randomNumber == enteredNumber){
                printf("YaaHOOO!\n");
                return 0;
            }
            if(enteredNumber < randomNumber){
                printf("Bigger!\n");
            }
            if(enteredNumber > randomNumber){
                printf("Lower!\n");
            }
        }
}


int main(){

   int randomNumber = 0;
   int enteredNumber = 0;
   char choiceOfAction = 0;
   int i = 0;
   int val = 0;

   for(;;){
        srand(time(NULL));
        randomNumber = rand() %10;

    choice(enteredNumber, randomNumber, val);

        printf("\nEnd of game!\n");
        printf("\nContinue or exit? - y, n");
        printf("\n");
        scanf("%s", &choiceOfAction);
        if(choiceOfAction == 'y'){
            continue;
        }
        if(choiceOfAction == 'n'){
            return;
        }
   }
   return 0;
}


