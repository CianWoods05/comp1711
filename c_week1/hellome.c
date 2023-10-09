#include <stdio.h>

int  main(){
    // sets 15 slots of memory for a string
    char name[15];
    // prompts the user for there name
    printf("Hello, enter your name;");
    // takes the input as a string and saves it in name
    scanf("%s", name);
    // prints name as a string and \n puts it on a new line
    printf("Your name is %s\n",name);
    // all int sub routines have to return a number
    return 0;
}