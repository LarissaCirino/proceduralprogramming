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

int main()
{
    // array of 
    FITNESS_DATA records[100]; //ver briefing

    char line[buffer_size];
    char filename[buffer_size];

    // get filename from the user
    printf("Please enter the name of the data file: ");

    // these lines read in a line from the stdin (where the user types)
    // and then takes the actual string out of it
    // this removes any spaces or newlines.
    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);

    char choice;
    int counter = 0;
    float mean = 0;

    FILE *input = fopen(filename, "r");
    if (!input)
    {
        printf("Error: File could not be opened\n");
        return 1;
    }

    while (fgets(line_buffer, 100, file) != NULL) 
    {    
        tokeniseRecord (line_buffer, ",", records[buffer_size].date, records[buffer_size].time, &records[buffer_size].steps);
        buffer_size++;

    };

    fclose(input);

    while (1)
    {


    printf("%s\n","Menu Options:");
    printf("%s\n","A: Specify the filename to be imported");
    printf("%s\n","B: Display the total number of records in the file");
    printf("%s\n","C: Find the date and time of the timeslot with the fewest steps");
    printf("%s\n","D: Find the data and time of the timeslot with the largest number of steps");
    printf("%s\n","E: Find the mean step count of all the records in the file");
    printf("%s\n","F: Find the longest continuous period where the step count is above 500 steps");
    printf("%s\n","Q: Quit");

    printf("%s","Enter choice: ");

    // get the next character typed in and store in the 'choice'
    choice = getchar();

    // this gets rid of the newline character which the user will enter
    // as otherwise this will stay in the stdin and be read next time
    while (getchar() != '\n');

    // scanf("%s", &choice); oq eu tinha colocado antes de 13/11

    switch(choice)
    {
        case 'A': 
        case 'a':
                printf("%s","Filename to be imported: ");
                scanf("%s", &filename);
                FILE *file = fopen (filename, "r");
                if (file == NULL) {
                    perror("Error: could not open file");
                    return 1;
                };
            break;
        case 'B':
        case 'b':
                //char fitnessdata [] = "FitnessData_2023.csv";
                //FILE *file = fopen (fitnessdata, "r");
                // seek(file,0) and close the file

                //int buffer_size = 0, i;
                //char line_buffer[100];
                //FITNESS_DATA records[100];

                printf("Number of records in the file: %d", buffer_size);
            break;
        case 'C':
        case 'c':
            printf("Fewest steps: %s %s", records[i].date, records[i].time);
            break;
        case 'D': 
        case 'd':
            printf("Largest steps: %s %s", records[i].date, records[i].time);
            break;
        case 'E': 
        case 'e':
            printf("Mean step count: ")
            break;
        case 'F': 
        case 'f':
                printf("Longest period start: %s %s", records[i].date, records[i].time);
                printf("Longest period end: %s %s", records[i].date, records[i].time);
                break;
        case 'Q':
        case 'q': 
                return 0;
                break;
        default: 
            printf("%s\n","Invalid choice.Try again.");
            break;
    };

    
    }

    return 0;

}












