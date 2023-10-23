#include "utils.h"

int main() {
    char* filename = "data.txt";
    FILE *file = fopen(filename, "r");
    
    int buffer_size = 100;
    char line_buffer[buffer_size]; // length of line, so will read the first 100 characters on each line
    // string that will hold each line as its read in
     while (fgets(line_buffer, buffer_size, file) != NULL) { // while there is still data in the file
        printf("%d\n", atoi(line_buffer));
    }
}