#include "file.h"

void write_file(const char *file_name, stack *head){
    FILE *file = fopen(file_name, "w");
    publication *p;
    for (int i = 0; i < stack_size(head); i++){
        p = get_element_by_index(head, i);
        fprintf(file, "%d,%d\n", p->pages, p->cout_quotes);
    }
}

void read_file(const char *file_name, stack **head){
    FILE *file = fopen(file_name, "r");
    char *line = NULL;  
    size_t len = 0;    
    size_t read;

    if (file == NULL) {
        printf("Не удалось открыть файл для чтения.\n");
        return;
    }
    while ((read = getline(&line, &len, file)) != -1){
        publication *pub = creat_publication();
        char *token = strtok(line, ",");
        int i = 0;
        while (token != NULL){
            if (i == 0){
                pub->pages = atoi(token);
            }  else if (i == 1){
                pub->cout_quotes = atoi(token);
            }
            token = strtok(NULL, ","); 
            i++;
        }
        push_front(&(*head), pub);
    }
}