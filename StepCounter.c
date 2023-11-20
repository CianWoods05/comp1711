#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


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
	int numRows;
	char dateString[11];
	char timeString[6];
	char stepString[6];
	int stepInteger;
	int i = 0;
	int buffer_size = 100;
    char line_buffer[buffer_size];
	char filename[buffer_size];
    FITNESS_DATA stepRecord [1000];
	char choice;
	int lowest, highest;
	double mean;
	int start,end;
	int lowI , highI;

	


	while(choice != 'q' && choice != 'Q')
	{
    	printf("A: Specify the filename to be imported\n");                       
    	printf("B: Display the total number of records in the file\n");                    
    	printf("C: Find the date and time of the timeslot with the fewest steps\n");                     
    	printf("D: Find the data and time of the timeslot with the largest number of steps\n");                    
    	printf("E: Find the mean step count of all the records in the file\n");      
    	printf("F: Find the longest continuous period where the step count is above 500 steps\n");                  
    	printf("Q: Exit the program\n");
    	choice = getchar();
    	while (getchar() != '\n');

		switch(choice){
			case 'A':
        	case 'a':
				printf("Please enter the name of the data file: ");
    			fgets(line_buffer, buffer_size, stdin);
    			sscanf(line_buffer, " %s ", filename);

				FILE *input = fopen(filename, "r");
        		if (!input)
        		{
           	 	printf("Error: could not open file\n");
           		return 1;
				}
				else
				{
					while (fgets(line_buffer, buffer_size, input) != NULL){
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
				}
		break;

		case 'B':
        case 'b':
			if (!filename)
        		{
           	 	printf("Error: could not open file\n");
           		return 1;
				}

			printf("Number of records in file: %d\n", numRows);
		break;

		case 'C':
        case 'c':
			if (!filename)
        		{
           	 	printf("Error: could not open file\n");
           		return 1;
				}
			lowest = stepRecord[0].steps;
			for(i = 1; i <= numRows; i++){
				if(stepRecord[i].steps < lowest){
					lowest = stepRecord[i].steps;
					lowI = i;
				}
			}
			printf("Fewest Steps: %s %s\n", stepRecord[lowI].date, stepRecord[lowI].time);
		break;

		case 'D':
        case 'd':
			if (!filename)
        		{
           	 	printf("Error: could not open file\n");
           		return 1;
				}
				highest = stepRecord[0].steps;
				for(i = 1; i <= numRows; i++){
				if(stepRecord[i].steps > highest){
					highest = stepRecord[i].steps;
					highI = i;
				}
			}
			printf("Largest Steps: %s %s\n", stepRecord[lowI].date, stepRecord[lowI].time);
		break;

		case 'E':
        case 'e':
			if (!filename)
        		{
           	 	printf("Error: could not open file\n");
           		return 1;
				}
			for(i=0; i <= numRows; i++){
				mean += stepRecord[i].steps;
			}
			mean /= numRows;
			printf("Mean step count: %f\n");
		break;

		case 'F':
        case 'f':
        		if (!filename)
        		{
           	 	printf("Error: could not open file\n");
           		return 1;
				}
		break;

		case 'Q':
        case 'q':

		break;


	}
    


}
}
