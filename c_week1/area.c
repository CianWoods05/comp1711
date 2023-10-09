#include <stdio.h>

int main(){
    float length;
    float width;
    float area;
    
    printf("Enter the length:");
    scanf("%f", &length);
    printf("Enter the width:");
    scanf("%f", &width);

    area = length * width;
    printf("the area of a rectangle with lenth %f and width %f is %f\n", length , width , area );

    return 0;
}