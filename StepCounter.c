#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"
// Struct moved to header file
// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
int numRows;
char dateString[12];
char timeString[7];
char stepString[7];
int stepInteger;
int i = 0;
int buffer_size = 100;
char line_buffer[100];
char filename[100];
FITNESS_DATA stepRecord[1000];
char choice;
int lowest, highest;
double mean;
int start = 0;
int end = 0;
int longS = 0;
int longE = 0;
int lowI , highI;
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
		break;

		case 'B':
        case 'b':
			if (!filename)
        		{
           	 	printf("Error: could not open file\n");
           		return 1;
				}

			printf("Total records: %d\n", numRows);
		break;

		case 'C':
        case 'c':
			if (!filename)
        		{
           	 	printf("Error: could not open file\n");
           		return 1;
				}
			lowI = 0;
			lowest = stepRecord[0].steps;
			for(i = 1; i < numRows; i++){
				if(stepRecord[i].steps < lowest){
					lowest = stepRecord[i].steps;
					lowI = i;
				}
			}
			printf("Fewest steps: %s %s\n", stepRecord[lowI].date, stepRecord[lowI].time);
		break;

		case 'D':
        case 'd':
			if (!filename)
        		{
           	 	printf("Error: could not open file\n");
           		return 1;
				}
				highI = 0;
				highest = stepRecord[0].steps;
				for(i = 1; i < numRows; i++){
				if(stepRecord[i].steps > highest){
					highest = stepRecord[i].steps;
					highI = i;
				}
			}
			printf("Largest steps:");
			printf(" %s",stepRecord[highI].date);
			printf(" %s\n",stepRecord[highI].time);
		break;

		case 'E':
        case 'e':
			if (!filename)
        		{
           	 	printf("Error: could not open file\n");
           		return 1;
				}
			for(i=0; i < numRows; i++){
				mean += stepRecord[i].steps;
			}
			mean /= numRows;
			printf("Mean step count: %.0f\n",mean);
		break;

		case 'F':
        case 'f':
        		if (!filename)
        		{
           	 	printf("Error: could not open file\n");
           		return 1;
				}
				for(i = 0 ; i < numRows - 1 ; i++){
					if(stepRecord[i].steps > 500 && start == 0){
						start = i;
					}
					else if(stepRecord[i].steps > 500 && start != 0){
						end = i;
					}else if(end - start > longE - longS){
						longS = start;
						longE = end;
					}else{
						start = 0;
						end = 0;
					}
				}
				printf("Longest period start: %s %s\n", stepRecord[longS].date, stepRecord[longS].time);
				printf("Longest period end: %s %s\n", stepRecord[longE].date, stepRecord[longE].time);
		break;
		case 'Q':
        case 'q':
			return 0;
		break;
	}
}
}