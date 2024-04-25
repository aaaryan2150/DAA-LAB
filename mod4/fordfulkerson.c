#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

#define V 6

bool bfs(int rGraph[V][V], int s, int t, int parent[]) {
    bool visited[V];
    memset(visited, 0, sizeof(visited));
    int queue[V];
    int front = 0, rear = 0;
    queue[rear++] = s;
    visited[s] = true;
    parent[s] = -1;
    while (front < rear) {
        int u = queue[front++];
        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return (visited[t] == true);
}

int fordFulkerson(int graph[V][V], int s, int t) {
    int rGraph[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            rGraph[i][j] = graph[i][j];
    int parent[V];
    int max_flow = 0;
    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            
            if (path_flow < rGraph[u][v]) {
                path_flow = path_flow;
            } else {
                path_flow = rGraph[u][v];
            }
        }
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main() {
    int graph[V][V] = { {0, 8, 0, 0, 3, 0},
                        {0, 0, 9, 0, 0, 0},
                        {0, 0, 0, 0, 7, 2},
                        {0, 0, 0, 0, 0, 5},
                        {0, 0, 0, 6, 0, 4},
                        {0, 0, 0, 0, 0, 0} };
    int source = 0, sink = 5;
    printf("The maximum possible flow is %d\n", fordFulkerson(graph, source, sink));
    return 0;
}
