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


    printf("%s\n","Menu Options:");
    printf("%s\n","A: Specify the filename to be imported");
    printf("%s\n","B: Display the total number of records in the file");
    printf("%s\n","C: Find the date and time of the timeslot with the fewest steps");
    printf("%s\n","D: Find the data and time of the timeslot with the largest number of steps");
    printf("%s\n","E: Find the mean step count of all the records in the file");
    printf("%s\n","F: Find the longest continuous period where the step count is above 500 steps");
    printf("%s\n","Q: Quit");

    printf("%s","Enter choice: ");
    char choice;
    scanf("%s", &choice);

    switch(choice)
    {
        case A: printf("%s","Filename to be imported: ");
                scanf("%s", &filename);
                FILE *file = fopen (filename, "r");
                if (file == NULL) {
                    perror("Error: could not open file");
                    return 1;
                };
        break;
        case B: char fitnessdata [] = "FitnessData_2023.csv";
                FILE *file = fopen (fitnessdata, "r");
                // seek(file,0) and close the file

                int buffer_size = 0, i;
                char line_buffer[100];
                FITNESS_DATA records[100];
                while (fgets(line_buffer, 100, file) != NULL) {
                    tokeniseRecord (line_buffer, ",", records[buffer_size].date, records[buffer_size].time, &records[buffer_size].steps);
                    buffer_size= buffer_size+1;
                    };
                printf("Number of records in the file: %d", buffer_size);
        break;
        case C: printf("Fewest steps: %s %s", records[i].date, records[i].time);
        break;
        case D: printf("Largest steps: %s %s", records[i].date, records[i].time);
        break;
        case E: printf("Mean step count: ")
        break;
        case F: printf("Longest period start: %s %s", records[i].date, records[i].time);
                printf("Longest period end: %s %s", records[i].date, records[i].time);
        break;
        case Q: Quit;
        break;
        default: printf("%s\n","Invalid choice.Try again.")
    };

    
    }

    return 0;

}











