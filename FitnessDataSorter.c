#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
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


int main() {
    int numRows;
    char dateString[12];
    char timeString[7];
    char stepString[7];
    int stepInteger;
    int i = 0;
    int buffer_size = 100;
    char line_buffer[100];
    char filename[100];
    FitnessData stepRecord[1000];
    char* newFile

    printf("Enter Filename: ");
    fgets(line_buffer, buffer_size, stdin);
    sscanf(line_buffer, " %s ", filename);
	FILE *input = fopen(filename, "r");
    if (!input)
    {
        printf("Error: could not open file\n");
        return 1;
    }  
	else{
	    while (fgets(line_buffer, buffer_size, input) != NULL){
        tokeniseRecord(line_buffer, "," , dateString, timeString, stepString);
        stepInteger = atoi(stepString);
        for(i = 0; i < 12; i++){
            stepRecord[numRows].date[i] = dateString[i];
	    }						
        for(i = 0; i < 7; i++){
        stepRecord[numRows].time[i] = timeString[i];
        }					
        stepRecord[numRows].steps = stepInteger;
        numRows += 1;
	}


}