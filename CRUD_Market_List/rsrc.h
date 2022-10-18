#ifndef __RSRC_H
#define __RSRC_H

#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

struct file_opt {
  char *filepath;
  char *crud_arg;
  char *str;
};

void fatal_error(const char *str);
void error(const char *str);
void create(struct file_opt *file);
void read(struct file_opt *file);
void delete_file(struct file_opt *file);

#endif
