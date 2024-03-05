#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct LinkedList* initializeList() {
    struct LinkedList* newList = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    newList->head = NULL;
    return newList;
}

void push(struct LinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = list->head;
    list->head = newNode;
}

int pop(struct LinkedList* list) {
    if (list->head == NULL) {
        printf("Stack/Queue is empty\n");
        return -1;
    }

    struct Node* temp = list->head;
    int poppedData = temp->data;
    list->head = temp->next;
    free(temp);
    return poppedData;
}

void enqueue(struct LinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    struct Node* lastNode = list->head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;
}

int dequeue(struct LinkedList* list) {
    return pop(list);
}

void display(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeList(struct LinkedList* list) {
    struct Node* current = list->head;
    struct Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    free(list);
}

int main() {
    struct LinkedList* linkedList = initializeList();

    push(linkedList, 1);
    push(linkedList, 2);
    push(linkedList, 3);
    printf("Stack: ");
    display(linkedList);
    printf("Popped from stack: %d\n", pop(linkedList));
    display(linkedList);

    enqueue(linkedList, 4);
    enqueue(linkedList, 5);
    enqueue(linkedList, 6);
    printf("\nQueue: ");
    display(linkedList);
    printf("Dequeued from queue: %d\n", dequeue(linkedList));
    display(linkedList);

    freeList(linkedList);

    return 0;
}
