#include <string.h>
#include <stdlib.h>

typedef struct publication{
    char *name_publication;
    char *surname;
    char *iinitials;
    char *name_journal;
    int date;
    int tom;
    bool in_RINC;
    int pages;
    int cout_quotes;
}publication;

typedef struct data_base{
    size_t size;
    publication *head;
    publication *tail;
}data_base;

publication *creat_publication();
data_base *init_base();

void push_at_ptr(data_base *base, publication *ptr);
void push_front(data_base *base);
void push_end(data_base *base);

void pop_at_ptr(data_base *base, publication *ptr);
void pop_front(data_base *base);
void pop_end(data_base *base);

void base_size(data_base *base);
void base_head(data_base *base);
void base_tail(data_base *base);

void next_at_ptr(publication *pub);
void prev_at_ptr(publication *pub);
