#include <stdio.h> 
#include <math.h>

int main(){
    int a = 5,i = 1;

    while( i <= 10 ){
        a = pow(i,2);
        printf("%d\n", a);
        i += 1;
    }

    //for (i = 1; i < 5; i++){
    //    printf("%d\n", i);
    //}

    
    return 0;
}