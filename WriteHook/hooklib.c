#include <stdio.h>
#include <dlfcn.h>
#include <string.h>

ssize_t write(int fd, const void *buf, size_t count){
    
    ssize_t (*new_write)(int fd, const void *str, size_t count);
    new_write = dlsym(RTLD_NEXT, "write");

      if(strcmp(buf, "Testing")==0){
        return new_write(fd, "hooked", 7); //+1 for the \0
      }
      else {
        return write(fd, buf, count);
      }
}
