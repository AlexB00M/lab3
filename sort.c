#include "sort.h"

int compare_publications(const void *a, const void *b) {
    const publication *pub_a = (const publication *)a;
    const publication *pub_b = (const publication *)b;
    int str_compare;

    if (pub_a->date < pub_b->date) return -1;
    if (pub_a->date > pub_b->date) return 1;

    if (pub_a->pages < pub_b->pages) return -1;
    if (pub_a->pages > pub_b->pages) return 1;

    if (pub_a->cout_quotes < pub_b->cout_quotes) return -1;
    if (pub_a->cout_quotes > pub_b->cout_quotes) return 1;
    
    if (pub_a->tom < pub_b->tom) return -1;
    if (pub_a->tom > pub_b->tom) return 1;

    if (pub_a->in_RINC < pub_b->in_RINC) return -1;
    if (pub_a->in_RINC > pub_b->in_RINC) return 1;

    if ((str_compare = strcmp(pub_a->name_publication, pub_b->name_publication)) != 0) return str_compare;
    if ((str_compare = strcmp(pub_a->surname, pub_b->surname)) != 0) return str_compare;
    if ((str_compare = strcmp(pub_a->iinitials, pub_b->iinitials)) != 0) return str_compare;
    if ((str_compare = strcmp(pub_a->name_journal, pub_b->name_journal)) != 0) return str_compare;

}

void sort(stack **head, int revers, int (*compare)(const void *, const void *)){
    int size = stack_size(*head);

    int left = 0;
    int right = size - 1;

    while (left < right) {

        for (int i = left; i < right; i++) {
            if ((revers == 0 && compare(get_element_by_index(*head, i), get_element_by_index(*head, i + 1)) > 0) || (revers == 1 && compare(get_element_by_index(*head, i), get_element_by_index(*head, i + 1)) < 0)) {
                change_elements(head, get_element_by_index(*head, i), get_element_by_index(*head, i + 1));
            }
        }
        right--;

        for (int i = right; i > left; i--) {
            if ((revers == 0 && compare(get_element_by_index(*head, i), get_element_by_index(*head, i - 1)) < 0) || (revers == 1 && compare(get_element_by_index(*head, i), get_element_by_index(*head, i - 1)) > 0)) {
                change_elements(head, get_element_by_index(*head, i), get_element_by_index(*head, i - 1));
            }
        }
        left++;
    }  

}