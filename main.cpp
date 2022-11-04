#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;
};

bool grow_that_list(int an_int, node** head) {
    node* curr = *head; // pointer to start of list
    node* prev = NULL; // pointer to prev.
    // finds the position where the node is no longer the smallest in list
    while ( curr != NULL && curr->data <= an_int) {
        if (curr->data == an_int) {
            return false;
        } 
        prev = curr;
        curr = curr->next;
    }
    // creates a new node and inserts in said position
    node* nu = new node();
    nu->data = an_int;
    nu->next = curr;
    if (prev != NULL) { prev->next = nu; }
    else { *head = nu; } // if is our new head
    return true;
}

int main(int argc, char * argv[]) {
    node* a_head = NULL;
    printf("why isn't this working???\n");

    for( int i = 0; i < 20; ++i) {
        int random_int = rand() % 30;

        std::cout << random_int << std::endl;
        if (!grow_that_list(random_int, &a_head)) {
            std::cout << random_int << " was already in the list\n";
        }
    }

    std::cout << "yes, we are in it..." << std::endl;

    for (node* curr = a_head; curr != NULL; curr = curr->next) {
        std::cout << curr->data << ", ";
    }
}