#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertToLeft(struct Node** head, struct Node* target, int value) {
    struct Node* newNode = createNode(value);
    
    if (target->prev != NULL) {
        target->prev->next = newNode;
        newNode->prev = target->prev;
    } else {
        *head = newNode;
    }

    newNode->next = target;
    target->prev = newNode;
}

void deleteNodeByValue(struct Node** head, int value) {
    struct Node* current = *head;
    
    while (current != NULL) {
        if (current->data == value) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                *head = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            free(current);
            return;
        }

        current = current->next;
    }

    printf("Node with value %d not found in the list.\n", value);
}

void displayList(struct Node* head) {
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    head = createNode(1);
    struct Node* second = createNode(2);
    struct Node* third = createNode(3);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    displayList(head);

    insertToLeft(&head, second, 5);
    displayList(head);

    deleteNodeByValue(&head, 2);
    displayList(head);

    return 0;
}
