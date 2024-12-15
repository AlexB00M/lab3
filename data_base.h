#pragma once
#include <stdlib.h>
#include "publication.h"
#include "random.h"

typedef struct stack{
    publication *pub;
    struct stack *before;
}stack;

// Initiatisation
stack *create_stack(stack *before);

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

// Tail
stack *stack_tail(stack *head);

// Ptr
publication *next_element(stack *head, publication *pub);
publication *prev_element(stack *head, publication *pub);

// Change
void change_elements(stack **head, publication *pub1, publication *pub2);

// Generate
void generate_stack(int n, stack **head);

// Clean
void clean_stack(stack **head);
void clean_array(publication **array);

// Array
publication **stack_to_array(stack **head);
stack *array_to_stack(publication **array, int size);