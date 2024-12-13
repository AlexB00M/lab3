#include <stdio.h>
#include "data_base.h"

void define_commands(int argc, char *str);
void print_stack(stack *head);

int main(int argc, char *argv[]){
    stack *head = NULL;
    publication *pub1 = creat_publication(1, 1);
    publication *pub2 = creat_publication(2, 2);
    publication *pub3 = creat_publication(3, 3);
    publication *pub4 = creat_publication(4, 4);
    push_front(&head, pub1);
    print_stack(head);
    push_to_index(&head, pub2, 0);
    print_stack(head);
    push_to_index(&head, pub3, 1);
    print_stack(head);
    push_to_index(&head, pub4, 2);
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
}
// void define_commands(int argc, char *argv){
//     for  (int i; i < argc; i++){

//     }
// }