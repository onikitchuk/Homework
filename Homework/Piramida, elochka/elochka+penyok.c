#include <stdio.h>

main(){

    int i,j,rows,k,m;
    int g = 0;
    int z = 0;
    char stars = '*';

    printf("Enter number of rows\n");
    scanf("%d", &rows);
    for(i = 0;i < rows;i++){
        for(j = 0;j < rows - i;j++){
            printf("%c", ' ');
        }
        for(k = 0;k < i + 1;k++){
            printf("%c", stars);
        }
        for(m = 0;m < i ;m++){
            printf("%c", stars);
        }
        if(i == (rows - 1)){
            printf("\n");
            while(g <= rows){
                if(g < rows){
                    printf("%c", ' ');
                } else {
                    printf("%c", stars);
                }
                g++;
            }
            printf("\n");
            while(z <= rows){
                if(z < rows){
                    printf("%c", ' ');
                } else{
                    printf("%c", stars);
                }
                z++;
            }
        }
        printf("\n");
    }
    return 0;
}
