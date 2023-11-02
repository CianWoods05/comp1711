#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

FILE *open_file(char *filename, char *mode)
{
    FILE *file = fopen(filename, mode);
    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    return file;
}


// Define any additional variables here
int numRows;
char dateString[11];
char timeString[6];
char stepString[6];
int stepInteger;
int i = 0; // is a counter like in a for loop


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {

    char *filename = "FitnessData_2023.csv";
    FILE *file = open_file(filename, "r");

    int buffer_size = 100;
    char line_buffer[buffer_size];
    FITNESS_DATA stepRecord [1000];       // declares stepRecord as an array of length 1000

    while (fgets(line_buffer, buffer_size, file) != NULL){
        tokeniseRecord(line_buffer, "," , dateString, timeString, stepString);
        stepInteger = atoi(stepString);
        for(i = 0; i < 11; i++){
            stepRecord[numRows].date[i] = dateString[i];
            
        }

        for(i = 0; i < 6; i++){
            stepRecord[numRows].time[i] = timeString[i];
            
        }

        stepRecord[numRows].steps = stepInteger;

        numRows += 1;
    }
    fclose(file);

    printf("Number of records in file: %d\n", numRows);
    for(i = 0; i < 3; i++){
        printf("%s/%s/%d\n", stepRecord[i].date , stepRecord[i].time , stepRecord[i].steps);
    }

    return 0;
}