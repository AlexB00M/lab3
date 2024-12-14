#include <stdio.h>
#include "data_base.h"
#include "start_params.h"
#include "file.h"
#define MAX_LEN_STRING 10
#define MIN_LEN_STRING 10
#define MAX_INT 10
#define MIN_INT 10
#define CULUM_WIDTH 50

void print_stack(stack *head);
void print_publication(publication *p);
void start(start_params *params, stack **head);
void read_file(const char *file_name, stack **head);
void print_table(stack *head, int width);
void get_str(char *str);

int main(int argc, char *argv[]){
    start_params *params = get_params(argc, argv);
    stack *head = NULL;
    start(params, &head);
    // read_file("data.csv", &head);
    // write_file("output.csv", head);
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
    // print_stack(head);
    return 0;
}

void print_table(stack *head, int width){
    publication *p;
    int colum_width = width/2;
    // printf("%-*s%-*s\n",colum_width, "Pages", colum_width, "cout_quotes");
    for (int i = 0; i < stack_size(head); i++){
        p = get_element_by_index(head, i);
        char *tf = yes_no(p->in_RINC);
        printf("%-*s%-*s%-*s%-*s%-*d%-*d%-*s%-*d%-*d\n",colum_width, p->name_publication, colum_width, p->surname, colum_width, p->iinitials, colum_width, p->name_journal, colum_width, p->date, colum_width, p->tom, colum_width, tf, colum_width, p->pages, colum_width, p->cout_quotes);
        free(tf);
    }   
}

void print_stack(stack *head){
    publication *p;
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i < stack_size(head); i++){
        p = get_element_by_index(head, i);
        printf("%s,%s,%s,%s,%d,%d,%s,%d,%d\n", p->name_publication, p->surname, p->iinitials, p->name_journal, p->date,p->tom, yes_no, p->pages, p->cout_quotes);
    }
}

void print_publication(publication *p){
    printf("pages: %d, cout_quotes: %d\n", p->pages, p->cout_quotes);
}

void get_str(char *str){
    int c;
    int i = 0;
    while ((c = getchar()) != '\n'){
        str[i] = c;
        i++;
    }
    str[i] = '\0';
}

void start(start_params *params, stack **head){
    printf("%s %s %s %d %s\n", params->command, params->file_name_in, params->file_name_out, params->generate, params->sort_type);
    if (strcmp(params->command, "-P") == 0){
        if (params->file_name_in == NULL){
            params->file_name_in = (char *)malloc(100);
            scanf("%s", params->file_name_in);
        }
        read_file(params->file_name_in, &(*head));
        if (params->file_name_out == NULL){
            print_table(*head, CULUM_WIDTH);
        } else {
            write_file(params->file_name_out, *head, CULUM_WIDTH);
        }
    } else if (strcmp(params->command, "-g") == 0){
        generate_stack(params->generate, &(*head), MAX_LEN_STRING, MIN_LEN_STRING, MAX_INT, MIN_INT);
        if (params->file_name_out == NULL){
            print_stack(*head);
        } else {
            write_file(params->file_name_out, *head, CULUM_WIDTH);
        }
    } else if (strcmp(params->command, "-s") == 0){

    }
}
