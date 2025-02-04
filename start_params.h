#pragma once
#include <string.h>
#include <stdlib.h>

typedef struct start_params{
    char *command;
    char *file_name_in;
    char *file_name_out;
    int generate;
    char *sort_type;
} start_params;

start_params *get_params(int argc, char *argv[]);