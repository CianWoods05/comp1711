#include "utils.h"

int main(){
    char *filename = "squares.txt";
    FILE *file = fopen(filename, "w");
    int num,i;
    
    printf("enter a positive whole number\n");
    scanf(" %d", &num);

    for(i = 1; i <= num; i++){
        fprintf(file, "%d", i*i);
        fprintf(file, "\n");
    }


     fclose(file);
    return 0;


}