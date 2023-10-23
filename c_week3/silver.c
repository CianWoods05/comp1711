#include "utils.h"

int main(){
    char* filename = "squares.txt";
    FILE *file = fopen(filename, "r");
    float mean;
    int buffer_size = 100;
    char line_buffer[buffer_size];

    while (fgets(line_buffer, buffer_size, file) != NULL) { // while there is still data in the file
        printf("%d\n", atoi(line_buffer));
    }

    fclose(file);
    return 0;
}   