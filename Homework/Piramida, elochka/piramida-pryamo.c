#include <stdio.h>

main(){

    int rows, i, j;
    char star = '*';

   printf("Enter number of rows\n");
   scanf("%d", &rows);

   for(i = 0; i < rows;i++){
       for(j = 0;j < i + 1;j++){
           printf("%c", star);
       }
       printf("\n");
   }
   return 0;
}
