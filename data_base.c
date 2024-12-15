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

void generate_stack(int n, stack **head){
    init_random();
    for (int i = 0; i < n; i++){
        publication *pub = creat_publication();
        char *names[] = {"The Future of Artificial Intelligence", "Advancements in Machine Learning", "Exploring Quantum Computing", "Trends in Web Development", "Cloud Computing: The Next Frontier", "The Rise of Edge Computing", "Understanding Cybersecurity in 2024", "Innovations in Data Science", "The Impact of 5G on Technology", "Automation in the Modern Workplace", "Blockchain and Its Applications", "The Evolution of Digital Marketing", "Exploring the Metaverse", "AI and the Future of Healthcare", "The Role of Big Data in Decision Making", "Sustainable Technologies for the Future", "Virtual Reality: Revolutionizing Entertainment", "The Internet of Things: Connecting the World", "The Ethics of Artificial Intelligence", "Future Trends in Software Development"};
        char *surnames[] = {"Smith", "Johnson", "Brown", "Taylor", "Williams", "Jones", "Davis", "Miller", "Wilson", "Moore", "Anderson", "Thomas", "Jackson", "White", "Harris", "Martin", "Thompson", "Garcia", "Martinez", "Robinson"};
        char *iinitials[] = {"A. B.", "C. D.", "E. F.", "G. H.", "I. J.", "K. L.", "M. N.", "O. P.", "Q. R.", "S. T.", "U. V.", "W. X.", "Y. Z.", "A. D.", "B. E.", "C. F.", "D. G.", "E. H.", "F. I.", "G. J."};
        char *journal_names[] = {"Tech Performance Enhancements", "Machine Learning Trends", "Web Libraries Review", "Foundations of Artificial Intelligence", "New Technologies for Startups", "Choosing the Right Technology", "Database Optimization", "Python Programming", "The Future of Front-End Development", "Working with APIs", "Introduction to Multitasking", "Docker Usage", "Artificial Intelligence Advances", "Popular CMS Overview", "Best Security Practices", "Framework Selection for Web Development", "Reinforcement Learning", "Development for IoT", "Code Optimization", "Becoming a Successful Developer"};
        pub->name_publication = random_string(names, 20);
        pub->surname = random_string(surnames, 20);
        pub->iinitials = random_string(iinitials, 20);
        pub->name_journal = random_string(journal_names, 20);
        pub->date = random_int(1950, 2024);
        pub->tom = random_int(1, 10);
        pub->in_RINC = rangdom_bool();
        pub->pages = random_int(20, 100);
        pub->cout_quotes = random_int(50, 200);

        push_front(head, pub);
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
    stack *head = NULL;
    for (int i = 0; i < size; i++){
        push_front(&head, array[i]);
    }
    clean_array(array);
    return head;
}