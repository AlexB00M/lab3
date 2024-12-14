#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct publication{
    char *name_publication;
    char *surname;
    char *iinitials;
    char *name_journal;
    int date;
    int tom;
    bool in_RINC;
    int pages;
    int cout_quotes;
}publication;

publication *creat_publication();
char *yes_no(bool a);