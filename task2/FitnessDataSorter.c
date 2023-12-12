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
     andthat all of the data inside the file is in the correct format
      (for example, 12-15-2023,,200 would beinvalid as the time is missing). 
      If the file does not exist or if it contains invalid data, your programshould give a suitable error message, return 1, and exit:Error: invalid file2.

    */
    int counter=0;
    int i=0;
    int lowest_steps=0;
    int highest_i= 0;
    int buffer_size=10000;
    FITNESS_DATA records[buffer_size]; 

    char line_buffer[buffer_size];
    char filename[buffer_size];

    // get filename from the user
    printf("%s","Enter Filename: ");

    // these lines read in a line from the stdin (where the user types)
    // and then takes the actual string out of it
    // this removes any spaces or newlines.
    fgets(line_buffer, buffer_size, stdin);
    sscanf(line_buffer, " %s ", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: Invalid File\n");
        return 1;
    }

    while (fgets(line_buffer, buffer_size, file) != NULL) 
    {
        tokeniseRecord (line_buffer,',', records[counter].date, records[counter].time, &records[counter].steps);
        counter++;

    }
    
    fclose(file);

    strcat(filename, ".tsv");
    FILE *newfile = fopen(filename, "w");
    if (newfile == NULL) 
    {
        perror("");
        return 1;
    }
    //if (fgets(line_buffer, buffer_size, newfile) == NULL)


    int j=0;
    for (i=0; i<counter; i++)
    {
        for (j=i+1; j<counter+1; j++)
        {
            if (records[i].steps<records[j].steps)
            {
                highest_i=j;
                lowest_steps= records[i].steps;
                records[i].steps= records[highest_i].steps;
                records[highest_i].steps= lowest_steps;
                char time[6];
                strcpy(time, records[i].time);
                strcpy(records[i].time, records[highest_i].time);
                strcpy(records[highest_i].time, time);
                char date[11];
                strcpy(date, records[i].date);
                strcpy(records[i].date, records[highest_i].date);
                strcpy(records[highest_i].date, date);
            }   
        }
        
        fprintf(newfile, "%s\t%s\t%d\n", records[i].date, records[i].time, records[i].steps);

    }
    
    fclose(newfile);
    
    printf("Data sorted and written to %s\n", filename);

    return 0;

}
