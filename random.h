#pragma once
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

void init_random();
int random_int(int max, int min);
bool rangdom_bool();
char *random_string(char **strings, int size);