#include "rsrc.h"

void fatal_error(const char *str){
    fprintf(stderr, "Fatal Error: %s\n", str);
    exit(-1);
}

void error(const char *str){
    printf("Error: %s\n", str);
}

