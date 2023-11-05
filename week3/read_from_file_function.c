#include <stdio.h> 
#include <stdlib.h> // Defines exit().

FILE *open_file(char test[], char mode[]) {
    FILE *file = fopen(test, mode);
    if (file == NULL) {
        perror("");
        exit(1);
    }
    return file;
}

int main() {
    char test [] = "data.txt";
    FILE *file = open_file(test, "r");

    int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        printf("%s", line_buffer);
    }

    fclose(file);
    return 0;
}