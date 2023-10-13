 #include <stdio.h>

int main(){
    int a[10];
    int count = 0;

    while( count <= 10 ){
        a[count] = count * 10 + count;
        count += 1;
    }
}