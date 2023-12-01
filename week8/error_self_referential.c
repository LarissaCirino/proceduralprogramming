#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    struct list *next_element;
} list;

int main()
{
    list *head = NULL;
    head = malloc(sizeof(list));
    head->data = 10;
    head->next_element = malloc(sizeof(list));
    list *current_element = head->next_element;
    current_element->data= 20;
    current_element->next_element= NULL;
    free(head);
    free(current_element);
    
    return 0; 
    
    
    //list first_node;
    //list second_node;
    //first_node.data


    // Run this program. Learn from the error. 

    // Why the error. 
}