#pragma once
#include "data_base.h"
#include <stdio.h>
#include <string.h>

void write_file(char *file_name, stack *head);
void read_file(char *file_name, stack **head);