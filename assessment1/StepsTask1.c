#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, int *steps) {
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
        char step[10];
        strcpy(step, token);
        *steps= atoi(step);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {

// read in file
    char fitnessdata [] = "FitnessData_2023.csv";
    FILE *file = fopen (fitnessdata, "r");
    if (file == NULL) {
        perror("error");
        return 1;
    }

    int buffer_size = 0, i;
    char line_buffer[100];
    FITNESS_DATA records[100];
    while (fgets(line_buffer, 100, file) != NULL) {
        tokeniseRecord (line_buffer, ",", records[buffer_size].date, records[buffer_size].time, &records[buffer_size].steps);
        buffer_size= buffer_size+1;

    }

    printf("Number of records in file: %d\n",buffer_size );
    //printf("%s", records[buffer_size].date);
    for (i=0; i<3; i++){
        printf("%s/%s/%d\n", records[i].date, records[i].time, records[i].steps);
    }

    fclose (file);
    return 0;
}

// use tokeniserecord


// printout


