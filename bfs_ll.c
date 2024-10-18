#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent the adjacency list
struct Graph {
    struct Node* array[MAX_VERTICES];
    int numVertices;
};

// Function to create a new graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->array[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = graph->array[src];
    graph->array[src] = newNode;

    // Add an edge from dest to src for undirected graph
    newNode = malloc(sizeof(struct Node));
    newNode->vertex = src;
    newNode->next = graph->array[dest];
    graph->array[dest] = newNode;
}

// BFS function
void BFS(struct Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0}; // Array to keep track of visited vertices
    int queue[MAX_VERTICES]; // Queue for BFS
    int front = 0, rear = 0;

    // Mark the starting vertex as visited and enqueue it
    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("BFS traversal starting from vertex %d:\n", startVertex);

    while (front < rear) {
        // Dequeue a vertex from the queue and print it
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Get all adjacent vertices of the dequeued vertex
        struct Node* temp = graph->array[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;

            // If the vertex is not visited, mark it visited and enqueue it
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// Function to free the graph memory
void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->array[i];
        while (temp) {
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph);
}

int main() {
    struct Graph* graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    BFS(graph, 0);

    freeGraph(graph);
    return 0;
}
