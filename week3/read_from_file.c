#include <stdio.h>

int main() {
    char test [] = "data.txt";
    FILE *file = fopen(test, "r");
    if (file == NULL) {
        perror("");
        return 1;
    }

    int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        printf("%s", line_buffer);
    }

    fclose(file);
    return 0;
}