#include "data_base.h"
#include <stdio.h>

stack *create_stack(stack *before){
    stack *st = (stack *)malloc(sizeof(stack));
    st->pub = (publication *)malloc(sizeof(publication));
    st->before = before;
    return st;
}

stack *get_ptr_by_index(stack *head, int index){
    int size = stack_size(head);
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

publication *get_element_by_index(stack *head, int index){
    return get_ptr_by_index(head, index)->pub;
}

int push_index(stack **head, publication *pub, int index){
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

int pop_index(stack **head, int index){
    if (*head != NULL){
        if (index == stack_size(*head) - 1){
            pop_front(head);
        } else if (index == 0){
            pop_end(head);
        } else {
            stack *tmp = get_ptr_by_index(*head, index + 1);
            stack *to_del = tmp->before;
            tmp->before = tmp->before->before;
            free(to_del);
            return 1;
        }
    } else {
        return 0;
    }
}

int pop_front(stack **head){
    if (*head != NULL){
        stack *tmp = *head;
        *head = (*head)->before;
        free(tmp);
        return 1;
    } else {
        return 0;// no elements
    }
}

int pop_end(stack **head){
    if (*head != NULL){
        stack *tmp = get_ptr_by_index(*head, 1);
        free(tmp->before);
        tmp->before = NULL;
        return 1;
    } else {
        return 0;
    }
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

publication *next_element(stack *head, publication *pub){
    stack *tmp = head;
    while (tmp->before->pub != pub){
        tmp = tmp->before;
    }
    return tmp->pub;
}

publication *prev_element(stack *head, publication *pub){
    stack *tmp = head;
    while (tmp->pub != pub){
        tmp = tmp->before;
    }
    return tmp->before->pub; 
}

stack *next_stack(stack *head, publication *pub) {
    stack *tmp = head;
    while (tmp != NULL && tmp->before != NULL) {
        if (tmp->before->pub == pub) {
            return tmp;
        }
        tmp = tmp->before;
    }
    return NULL;
}
    char *name_publication;
    char *surname;
    char *iinitials;
    char *name_journal;
    int date;
    int tom;
    bool in_RINC;
    int pages;
    int cout_quotes;

void clean_stack(stack **head){
    stack *tmp = *head;
    while (tmp != NULL) {
        free(tmp->pub->name_publication);
        free(tmp->pub->surname);
        free(tmp->pub->iinitials);
        free(tmp->pub->name_journal);
        
        stack *next = tmp->before;
        free(tmp->pub);
        free(tmp);
        tmp = next;
    }

    *head = NULL;
}

void clean_array(publication **array){
    int size = sizeof(array)/sizeof(publication);
    for (int i = 0; i < size; i++) {
        free(array[i]->name_publication);
        free(array[i]->surname);
        free(array[i]->iinitials);
        free(array[i]->name_journal);
        free(array[i]);
    }

    free(array);
}
void change_elements(stack **head, publication *pub1, publication *pub2) {
    if (pub1 == pub2) return;

    stack *prev1 = NULL, *prev2 = NULL;
    stack *st1 = NULL, *st2 = NULL;

    if ((*head)->pub != pub1) prev1 = next_stack(*head, pub1);
    if ((*head)->pub != pub2) prev2 = next_stack(*head, pub2);

    st1 = (prev1 == NULL) ? *head : prev1->before;
    st2 = (prev2 == NULL) ? *head : prev2->before;

    if (st1 == NULL || st2 == NULL) return;

    if (prev1 != NULL) prev1->before = st2;
    else *head = st2; 

    if (prev2 != NULL) prev2->before = st1;
    else *head = st1; 

    stack *temp = st1->before;
    st1->before = st2->before;
    st2->before = temp;
}

void generate_stack(int n, stack **head, int max_len_string, int min_len_string, int max_int, int min_int){
    init_random();
    for (int i = 0; i < n; i++){
        publication *pub = creat_publication();

        pub->name_publication = random_string(max_len_string, min_len_string);
        pub->surname = random_string(max_len_string, min_len_string);
        pub->iinitials = random_string(max_len_string, min_len_string);
        pub->name_journal = random_string(max_len_string, min_len_string);
        pub->date = random_int(max_int, min_int);
        pub->tom = random_int(max_int, min_int);
        pub->in_RINC = rangdom_bool();
        pub->pages = random_int(max_int, min_int);
        pub->cout_quotes = random_int(max_int, min_int);

        push_front(&(*head), pub);
    }

}

publication **stack_to_array(stack **head){
    int size = stack_size(*head);
    publication **array = (publication **)malloc(sizeof(publication*)*size);
    for(int i = 0; i < size; i++){
        *(array + i) = get_element_by_index(*head, i);
    }
    *head = NULL;
    clean_stack(head);
    return array;
}

stack *array_to_stack(publication **array, int size){
    printf("%d\n", size);
    stack *head = NULL;
    for (int i = 0; i < size; i++){
        push_front(&head, array[i]);
    }
    clean_array(array);
    return head;
}