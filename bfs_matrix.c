#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Function to perform BFS on the graph
void BFS(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices, int startVertex) {
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

        // Explore all adjacent vertices
        for (int i = 0; i < numVertices; i++) {
            // If the vertex is adjacent and not visited
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1; // Mark it visited
                queue[rear++] = i; // Enqueue it
            }
        }
    }
    printf("\n");
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {0}; // Adjacency matrix
    int numVertices = 5;

    // Example: Create a graph with 5 vertices (0 to 4)
    // Add edges (undirected graph)
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[2][4] = 1;
    graph[3][4] = 1;

    // Perform BFS starting from vertex 0
    BFS(graph, numVertices, 0);

    return 0;
}
