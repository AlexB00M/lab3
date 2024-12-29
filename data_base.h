#pragma once
#include <stdlib.h>
#include "publication.h"
#include "random.h"

typedef struct stack{
    publication *pub;
    struct stack *before;
}stack;

stack *create_stack(stack *before);

stack *get_ptr_by_index(stack *head, int index);
stack *next_stack(stack *head, publication *pub);
publication *get_element_by_index(stack *head, int index);

int stack_size(stack *head);

int push_index(stack **head, publication *pub, int index);
void push_front(stack **head, publication *pub);
void push_end(stack **head, publication *pub);

int pop_index(stack **head, int index);
int pop_front(stack **head);
int pop_end(stack **head);

stack *stack_tail(stack *head);

publication *next_element(stack *head, publication *pub);
publication *prev_element(stack *head, publication *pub);

void change_elements(stack **head, publication *pub1, publication *pub2);

void generate_stack(int n, stack **head);

void clean_stack(stack **head);
void clean_array(publication **array);

publication **stack_to_array(stack **head);
stack *array_to_stack(publication **array, int size);