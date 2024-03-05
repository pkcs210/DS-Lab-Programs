#include <stdio.h>
#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

int isFull() {
    if ((rear + 1) % SIZE == front)
        return 1;
    else
        return 0;
}

int isEmpty() {
    if (front == -1 && rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(int e) {
    if (isFull())
        printf("Queue is full\n");
    else {
        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % SIZE;
        items[rear] = e;
        printf("Inserted %d\n", e);
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    } else {
        int removed = items[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
        printf("Deleted: %d\n", removed);
        return removed;
    }
}

void display() {
    if (isEmpty())
        printf("Empty Queue\n");
    else {
        printf("Front: %d\n", front);
        printf("Items: ");
        int i;
        for (i = front; i != rear; i = (i + 1) % SIZE)
            printf("%d ", items[i]);
        printf("%d\n", items[i]);
        printf("Rear: %d\n", rear);
    }
}

int main() {
    dequeue();
    enqueue(5);
    enqueue(7);
    enqueue(10);
    display();
    dequeue();
    display();
    return 0;
}
