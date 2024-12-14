#include <stdio.h>
#include "data_base.h"
#include "start_params.h"
#include "file.h"

void print_stack(stack *head);
void print_publication(publication *p);
void write_file(const char *file_name, stack *head);
void start(start_params *params, stack **head);
void read_file(const char *file_name, stack **head);

int main(int argc, char *argv[]){
    start_params *params = get_params(argc, argv);
    // start(params, head);
    stack *head = NULL;
    read_file("data.csv", &head);
    write_file("output.csv", head);
    // printf("%s %s %s %d %s", params->command, params->file_name_in, params->file_name_out, params->generate, params->sort_type);
    // publication *pub1 = creat_publication(1, 1);
    // publication *pub2 = creat_publication(2, 2);
    // publication *pub3 = creat_publication(3, 3);
    // publication *pub4 = creat_publication(4, 4);
    // push_front(&head, pub1);
    // print_stack(head);
    // push_front(&head, pub2);
    // print_stack(head);
    // push_front(&head, pub3);
    // print_stack(head);
    // push_front(&head, pub4);
    // print_stack(head);
    // printf("###########\n");
    // change_elements(&head, pub1, pub4);
    print_stack(head);
    return 0;
}
void print_stack(stack *head){
    stack *p = head;
    int i = stack_size(p) - 1;
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    while (p != NULL){
        printf("%d) pages: %d, cout_quotes: %d\n", i, p->pub->pages, p->pub->cout_quotes);
        p = p->before;
        i--;
    }
    printf("\n");
}

void print_publication(publication *p){
    printf("pages: %d, cout_quotes: %d\n", p->pages, p->cout_quotes);
}

void start(start_params *params, stack **head){
    if (strcmp(params->command, "-P")){
        if (params->file_name_in == NULL){
            scanf("%s", params->file_name_in);
        }
        if (params->file_name_out == NULL){
            
        }
    } else if (strcmp(params->command, "-g")){

    } else if (strcmp(params->command, "-s")){

    }
}
