#include "start_params.h"

void print(char*argv){
    
}

void generate(char *argv){

}

start_params *get_params(int argc, char *argv[]){
    start_params *params = (start_params *)malloc(sizeof(start_params));
    params->command = NULL;
    params->file_name_in = NULL;
    params->file_name_out = NULL;
    params->sort_type = NULL;
    char *str;

    for (int i = 1; i < argc; i++){

        if (strcmp(argv[i], "-P") == 0 || strcmp(argv[i], "-print") == 0) {
            params->command = "-P";
        } else if (strcmp(argv[i], "-g") == 0 || strcmp(argv[i], "--generate") == 0) {
            params->generate = atoi(argv[i + 1]);
        } else if (strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--sort") == 0) {
            params->command = "-s";
        }

        if (strcmp(argv[i], "-o") == 0){
            params->file_name_out = (char *)malloc(strlen(argv[i + 1]) + 1);
            strcpy(params->file_name_out, argv[i + 1]);
        } else if ((str = strstr(argv[i], "--out=")) != NULL){
            params->file_name_out = (char *)malloc(strlen(str + 6) + 1);
            strcpy(params->file_name_out, str + 6);
        }

        if (strcmp(argv[i], "-i") == 0){
            params->file_name_in = (char *)malloc(strlen(argv[i + 1]) + 1);
            strcpy(params->file_name_in, argv[i + 1]);
        } else if ((str = strstr(argv[i], "--in=")) != NULL){
            params->file_name_in = (char *)malloc(strlen(str + 5) + 1);
            strcpy(params->file_name_in, str + 5);
        }

        if (strcmp(argv[i], "-t") == 0){
            params->sort_type = (char *)malloc(strlen(argv[i + 1]) + 1);
            strcpy(params->sort_type, argv[i + 1]);
        } else if ((str = strstr(argv[i], "--type=")) != NULL){
            params->sort_type = (char *)malloc(strlen(str + 7) + 1);
            strcpy(params->sort_type, str + 7);
        }
        free(str);
    } 
    return params;
}

