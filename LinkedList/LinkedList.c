#include <stdio.h>
#include <stdlib.h>

void die(char *str){
    fprintf(stderr, "ERROR: %s\n", str);
    exit(1);
}

typedef struct node{
    int val;
    struct node * next;
} node_t;

void print_list(node_t * head){
    node_t * current = head;

    while(current != NULL){
        printf("value: %d\n", current->val);
        current = current->next;
    }

}

void push(node_t ** head, int val){ //insert in begin
    node_t * new_node;
    new_node = (node_t *) malloc(sizeof(size_t));

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

int pop(node_t ** head){ //remove first node
    int retval = -1;
    node_t * next_node;

    if(*head == NULL)
        return -1;

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

int main(int argc, char *argv[]){

    node_t *head = NULL;
    head = (node_t *) malloc(sizeof(node_t));

    if(head == NULL){
        die("Failed to allocate memory to head");
    }

    head->val = 1;
    
    push(head, 5);
    print_list(&head);
    printf("\n");
    pop(&head);
    print_list(head);

    free(head);
    return 0;
}