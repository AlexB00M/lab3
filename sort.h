#pragma once
#include "data_base.h"

int compare_publications(const void *a, const void *b);
void sort(stack **head, int revers, int (*compare)(const void *, const void *));