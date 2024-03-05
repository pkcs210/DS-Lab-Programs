#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int num_vertices;
    struct Node* adjacency_list[MAX_NODES];
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int num_vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->num_vertices = num_vertices;

    for (int i = 0; i < num_vertices; ++i)
        graph->adjacency_list[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacency_list[src];
    graph->adjacency_list[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjacency_list[dest];
    graph->adjacency_list[dest] = newNode;
}

void BFS(struct Graph* graph, int start) {
    int visited[MAX_NODES] = {0};
    int queue[MAX_NODES];
    int front = -1, rear = -1;

    queue[++rear] = start;
    visited[start] = 1;

    while (front < rear) {
        int current = queue[++front];
        printf("%d ", current);

        struct Node* temp = graph->adjacency_list[current];
        while (temp) {
            int adj_vertex = temp->data;
            if (!visited[adj_vertex]) {
                queue[++rear] = adj_vertex;
                visited[adj_vertex] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    struct Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    printf("BFS traversal starting from vertex 2: ");
    BFS(graph, 2);

    return 0;
}
