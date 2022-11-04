#include <stdio.h>
#include <stdlib.h>

struct LL{
    int data;
    struct LL* next;
};

typedef struct LL * node;

// returns 0 if was already in list and add was unsuccessful
// returns 1 if add was successful.
int grow_that_list(int an_int, node* head) {
    node curr = *head; // pointer to start of list
    node prev = NULL; // pointer to prev.
    // finds the position where the node is no longer the smallest in list
    while (curr != NULL && curr->data <= an_int) {
        if (curr->data == an_int) {
            return 0; // ret 0 for add failure
        } 
        prev = curr;
        curr = curr->next;
    }
    // creates a new node and inserts in said position
    node nu = (node)malloc(sizeof(struct LL));
    nu->data = an_int;
    nu->next = curr;
    if (prev != NULL) { prev->next = nu; }
    else { *head = nu; } // if is our new head
    return 1; // ret 1 for add success
}

int main(int argc, char** argv) {
    printf("hello world");

    node a_head = NULL;

    for( int i = 0; i < 20; ++i) {
        int random_int = rand() % 30;

        printf("%d\n", random_int);

        if (! grow_that_list(random_int, &a_head)) {
            printf("%d  was already in the list\n",random_int);
        }
    }
    
    for (node curr = a_head; curr != NULL; curr = curr->next) {
        printf("%d, ", curr->data);
    }
}