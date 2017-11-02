#include <stdio.h>


int christmasTree(int height){
    int i,j;
    int g = 0;
    int spases = height - 1;
    int stars = 1;
    if(height <= 0){
        printf("Wrong data!\n");
        return -1;
    }
    for(i = 0; i < height; i++){
        for(j = 0; j < spases; j++){
            printf(" ");
        }
        for(j = 0; j < stars; j++){
            printf("*");
        }
        stars += 2;
        spases--;
        if(i == (height - 1)){
            printf("\n");
            while(g <= height - 1){
                if(g < height - 1){
                    printf("%c", ' ');
                } else {
                    printf("*");
                }
                g++;
            }
        }
        printf("%\n");
    }
    return 0;
}

int main(){
   int height = 0;
   printf("Enter the rows or Christmas Tree:\n");
   scanf("%d", &height);
//   printf("%d\n", height);
   int ok = christmasTree(height);

   return 0;
}



