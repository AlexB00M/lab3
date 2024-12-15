#include <stdio.h>
#include "data_base.h"
#include "start_params.h"
#include "file.h"
#include "sort.h"
#define WIDTH 40

void print_stack(stack *head);
void print_publication(publication *p);
void start(start_params *params, stack **head);
void read_file(const char *file_name, stack **head);
void print_table(stack *head, int colum_width);
void get_str(char *str);
void read_input(stack **head);

int main(int argc, char *argv[]){
    start_params *params = get_params(argc, argv);
    stack *head = NULL;
    start(params, &head);
    return 0;
}

void print_table(stack *head, int colum_width){
    publication *p;;
    printf("%-50s%-20s%-10s%-50s%-10s%-10s%-10s%-10s%-10s\n","Название публикации","Фамилия","Инициалы", "Название журнала", "Год публикации", "Том", "Входит в РИНЦ", "Страницы", "Голоса");
    for (int i = 0; i < stack_size(head); i++){
        p = get_element_by_index(head, i);
        char *tf = yes_no(p->in_RINC);
        printf("%-50s%-20s%-10s%-50s%-10d%-10d%-10s%-10d%-10d\n",p->name_publication, p->surname, p->iinitials, p->name_journal, p->date, p->tom, tf, p->pages, p->cout_quotes);
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
        char *tf = yes_no(p->in_RINC);
        printf("%s,%s,%s,%s,%d,%d,%s,%d,%d\n", p->name_publication, p->surname, p->iinitials, p->name_journal, p->date,p->tom, tf, p->pages, p->cout_quotes);
        free(tf);
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
    // printf("%s %s %s %d %s\n", params->command, params->file_name_in, params->file_name_out, params->generate, params->sort_type);
    int n;
    if (strcmp(params->command, "-P") == 0){
        if (params->file_name_in == NULL){
            params->file_name_in = (char *)malloc(100);
            scanf("%s", params->file_name_in);
        }
        read_file(params->file_name_in, head);
        if (params->file_name_out == NULL){
            print_table(*head, WIDTH);
        } else {
            write_file(params->file_name_out, *head, WIDTH);
        }
    } else if (strcmp(params->command, "-g") == 0){
        generate_stack(params->generate, head);
        if (params->file_name_out == NULL){
            print_stack(*head);
        } else {
            write_file(params->file_name_out, *head, WIDTH);
        }
    } else if (strcmp(params->command, "-s") == 0){
        if (params->file_name_in != NULL){
            read_file(params->file_name_in, head);
        } else {
            read_input(head);
        }
        if (params->sort_type == NULL){
            sort(head, 0, compare_publications);
        } else if (strcmp(params->sort_type, "asc") == 0 || strcmp(params->sort_type, "A") == 0){
            sort(head, 0, compare_publications); 
        } else {
            sort(head, 1, compare_publications);
        }
        if (params->file_name_out != NULL){
            write_file(params->file_name_out, *head, WIDTH);
        } else {
            print_stack(*head);
        }
    }
}

void read_input(stack **head){
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("Введите строки данных в формате CSV (для завершения нажмите Ctrl+Z):\n");

    while ((read = getline(&line, &len, stdin)) != -1) {
        publication *pub = creat_publication();
        char *token = strtok(line, ",");
        int i = 0;

        while (token != NULL) {
            if (i == 0) {
                pub->name_publication = strdup(token);
            } else if (i == 1) {
                pub->surname = strdup(token);
            } else if (i == 2) {
                pub->iinitials = strdup(token);
            } else if (i == 3) {
                pub->name_journal = strdup(token);
            } else if (i == 4) {
                pub->date = atoi(token);
            } else if (i == 5) {
                pub->tom = atoi(token);
            } else if (i == 6) {
                pub->in_RINC = (strcmp(token, "YES") == 0);
            } else if (i == 7) {
                pub->pages = atoi(token);
            } else if (i == 8) {
                pub->cout_quotes = atoi(token);
            }
            token = strtok(NULL, ",");
            i++;
        }
        push_front(&(*head), pub);
    }
    free(line);
}