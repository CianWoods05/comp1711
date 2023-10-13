#include <stdio.h>

int main(){
    int a[10];
    int count = 0, total = 0;

    while( count < 10 ){
        a[count] = count * 10 + count;
        total += a[count];
        count += 1;
    }

    printf("%d",total);

    return 0;
}