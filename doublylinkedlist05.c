#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Function to display the doubly linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <--> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete the first node
void delete_begin(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is Empty, cannot delete\n");
        return;
    }

    struct Node* temp = *head_ref;
    *head_ref = temp->next;

    if (*head_ref != NULL)
        (*head_ref)->prev = NULL;

    free(temp);  // Free memory of the deleted node
}

int main() {
    // Create initial list manually
    struct Node* head = create_node(10);
    struct Node* n1 = create_node(20);
    struct Node* n2 = create_node(30);
    struct Node* n3 = create_node(40);

    // Link the nodes
    head->next = n1;
    n1->prev = head;
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;

    printf("Initial Doubly Linked List:\n");
    display(head);

    printf("\nDeleting the first node...\n\n");
    delete_begin(&head);

    printf("After Deletion:\n");
    display(head);

    return 0;
}
