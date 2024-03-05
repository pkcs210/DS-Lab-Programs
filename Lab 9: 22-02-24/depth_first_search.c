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

void DFS(struct Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    struct Node* temp = graph->adjacency_list[vertex];
    while (temp) {
        int adj_vertex = temp->data;
        if (!visited[adj_vertex])
            DFS(graph, adj_vertex, visited);
        temp = temp->next;
    }
}

int isConnected(struct Graph* graph) {
    int visited[MAX_NODES] = {0};
    DFS(graph, 0, visited);

    for (int i = 0; i < graph->num_vertices; ++i) {
        if (!visited[i])
            return 0;
    }
    return 1;
}

int main() {
    struct Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 4);

    if (isConnected(graph))
        printf("The graph is connected.\n");
    else
        printf("The graph is not connected.\n");

    return 0;
}
