#include "file.h"

void write_file(const char *file_name, stack *head, int colum_width){
    FILE *file = fopen(file_name, "w");
    publication *p;
    if (strstr(file_name, ".csv") != NULL){
        for (int i = 0; i < stack_size(head); i++){
            p = get_element_by_index(head, i);
            char *tf = yes_no(p->in_RINC);
            fprintf(file, "%s,%s,%s,%s,%d,%d,%s,%d,%d", p->name_publication, p->surname, p->iinitials, p->name_journal, p->date,p->tom, tf, p->pages, p->cout_quotes);
            free(tf);
            if (i < stack_size(head) - 1) {
                fprintf(file, "\n"); 
            }
        }
    } else if (strstr(file_name, ".txt") != NULL){
        fprintf(file, "%-*s%-*s%-*s%-*s%-*d%-*d%-*s%-*d%-*d\n",colum_width, "Название публикации", colum_width, "Фамилия", colum_width, "Инициалы", colum_width, "Название журнала", colum_width, "Год публикации", colum_width, "Том", colum_width, "Входит в РИНЦ", colum_width, "Страницы", colum_width, "Голоса");
        for (int i = 0; i < stack_size(head); i++){
            p = get_element_by_index(head, i);
            char *tf = yes_no(p->in_RINC);
            fprintf(file, "%-*s%-*s%-*s%-*s%-*d%-*d%-*s%-*d%-*d",colum_width, p->name_publication, colum_width, p->surname, colum_width, p->iinitials, colum_width, p->name_journal, colum_width, p->date, colum_width, p->tom, colum_width, tf, colum_width, p->pages, colum_width, p->cout_quotes);
            free(tf);
            if (i > stack_size(head) - 1) {
                fprintf(file, "\n");
            }
        }
    }
    fclose(file);
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
        char *str;
        int i = 0;
        while (token != NULL){
            str = (char *)malloc(strlen(token) + 1);
            if (i == 0){
                pub->name_publication = (char *)malloc(strlen(token) + 1);
                strcpy(pub->name_publication, token);
            } else if (i == 1){
                pub->surname = (char *)malloc(strlen(token) + 1);
                strcpy(pub->surname, token);
            } else if (i == 2){
                pub->iinitials = (char *)malloc(strlen(token) + 1);
                strcpy(pub->iinitials, token);
            } else if (i == 3){
                pub->name_journal = (char *)malloc(strlen(token) + 1);
                strcpy(pub->name_journal, token);
            } else if (i == 4){
                pub->date = atoi(token);
            } else if (i == 5){
                pub->tom = atoi(token);
            } else if (i == 6){
                if (strcmp(token, "YES") == 0)
                    pub->in_RINC = true;
                else
                    pub->in_RINC = false;
            } else if (i == 7){
                pub->pages = atoi(token);
            } else if (i == 8){
                pub->cout_quotes = atoi(token);
            }
            token = strtok(NULL, ","); 
            i++;
        }
        push_front(&(*head), pub);
    }
    fclose(file);
}