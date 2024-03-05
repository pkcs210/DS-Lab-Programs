#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sortList(struct Node* head) {
    struct Node *current, *nextNode;
    int temp;
    
    if (head == NULL) {
        return;
    }

    do {
        current = head;
        nextNode = current->next;

        while (nextNode != NULL) {
            if (current->data > nextNode->data) {
                temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
            }
            current = current->next;
            nextNode = nextNode->next;
        }
    } while (current->next != NULL);
}

struct Node* reverseList(struct Node* head) {
    struct Node *prev, *current, *nextNode;
    prev = NULL;
    current = head;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

void concatenateLists(struct Node* list1, struct Node* list2) {
    while (list1->next != NULL) {
        list1 = list1->next;
    }
    list1->next = list2;
}

int main() {
    struct Node* head1 = createNode(3);
    head1->next = createNode(1);
    head1->next->next = createNode(5);

    printf("Original Linked List 1: ");
    displayList(head1);

    sortList(head1);
    printf("Sorted Linked List 1: ");
    displayList(head1);

    head1 = reverseList(head1);
    printf("Reversed Linked List 1: ");
    displayList(head1);

    struct Node* head2 = createNode(2);
    head2->next = createNode(4);
    head2->next->next = createNode(6);

    printf("Original Linked List 2: ");
    displayList(head2);

    concatenateLists(head1, head2);
    printf("Concatenated Linked List: ");
    displayList(head1);

    return 0;
}
