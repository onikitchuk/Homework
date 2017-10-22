#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(){

   int searchedNum = 0;
   int usersNum = 0;
   char select;
   int i;
   int val;

   for(;;){
    srand(time(NULL));
    searchedNum = rand() %10;

    for(i = 0; i < 3; i++){
        if(i == 2){
            printf("\nLast try!\n");
        }
        for(;;){

            printf("\nEnter posiive value: \n");
                val = scanf("%d", &usersNum);
            if(usersNum < 0){
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
        if(searchedNum == usersNum){
            printf("YaaHOOO!\n");
            return 0;
        }
        if(usersNum < searchedNum){
            printf("Bigger!\n");
        }
        if(usersNum > searchedNum){
            printf("Lower!\n");
        }
    }
    printf("\nEnd of game!\n");
    printf("\nContinue or exit? - y, n");
    printf("\n");
    scanf("%s", &select);
    if(select == 'y'){
        continue;
    }
    if(select == 'n'){
        return;
    }
   }
   return 0;
}


