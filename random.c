#include "random.h"


void init_random() {
    srand(time(NULL));
}

bool rangdom_bool(){
    int a = random_int(2, 0);
    if (a == 1){
        return true;
    } else {
        return false;
    }
}

int random_int(int min, int max){
    return rand() % (max - min + 1) + min;
}

char *random_string(char **strings, int size){
    int i = random_int(0, size - 1);
    char *s = (char *)malloc(strlen(strings[i]) + 1);
    strcpy(s, strings[i]);
    return s;
}