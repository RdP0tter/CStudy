#ifndef __RSRC_H
#define __RSRC_H

#include <stdlib.h>
#include <stdio.h>

void fatal_error(const char *str);
void error(const char *str);

struct file_opt {
  char *filepath;
  char *crud_arg;
  char *str;
};

#endif
