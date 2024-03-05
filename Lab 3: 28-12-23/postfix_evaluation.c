#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 30

int stack[MAX_SIZE];
int top = -1;

void push(int item) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = item;
}

int pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int evaluate(char expression[]) {
    int i = 0;
    char symbol;
    int op1, op2, result;

    while ((symbol = expression[i++]) != '\0') {
        if (isdigit(symbol)) {
            push(symbol - '0');
        } else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') {
            op2 = pop();
            op1 = pop();
            switch (symbol) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
            }
            push(result);
        }
    }
    return pop();
}

int main() {
    char expression[] = "567+*8-";
    int result = evaluate(expression);
    printf("Result = %d\n", result);
    return 0;
}
