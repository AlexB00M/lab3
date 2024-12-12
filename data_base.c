#include "data_base.h"
/*
Название публикации: строка
Фамилия первого автора: строка
Инициалы первого автора: строка
Название журнала: строка
Год публикации: четырехзначное число
Том журнала: целое число
Входит в РИНЦ: логическое значение
Количество страниц: целое число
Цитирований: целое число
*/
publication *creat_publication(char *name_publication, char *surname, char *iinitials, char *name_journal, int date, int tom, bool in_RINC, int pages, int cout_quotes){
    publication *pub = (publication *)malloc(sizeof(publication));

    pub->name_publication = name_publication;
    pub->surname = surname;
    pub->iinitials = iinitials;
    pub->name_journal = name_journal;
    pub->date = date;
    pub->tom = tom;
    pub->in_RINC = in_RINC;
    pub->pages = pages;
    pub->cout_quotes = cout_quotes;
    pub->before = base->head;
    return pub;
}

data_base *init_base(){
    data_base *base = (data_base *)malloc(sizeof(data_base));

    base->size = 0;
    base->head = NULL; 
    base->tail = NULL;
    return base;
}

void push_at_ptr(data_base *base, publication *pub){
    int size = base->size++;
    if(base->head == NULL){
        base->head = pub;
        base->tail = pub;
    }
}

void push_front(data_base *base, publication *pub){
    int size = base->size++;
    pub->before = base->head;
    base->head = pub;
    if(base->tail == NULL)
        base->tail = pub;
}

void push_end(data_base *base, publication *pub){
    int size = base->size++;
    pub->before = NULL;
    base->tail->before = pub;
    if(base->head == NULL)
        base->head = pub;
}   

void pop_at_ptr(data_base *base, publication *ptr){

}

void pop_front(data_base *base){

}

void pop_end(data_base *base){
    
}

int base_size(data_base *base){
    return base->size;
}

publication *base_head(data_base *base){
    return base->head;
}

publication *base_tail(data_base *base){
    return base->tail;
}

publication *next_at_ptr(publication *pub){

}

publication *prev_at_ptr(publication *pub){
    
}