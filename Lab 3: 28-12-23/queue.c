 c#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

int items[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int value);
void dequeue();
void display();

int main() {
    dequeue();
    enqueue(1);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    display();
    dequeue();
    display();
    return 0;
}

void enqueue(int value) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full\n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        items[rear] = value;
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Deleted: %d\n", items[front]);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }
}

void display() {
    if (rear == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", items[i]);
        }
        printf("\n");
    }
}
