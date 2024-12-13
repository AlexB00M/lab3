#include "data_base.h"
#include <stdio.h>
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
//char *name_publication, char *surname, char *iinitials, char *name_journal, int date, int tom, bool in_RINC, int pages, int cout_quotes
publication *creat_publication(int pages, int cout_quotes){
    publication *pub = (publication *)malloc(sizeof(publication));

    // pub->name_publication = name_publication;
    // pub->surname = surname;
    // pub->iinitials = iinitials;
    // pub->name_journal = name_journal;
    // pub->date = date;
    // pub->tom = tom;
    // pub->in_RINC = in_RINC;
    pub->pages = pages;
    pub->cout_quotes = cout_quotes;
    return pub;
}

// skack *head = create_stack()
stack *create_stack(stack *before){
    stack *st = (stack *)malloc(sizeof(stack));
    st->pub = (publication *)malloc(sizeof(publication));
    st->before = before;
    return st;
}

stack *get_ptr_by_index(stack *head, int index){
    int size = stack_size(head);
    printf("%d\n",size);
    if (index < size && index >= 0){
        stack *head_tmp = head;
        for (int i = size - 1; i > index; i--)
            head_tmp = head_tmp->before;
        return head_tmp;
    } else if (index == 0 && size == 0){
        return head;
    } else {
        return NULL;
    }
}

int push_to_index(stack **head, publication *pub, int index){
    stack *p = get_ptr_by_index(*head, index);
    if (p != NULL){
        stack *st = create_stack(p->before);
        st->pub = pub;
        p->before = st; 
        return 1;
    } else {
        return 0; // index out of range
    }
}

void push_front(stack **head, publication *pub){
    stack *st = create_stack(*head);
    st->pub = pub;
    *head = st;
}

void push_end(stack **head, publication *pub){
    stack *p = get_ptr_by_index(*head, 0);
    if (*head != NULL){
        stack *st = create_stack(NULL);
        p->before = st;
        st->pub = pub;
    } else {
        stack *st = create_stack(NULL);
        st->pub = pub;
        *head = st;
    }
}   

void pop_at_ptr(stack **head, publication *ptr){

}

void pop_front(stack **head){

}

void pop_end(stack **head){
    
}

int stack_size(stack *head){
    stack *head_tmp = head;
    int size = 0;
    while (head_tmp != NULL){
        head_tmp = head_tmp->before;
        size++;
    }
    return size;
}

stack *stack_tail(stack *head){
    stack *p = get_ptr_by_index(head, 0);
    if (p != NULL)
        return get_ptr_by_index(head, 0);
    return NULL; // no elements
}

stack *next_at_ptr(stack *head, publication *pub){

}

stack *prev_at_ptr(stack *head, publication *pub){
    
}