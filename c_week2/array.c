#include <stdio.h> 
#include <math.h>

int main(){
    int a[10];
    int count = 0;

    while( count <= 10 ){
        a[count] = count * 10 + count;
        count += 1;
    }

    for(count = 0; count < 10; count++){
        printf("%d\n", a[count]);
    }
    return 0;
}