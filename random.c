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

int random_int(int max, int min){
    return rand() % max + min;
}

char *random_string(int max, int min){
    int length = random_int(max, min);
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *random_string = (char *)malloc(length + 1);
    int key;

    for (int i = 0; i < length; i++) {
        key = random_int(strlen(charset), 0);  
        random_string[i] = charset[key];
    }
    random_string[length] = '\0';
    return random_string;
}