#define MAX_SIZE 1000

typedef struct {
    int *stack;
    int *min_stack;
    int top;
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->stack = (int*)malloc(MAX_SIZE * sizeof(int));
    obj->min_stack = (int*)malloc(MAX_SIZE * sizeof(int));
    obj->top = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    if(obj->top == -1){
        obj->top++;
        obj->stack[obj->top] = val;
        obj->min_stack[obj->top] = val;
    } else if (obj->top < MAX_SIZE-1) {
        obj->top++;
        obj->stack[obj->top] = val;
        if(obj->min_stack[obj->top-1] < val)
            obj->min_stack[obj->top] = obj->min_stack[obj->top-1];
        else 
            obj->min_stack[obj->top] = val;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top == -1) return;
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->min_stack[obj->top];
}

void minStackFree(MinStack* obj) {
    free(obj->stack);
    free(obj->min_stack);
    free(obj);
}
