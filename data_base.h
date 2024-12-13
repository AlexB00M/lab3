#include <stdlib.h>
#include <stdbool.h>

typedef struct publication{
    // char *name_publication;
    // char *surname;
    // char *iinitials;
    // char *name_journal;
    // int date;
    // int tom;
    // bool in_RINC;
    int pages;
    int cout_quotes;
}publication;


typedef struct stack{
    publication *pub;
    struct stack *before;
}stack;

// Initiatisation
stack *create_stack(stack *before);//char *name_publication, char *surname, char *iinitials, char *name_journal, int date, int tom, bool in_RINC,
publication *creat_publication(int pages, int cout_quotes);

// Index
stack *get_ptr_by_index(stack *head, int index);

// Size
int stack_size(stack *head);

// Push
int push_to_index(stack **head, publication *pub, int index);
void push_front(stack **head, publication *pub);
void push_end(stack **head, publication *pub);

// Pop
void pop_at_ptr(stack **head, publication *ptr);
void pop_front(stack **head);
void pop_end(stack **head);

// tail
stack *stack_tail(stack *head);

// Ptr
stack *next_at_ptr(stack *head, publication *pub);
stack *prev_at_ptr(stack *head, publication *pub);
