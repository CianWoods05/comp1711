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
    char dateString[11];
    char timeString[6];
    char stepString[7];
    int stepInteger;
    int i = 0;
    int j = 0;
    int buffer_size = 100;
    char line_buffer[100];
    char filename[100];
    FitnessData stepRecord[1000];
    
    int swaps = 1;
    printf("Enter Filename: ");
    fgets(line_buffer, buffer_size, stdin);
    sscanf(line_buffer, " %s ", filename);
	FILE *input = fopen(filename, "r");
    char *newFile = strcat(filename,".tsv");
    if (!input)
    {
        printf("Error: invalid file\n");
        return 1;
    }  
	else{
	    while (fgets(line_buffer, buffer_size, input) != NULL){
        tokeniseRecord(line_buffer, "," , dateString, timeString, stepString);
        stepInteger = atoi(stepString);
        if(strlen(dateString) == 0){
            printf("Error: invalid file\n");
            return 1;
        }
        for(i = 0; i < 11; i++){
            stepRecord[numRows].date[i] = dateString[i];
	    }		
        if(strlen(timeString) == 0){
            printf("Error: invalid file\n");
            return 1;
        }				
        for(i = 0; i < 6; i++){
            stepRecord[numRows].time[i] = timeString[i];
        }		
        if(strlen(stepString) == 0){
            printf("Error: invalid file\n");
            return 1;
        }				
        stepRecord[numRows].steps = stepInteger;
        numRows += 1;
	}

    do{
        swaps = 0;  
        for(j=0;j < (numRows - 1);j++){

            if(stepRecord[j+1].steps > stepRecord[j].steps){

                swaps +=1;

                strncpy(dateString,stepRecord[j].date,11);
                strncpy(timeString,stepRecord[j].time,6);
                stepInteger = stepRecord[j].steps;


                strncpy(stepRecord[j].date,stepRecord[j+1].date,11);
                strncpy(stepRecord[j].time,stepRecord[j+1].time,6);
                stepRecord[j].steps = stepRecord[j+1].steps;

                strncpy(stepRecord[j+1].date,dateString,11);
                strncpy(stepRecord[j+1].time,timeString,6);
                stepRecord[j+1].steps = stepInteger;
            }
        }
    }while(swaps != 0);

    fclose(input);
    FILE *file = fopen(newFile, "w");


    for(i=0;i<numRows;i++){
        fprintf(file,"%s\t%s\t%d\n", stepRecord[i].date,stepRecord[i].time,stepRecord[i].steps);
    }
    fclose(file);

    return 0;
}
}