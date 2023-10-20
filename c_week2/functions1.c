#include <stdio.h>


int sum(int a, int b){
    int ans;
    ans = a+b;
    return ans;
}

int main(){
    int y = 2;
    int z = sum(5,y);
    int z1 = sum(10,y);

    printf("the sum of 5 and %d is %d\n", y ,z);

}