#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
void print_list(struct Node* node){
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}
void insert_node(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
void delete_node(struct Node** head_ref, int key){
    struct Node *temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; 
        free(temp); 
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp); 
}
int main(){
    struct Node* head = NULL;
    insert_node(&head, 7);
    insert_node(&head, 1);
    insert_node(&head, 3);
    insert_node(&head, 2);
    print_list(head);
    delete_node(&head, 1);
    print_list(head);
    return 0;
}
