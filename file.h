#pragma once
#include "data_base.h"
#include <stdio.h>
#include <string.h>
void write_file(const char *file_name, stack *head, int colum_width);
void read_file(const char *file_name, stack **head);