#include <stdlib.h>
#include <stdbool.h>

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
    publication *before;
}publication;

typedef struct data_base{
    size_t size;
    publication *head;  
    publication *tail;
}data_base;

publication *creat_publication(char *name_publication, char *surname, char *iinitials, char *name_journal, int date, int tom, bool in_RINC, int pages, int cout_quotes);
data_base *init_base();

void push_at_ptr(data_base *base, publication *pub);
void push_front(data_base *base, publication *pub);
void push_end(data_base *base, publication *pub);

void pop_at_ptr(data_base *base, publication *ptr);
void pop_front(data_base *base);
void pop_end(data_base *base);

int base_size(data_base *base);
publication *base_head(data_base *base);
publication *base_tail(data_base *base);

publication *next_at_ptr(publication *pub);
publication *prev_at_ptr(publication *pub);
