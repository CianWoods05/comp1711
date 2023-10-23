#include <stdio.h>

int main(){
    int i = 0;
    int total = 0;
    int num[10];
    float mean;

    for(i = 0; i < 10; i++){
        printf("enter a number");
        scanf("%d", &num[i]);
        total += num[i];
        
    }
    mean = total / 10;
    printf("the total of the 10 numbers is %d and the mean is %.3f\n", total,mean);
    return 0;
}