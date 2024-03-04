#include <stdio.h>
#include <stdlib.h>

int stack[10];
int count = -1;

void push(int);
void pop();
void display();

int main() {
    for (;;) {
        printf("\n1. Push value to stack\n");
        printf("2. Pop value from stack\n");
        printf("3. Display values\n");
        printf("4. Exit\n\n");
        
        int t;
        printf("Enter your choice: ");
        scanf("%d", &t);
        printf("\n");

        if (t == 1) {
            int v;
            printf("Enter value to push: ");
            scanf("%d", &v);
            push(v);
        } 
        else if (t == 2) {
            pop();
            
        }
        else if (t == 3) {
            display();
        }
        else {
            exit(0);
        }
    }
}

void push(int e) {
    if (count < 10) {
        stack[++count] = e;
    } else {
        printf("Stack is full!\n");
    }
}

void pop() {
    if (count >= 0) {
        stack[count--] = 0;
    } else {
        printf("Stack is empty!\n");
    }
}

void display() {
    if (count == -1) 
        return;
    int i;
    printf("The values are (top to bottom):\n");
    for (int i = count; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
    printf("\n");
}
