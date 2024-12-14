#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include "publication.h"

typedef struct stack{
    publication *pub;
    struct stack *before;
}stack;

// Initiatisation
stack *create_stack(stack *before);//char *name_publication, char *surname, char *iinitials, char *name_journal, int date, int tom, bool in_RINC, 

// Index
stack *get_ptr_by_index(stack *head, int index);
stack *next_stack(stack *head, publication *pub);
publication *get_element_by_index(stack *head, int index);

// Size
int stack_size(stack *head);

// Push
int push_index(stack **head, publication *pub, int index);
void push_front(stack **head, publication *pub);
void push_end(stack **head, publication *pub);

// Pop
int pop_index(stack **head, int index);
int pop_front(stack **head);
int pop_end(stack **head);

// tail
stack *stack_tail(stack *head);

// Ptr
publication *next_element(stack *head, publication *pub);
publication *prev_element(stack *head, publication *pub);

// Change
void change_elements(stack **head, publication *pub1, publication *pub2);