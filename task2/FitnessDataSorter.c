#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/// TASK 3 --------------------------------
// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FITNESS_DATA;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}


int main() {
    /*
     Ask the user for a filename.Enter filename:1. Your program should ensure that the filename provided is a valid file (able to be opened by C), 
     andthat all of the data inside the file is in the correct format
      (for example, 12-15-2023,,200 would beinvalid as the time is missing). 
      If the file does not exist or if it contains invalid data, your programshould give a suitable error message, return 1, and exit:Error: invalid file2.
       If the file exists then your program should read the file into an array, and 
       sort the data in descendingorder of steps (highest number of steps at the top, smallest number at the bottom). 
       If two recordshave the same step count, these should be consecutive but the order does not matter.3.
        Write out the sorted data file with the same filename, but with the file extension .tsv added to it.
     Once this is complete, return 0 to exit successfully
    */
    int buffer_size=10000;
    FITNESS_DATA records[buffer_size]; 

    char line_buffer[buffer_size];
    char filename[buffer_size];

    // get filename from the user
    printf("Enter Filename: ");

    // these lines read in a line from the stdin (where the user types)
    // and then takes the actual string out of it
    // this removes any spaces or newlines.
    fgets(line_buffer, buffer_size, stdin);
    sscanf(line_buffer, " %s ", filename);

    counter=0;

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: Invalid File\n");
        return 1;
    }

    while (fgets(line_buffer, buffer_size, file) != NULL) 
    {
        tokeniseRecord (line_buffer,",", records[counter].date, records[counter].time, records[counter].steps);
        counter++;

    };

    fclose(file);

    //sort data in descending order- while?

    //create file



    //write in file

    //print Data sorted and written to FitnessData_2023.csv.tsv
}
