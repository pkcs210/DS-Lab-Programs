#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

// Node structure for the binary tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new Node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to swap subtrees at a given depth
void swapSubtrees(Node* root, int k, int depth) {
    if (root == NULL)
        return;

    if (depth % k == 0) {
        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }

    swapSubtrees(root->left, k, depth + 1);
    swapSubtrees(root->right, k, depth + 1);
}

// Function to perform inorder traversal of the binary tree
void inorderTraversal(Node* root, int** result, int* index) {
    if (root == NULL)
        return;

    inorderTraversal(root->left, result, index);
    (*result)[(*index)++] = root->data;
    inorderTraversal(root->right, result, index);
}

// Function to swap nodes in a binary tree based on queries
int** swapNodes(int indexes_rows, int indexes_columns, int** indexes, int queries_count, int* queries, int* result_rows, int* result_columns) {
    // Build the binary tree
    Node* root = createNode(1);
    Node* queue[indexes_rows];
    int front = -1, rear = -1;
    queue[++rear] = root;

    for (int i = 0; i < indexes_rows; i++) {
        Node* curr = queue[++front];
        int leftData = indexes[i][0];
        int rightData = indexes[i][1];

        if (leftData != -1) {
            curr->left = createNode(leftData);
            queue[++rear] = curr->left;
        }
        if (rightData != -1) {
            curr->right = createNode(rightData);
            queue[++rear] = curr->right;
        }
    }

    // Perform swapping based on queries
    int** resultArray = (int**)malloc(queries_count * sizeof(int*));
    *result_rows = queries_count;
    *result_columns = indexes_rows;

    int resultIndex = 0;
    for (int i = 0; i < queries_count; i++) {
        int k = queries[i];
        swapSubtrees(root, k, 1);

        // Traverse the tree in inorder and store the result
        int* result = (int*)malloc(indexes_rows * sizeof(int));
        int index = 0;
        inorderTraversal(root, &result, &index);
        resultArray[resultIndex++] = result;
    }

    return resultArray;
}



int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    int** indexes = malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        *(indexes + i) = malloc(2 * (sizeof(int)));

        char** indexes_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < 2; j++) {
            int indexes_item = parse_int(*(indexes_item_temp + j));

            *(*(indexes + i) + j) = indexes_item;
        }
    }

    int queries_count = parse_int(ltrim(rtrim(readline())));

    int* queries = malloc(queries_count * sizeof(int));

    for (int i = 0; i < queries_count; i++) {
        int queries_item = parse_int(ltrim(rtrim(readline())));

        *(queries + i) = queries_item;
    }

    int result_rows;
    int result_columns;
    int** result = swapNodes(n, 2, indexes, queries_count, queries, &result_rows, &result_columns);

    for (int i = 0; i < result_rows; i++) {
        for (int j = 0; j < result_columns; j++) {
            fprintf(fptr, "%d", *(*(result + i) + j));

            if (j != result_columns - 1) {
                fprintf(fptr, " ");
            }
        }

        if (i != result_rows - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
