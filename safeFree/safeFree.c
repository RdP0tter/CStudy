#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void s_free(void **ptr){
  if(ptr!=NULL && *ptr!=NULL){
    free(*ptr);
    *ptr = NULL;
  }
}

#define safeFree(p) s_free((void**)&(p))

void AllocateArray( int **arr, int size, int value ){

  *arr = (int*)malloc(sizeof(int));
  if(*arr != NULL){
    for(int i=0;i<size;i++){
      *(*arr+i) = value;
    }
  }

}

int main(){
  
  int *vector = NULL;
  AllocateArray(&vector, 5, 45);
  safeFree(vector);

  return 0;
}
