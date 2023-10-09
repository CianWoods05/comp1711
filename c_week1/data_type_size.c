#include <stdio.h> 
#include <math.h>

int main(){
    double intsize = 2147483647;
    double floatsize = 3.40282 * pow(10,38) ;
    double doublesize = 1.79769 * pow(10,308);
    double charsize = 127;
    
    printf("max size of an int %f and max size of a float %f and max size a double %f and max size of a char %f", intsize , floatsize , doublesize, charsize );

    return 0;
}