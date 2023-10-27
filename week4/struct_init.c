#include <stdio.h>

struct student {
    char name [20];
    char student_id [11]; // Assuming 10 digits.
    unsigned mark;
};

int main () {
    struct student new_student= {
    printf("Insert data [name, id, mark]\n")};

    scanf("%s", *&new_student.name);
    scanf("%s", *&new_student.student_id);
    scanf("%d", &new_student.mark);
return 0;
}