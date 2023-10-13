#include <stdio.h>

int main(){
    int count = 0;
    char str[6]= "hello";

    while(count <= 6){
        printf("%c\n",str[count]);
        count += 1;
    }

    return 0;
}