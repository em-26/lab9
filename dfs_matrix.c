#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Function to perform DFS on the graph
void DFS(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices, int vertex, int visited[]) {
    // Mark the current vertex as visited and print it
    visited[vertex] = 1;
    printf("%d ", vertex);

    // Explore all adjacent vertices
    for (int i = 0; i < numVertices; i++) {
        // If there's an edge and the vertex is not visited
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(graph, numVertices, i, visited); // Recur for adjacent vertex
        }
    }
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {0}; // Adjacency matrix
    int numVertices = 5;

    // Example: Create a graph with 5 vertices (0 to 4)
    // Add edges (undirected graph)
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][3] = 1;
    graph[1][4] = 1;
    graph[2][4] = 1;

    // Array to keep track of visited vertices
    int visited[MAX_VERTICES] = {0};

    // Perform DFS starting from vertex 0
    printf("DFS traversal starting from vertex 0:\n");
    DFS(graph, numVertices, 0, visited);
    printf("\n");

    return 0;
}
