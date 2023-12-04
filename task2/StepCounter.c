#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array

    char tempsteps[10000];


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
    if (token != NULL) {;
        strcpy(steps, token);    
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }


// Complete the main function

int main()
{
    // array of
    int buffer_size=10000;
    FITNESS_DATA records[buffer_size]; 

    char line_buffer[buffer_size];
    char filename[buffer_size];
    char choice;
    int i = 0;
    int counter= 0;
    int mean= 0;
    int stepcount = 0;

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

    switch (choice)
    { 
        case 'A': 
        case 'a':
                printf("%s","Input filename: ");
                // these lines read in a line from the stdin (where the user types)
                // and then takes the actual string out of it
                // this removes any spaces or newlines.
                fgets(line_buffer, buffer_size, stdin);
                sscanf(line_buffer, " %s ", filename);
                FILE *file = fopen (filename, "r");
                if (file == NULL) {
                    perror("Error: could not find or open the file");
                    return 1;
                }
                else{
                    printf("File successfully loaded.\n");
                };
                while (fgets(line_buffer, buffer_size, file) != NULL) 
                {    
                    tokeniseRecord (line_buffer,",", records[counter].date, records[counter].time, tempsteps);
                    records[counter].steps= atoi(tempsteps);
                    counter++;
    };
                fclose(file);
            break;
            
        case 'B':
        case 'b':
                printf("Total of records: %d\n", counter);
            break;

        case 'C':
        case 'c':
            stepcount=10000;
            int fewest_i= 0;
            for (i=0; i<counter; i++){
                if (records[i].steps<stepcount)
                {
                    stepcount=records[i].steps;
                    fewest_i=i;
            }
        }
            printf("Fewest steps: %s %s\n", records[fewest_i].date, records[fewest_i].time);
            break;

        case 'D': 
        case 'd':
            stepcount=0;
            int largest_i= 0;
                for (i=0; i<counter; i++)
                {
                    if (records[i].steps>stepcount)
                    {
                        stepcount=records[i].steps;
                        largest_i=i;
                }
            }
            printf("Largest steps: %s %s\n", records[largest_i].date, records[largest_i].time);
            break;

        case 'E': 
        case 'e':
            mean=0;
            for (i=0;i<counter;i++){
                mean += records[i].steps;
            }
            mean /= counter;
            printf("Mean step count: %d\n", mean);
            break;

        case 'F': 
        case 'f':
        {
            int first_i= 0;
            int last_i= 0;
            int firstnew_i= 0;
            int lastnew_i= 0;
            int newseq= 0;

            for (i=0; i<counter; i++)
            {
                if (records[i].steps>500){
                    if(newseq==0){
                       firstnew_i=i;
                       lastnew_i=i;
                       newseq=1;
                    }
                    else{
                        lastnew_i=i;
                    }
                }
                else {
                    newseq=0;
                    if(lastnew_i - firstnew_i > last_i - first_i){
                        last_i=lastnew_i;
                        first_i= firstnew_i;
                    }
                }
            }
            printf("Longest period start: %s %s\n", records[first_i].date, records[first_i].time);
            printf("Longest period end: %s %s\n", records[last_i].date, records[last_i].time);
            break;
        };
        case 'Q':
        case 'q': 
                return 0;
                break;

        default: 
            printf("%s\n","Invalid choice.Try again.");
            break;
    };
};
    return 0;

}












